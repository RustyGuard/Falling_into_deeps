require "scripts/class"

function CreateEntity()
	local en = {}
	en.tags = {}
	-------------------------------------------
	function en:AddTag(tag)
		table.insert(self.tags, tag)
	end
	function en:HasTag(tag)
		for _, i in ipairs(self.tags) do
			if i == tag then return true end
		end
		return false
	end
	------------------------------------------
	en.components = {}
	function en:AddComponent(name)
		local c = FindPrefab(name):Create(self)
		self.components[name] = c
		return c
	end
	------------------------------------------
	en.listeners = {}
	function en:AddListener(type, fn)
		if not self.listeners[type] then self.listeners[type] = {} end
		self.listeners[type][fn] = true
	end
	function en:RemoveListener(type, fn)
		self.listeners[type][fn] = nil
	end
	function en:PushEvent(type, ...)
		if self.listeners[type] then
			for i, v in pairs(self.listeners[type]) do
				if v then i(self, ...) end
			end
		end
	end
	-----------------------------------------
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
			function OnUpdate(delta) end
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

	function en:UpdateAnimation(delta)
		if self.curr ~= 0 then
			self.animations[self.curr]:OnUpdate(delta)	
		end
	end
	--------------------------------------------------------
	en:AddListener("OnUpdate", function(entity, d) entity:UpdateAnimation(d) end)

	function en:DebugInfo()
		print("------------------------------------")
		print("Tags:")
		for _, i in ipairs(self.tags) do
			print(i)
		end
		print("Components:")
		for _, i in pairs(self.components) do
			i:DebugInfo()
			print("---------------------")
		end
	end
	return en
end

require "scripts/prefab"

local entity_renderer = require "scripts/entity_renderer"
local tile_renderer = require "scripts/tile_renderer"
local ui_renderer = require "scripts/ui_renderer"

dummy = AddEntity("dummy")
player = AddEntity("player")

require "scripts/widgets/bar"
local b = Bar(dummy)
b:setLocation(512, -256)
AddWidget(b)
require "scripts/widgets/button"
local button = Button()
button:setLocation(-128, -128)
local function callback(b, button)
	print("Call!")
end
button:addListener("OnMouseButtonReleased", function(b, button)	print("Call!") end)
AddWidget(button)

player:PushEvent("Punch", dummy)

function PushEvent(type, ...)
	if type == "OnMouseButtonReleased" then
		player:PushEvent("Punch", dummy)
	end
	local b = tile_renderer:PushEvent(type, ...) or ui_renderer:PushEvent(type, ...) or entity_renderer:PushEvent(type, ...)
end
