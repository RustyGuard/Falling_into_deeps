local function create()
	local inst = {}
	inst.transform = CreateComponent("transform")
	inst.transform:SetDrawable()
	inst.transform.tex_half.x = 32
	inst.transform.tex_half.y = 32
	function inst:update(a)
		if IsButtonPressed(0) and self.transform:IsInside(a) then
			print("Button Pressed")
		end
	end
	function inst:render()
		BindTexture(0, 0)
		inst.transform:Draw()
	end
	return inst
end

return create