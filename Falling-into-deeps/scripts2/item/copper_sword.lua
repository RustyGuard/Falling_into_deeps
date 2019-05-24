local function create(inv, slot)
	local inst = CreateEntity()
	inst.inv = inv
	inst.slot = slot
	inst:AddComponent("usable")
	inst:AddAnimation(1, "static"):Init("res/textures/items/copper_sword.png")
	inst:UseAnimation(1)
	return inst
end
return create