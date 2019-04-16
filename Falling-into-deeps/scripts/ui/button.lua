local function create()
	local inst = {}
	inst.transform = CreateComponent("transform")
	inst.transform:SetDrawable()
	inst.transform.tex_half.x = 32
	inst.transform.tex_half.y = 32
	inst.transform.pos.z = 0.25
	inst.tex = CreateTexture("res/textures/test.png")
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
			--print("Button Pressed")
			self.transform.pos.z = 0.75
			if self.callback then
				self.callback()
			end
		end
	end
	function inst:render()
		BindTexture(self.tex, 0)
		inst.transform:Draw()
	end
	return inst
end

return create