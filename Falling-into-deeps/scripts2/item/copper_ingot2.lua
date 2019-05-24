local inst = {}

inst.texture = CreateTexture("res/textures/test.png")

function inst:OnMouseButtonReleased(stack, b, p)
	return PlaceTile(p, "chest")
end

return inst