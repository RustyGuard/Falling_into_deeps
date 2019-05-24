local function commonfn(inv, slot, name)
	local inst = CreateEntity()
	inst.inv = inv
	inst.slot = slot
	inst.name = "copper_"..name
	function inst:to_string()
		return self.name
	end
	return inst
end

local function chestplate(inv, slot)
	local inst = commonfn(inv, slot, "chestplate")
	inst:AddComponent("armor"):Init(5, 2, 0, -2)
	return inst
end

local function boots(inv, slot)
	local inst = commonfn(inv, slot, "boots")
	inst:AddComponent("armor"):Init(5, 2, 0, -2)
	return inst
end

local function helmet(inv, slot)
	local inst = commonfn(inv, slot, "helmet")
	inst:AddComponent("armor"):Init(5, 2, 0, -2)
	return inst
end

return {Prefab("copper_chestplate", chestplate), Prefab("copper_boots", boots), Prefab("copper_helmet", helmet)}