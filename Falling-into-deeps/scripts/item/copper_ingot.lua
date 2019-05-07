local inst = {}

inst.texture = CreateTexture("res/textures/test.png")

function inst:OnMouseButtonReleased(stack, b, p)
	return false
end

return inst