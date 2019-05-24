local inst = {}

inst.texture = CreateTexture("res/textures/items/food_bowl.png")

function inst:OnMouseButtonReleased(stack, button, p)
	if button == 0 then
		print("I eat it!")
		stack:Reduce(1)
		return true
	end
	return false
end

return inst