local inst = {}

inst.entity_func = {}
inst.entities = {}
inst.pos = vec3()
inst.pos.x = 0
inst.pos.y = 0

function CreateEntity()
	local en = {}
	en.tags = {}
	function en:AddTag(tag)
		table.insert(self.tags, tag)
	end
	function en:HasTag(tag)
		for _, i in ipairs() do
			if i == tag then return true end
		end
		return false
	end
	en.components = {}
	function en:AddComponent(name)
		local c = CreateComponent(name)
		self.components[name] = c
		return c
	end
	-------------------------------------------------------------
	en.animations = {}
	en.curr = 0
	
	function en:AddAnimation(id, type)
		local i = {}
		if type == "static" then
			function i:Init(name)
				self.texture = CreateTexture(name)
			end
			function i:GetImage()
				return self.texture
			end
		elseif type == "cycle" then
			function i:Init(name, duration, range)
				self.duration = duration
				self.time = 0
				self.range = range
				self.current = 1
				self.textures = {}
				self.reversed = false
				for i = 1, range do
					self.textures[i] = CreateTexture(name .. i .. ".png")
				end
			end
			function i:OnUpdate(delta)
				self.time = self.time + delta
				if self.time >= self.duration then
					self.time = self.time - self.duration
					self.current = self.current + 1
					if self.current > self.range then
						self.current = 1
					end
				end
			end
			function i:Reverse() 
				self.reversed = not self.reversed
			end
			function i:SetReversed(r) 
				self.reversed = r
			end
			function i:Min()
				self.current = 1
			end
			function i:Max()
				self.current = self.range
			end
			function i:GetImage()
				if self.reversed then
					return self.textures[self.range - self.current + 1]
				end
				return self.textures[self.current]
			end
		elseif type == "over" then
			function i:Init(name, duration, range)
				self.duration = duration
				self.time = 0
				self.range = range
				self.current = 1
				self.textures = {}
				for i = 1, range do
					self.textures[i] = CreateTexture(name .. i .. ".png")
				end
			end
			function i:OnUpdate(delta)
				if self.current < self.range then
					self.time = self.time + delta
					if self.time >= self.duration then
						self.time = self.time - self.duration
						self.current = self.current + 1
					end
				end
			end
			function i:Reverse() 
				self.reversed = not self.reversed
			end
			function i:SetReversed(r) 
				self.reversed = r
			end
			function i:Min()
				self.current = 1
			end
			function i:Max()
				self.current = self.range
			end
			function i:GetImage()
				if self.reversed then
					return self.textures[self.range - self.current + 1]
				end
				return self.textures[self.current]
			end
		end
		self.animations[id] = i
		return i
	end

	function en:GetImage()
		if self.curr == 0 then return 0 end
		return self.animations[self.curr]:GetImage()
	end

	function en:UseAnimation(id)
		self.curr = id
	end

	function en:GetAnimation(id)
		return self.animations[id]
	end
	------------------------------------------------------------------

	function en:PushEvent(type, ...)
		if type == "OnUpdate" and self.curr ~= 0 and self.animations[self.curr].OnUpdate then
			self.animations[self.curr].OnUpdate(self.animations[self.curr], ...)
		end
		for _, i in pairs(self.components) do
			if i[type] and i[type](i, self, ...) then
				return true
			end
		end
		if self[type] then
			return self[type](self, ...)
		end
		return false
	end

	--[[local id = #inst.entities + 1
	en.id = id
	inst.entities[id] = en]]
	return en
end

function ChangeId(last, new)
	if inst.entities[new] then
		print("This id is already taken.")
		return
	end
	local en = inst.entities[last]
	inst.entities[last] = nil
	inst.entities[new] = en
	en.id = new
end

function AddEntity(name)
	if not inst.entity_func[name] then
		inst.entity_func[name] = require("scripts/entity/" .. name)
	end
	local en = inst.entity_func[name]()
	local id = #inst.entities + 1
	en.id = id
	inst.entities[id] = en
	return en
end

function AppendEntity(en)
	local id = #inst.entities + 1
	en.id = id
	inst.entities[id] = en
	return en
end


function inst:OnRender()
	for _, en in pairs(self.entities) do
		en:PushEvent("OnRender")
	end
	return false
end

function inst:PushEvent(type, ...)
	if self[type] then
		return self[type](self, ...)
	end
	return false
end

function GetByPoint(p)
	for _, en in pairs(inst.entities) do
		if en.components.transform and en.components.transform:IsInside(p) then
			return en
		end
	end
	return nil
end

function inst:OnMouseButtonReleased(button)
	--[[local i = self.entities.player.components.inventory:GetItemStack(1)
	if (not i:IsEmpty()) and i:GetItem():OnMouseButtonReleased(i, button, self.pos) then
		return true
	end]]
	for _, en in pairs(self.entities) do
		if en.components.transform and en.components.transform:IsInside(self.pos) then
			if en.OnMouseButtonReleased and en:OnMouseButtonReleased(button) then
				return true
			end
		end
	end
	return false
	--print("Taken: " .. tostring(b) .. " " .. tostring(p))
end

function inst:OnUpdate(delta)
	self.pos.x = GetMouseX() - GetCameraX()
	self.pos.y = GetMouseY() - GetCameraY()
	self.entities.player.components.transform:CorrectCamera()
	for id, en in pairs(self.entities) do
		en:PushEvent("OnUpdate", delta)

		if en.components.transform.collidable and en.components.transform.moved then
			for i, e in pairs(self.entities) do
				if e ~= en then
					if e.components.transform.static then
						en.components.transform:Correct(e.components.transform)
					else
						if e.components.transform:Correct(en.components.transform) then
							for ide, ene in pairs(self.entities) do
								if ene ~= e then
									if e.components.transform:Correct(ene.components.transform) then
										en.components.transform:Correct(e.components.transform)
									end
								end
							end
						end
					end
				end
			end
			en.components.transform.moved = false
		end
	end
	return false
end

return inst