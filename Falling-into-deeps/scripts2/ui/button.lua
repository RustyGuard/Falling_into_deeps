local function create()
	local inst = {}
	inst.transform = CreateComponent("transform")
	inst.transform:CreateUICapability()
	inst.transform.tex_half.x = 32
	inst.transform.tex_half.y = 32
	inst.tex = CreateTexture("res/textures/test6.png")
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
	function OnMouseButtonReleased(b, p)
		if b == 0 and self.transform:IsInside(p) then
			if self.callback then
				self.callback()
			end
			return true
		end
		return false
	end
	function inst:render()
		inst.transform:DrawUI(self.tex, 1, 1)
	end
	return inst
end

return create