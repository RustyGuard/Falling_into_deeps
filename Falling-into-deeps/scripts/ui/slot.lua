local function create()
	local inst = {}
	inst.transform = CreateComponent("transform")
	inst.transform:SetDrawable()
	inst.transform.tex_half.x = 32
	inst.transform.tex_half.y = 32
	inst.tex = CreateTexture("res/textures/test6.png")
	function inst:Init(inv, slot)
		self.inventory = inv
		self.slot = slot
	end
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
			self.inventory:ChangeWithCursor(self.slot)
			print(self.inventory:GetAmount(self.slot))
		end
	end
	function inst:render()
		inst.transform:DrawUI(self.tex, 1, 1)
		if not self.inventory:IsEmpty(self.slot) then
			inst.transform:DrawUI(self.inventory:GetItem(self.slot).texture, 1, 1)
		end
	end
	return inst
end

return create