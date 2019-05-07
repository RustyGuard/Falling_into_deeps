local function create()
	local inst = {}
	inst.animations = {}
	inst.curr = 0
	
	function inst:AddAnimation(id, type)
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

	function inst:OnUpdate(en, delta)
		if self.curr == 0 then return end
		if self.animations[self.curr].OnUpdate then
			self.animations[self.curr]:OnUpdate(delta)
		end
		return false
	end

	function inst:GetImage()
		if self.curr == 0 then return 0 end
		return self.animations[self.curr]:GetImage()
	end

	function inst:Use(id)
		self.curr = id
	end

	function inst:Get(id)
		return self.animations[id]
	end
	return inst
end

return create