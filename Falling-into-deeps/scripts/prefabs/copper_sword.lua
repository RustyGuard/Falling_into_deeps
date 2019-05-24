local function fn(inv, slot)
	local inst = CreateEntity()
	inst.inv = inv
	inst.slot = slot
	inst.name = "copper_sword"
	inst:AddComponent("weapon"):Init(3, 3, 3, 3)
	function inst:to_string()
		return self.components.weapon:to_string() .. " copper_sword"
	end
	return inst
end
return Prefab("copper_sword", fn)