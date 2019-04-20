local function create()
	local inst = {}
	inst.transform = CreateComponent("transform")
	inst.transform:SetDrawable()
	inst.transform.tex_half.x = 32
	inst.transform.tex_half.y = 32
	inst.transform.pos.z = 0.25
	inst.tex1 = CreateTexture("res/textures/test2.png")
	inst.tex2 = CreateTexture("res/textures/test3.png")
	inst.maximum = 1500
	inst.minimum = 75
	function inst:SetLocation(x, y)
		self.transform.pos.x = x
		self.transform.pos.y = y
	end
	function inst:SetSize(w, h)
		self.transform.tex_half.x = w
		self.transform.tex_half.y = h
	end
	function inst:SetCallback(f)
		self.callback = f
	end
	function inst:update(a)
		if GetMouseButton(0) == GLFW_PRESS and self.transform:IsInside(a) then
			self.transform.pos.z = 0.75
			if self.callback then
				self.callback()
			end
		end
	end
	function inst:render()
		self.minimum = self.minimum + 1.0
		inst.transform:DrawUI(self.tex2, 1, 1)
		local x_v = self.maximum / self.minimum
		inst.transform:DrawUI(self.tex1, x_v, 1)
	end
	return inst
end

return create