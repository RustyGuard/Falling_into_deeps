local function fn(inv, slot)
	local inst = CreateEntity()
	inst.inv = inv
	inst.slot = slot
	inst.name = "food_bowl"
	function inst:to_string()
		return "food_bowl"
	end
	return inst
end

return Prefab("food_bowl", fn)