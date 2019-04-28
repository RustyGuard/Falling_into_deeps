local function create()
	local inst = {}
	inst.animations = {}
	inst.curr = 0
	
	function inst:AddAnimation(id, type)
		local i = {}
		if type == "static" then
			function i:SetImage(name)
				self.texture = CreateTexture(name)
			end
			function i:GetImage()
				return self.texture
			end
		end
		self.animations[id] = i
		return i
	end

	function inst:update(delta)
		if self.curr == 0 then return end
		if self.animations[self.curr].update then
			self.animations[self.curr]:update(delta)
		end
	end

	function inst:GetImage()
		if self.curr == 0 then return 0 end
		return self.animations[self.curr]:GetImage()
	end

	function inst:Use(id)
		self.curr = id
	end

	return inst
end

return create