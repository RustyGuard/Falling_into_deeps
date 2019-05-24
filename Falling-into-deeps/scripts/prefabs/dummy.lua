local function fn()
	local inst = CreateEntity()
	inst:AddTag("player")
	--inst:AddComponent("transform")
	inst:AddComponent("health")
	inst:AddComponent("combat")
	local inv = inst:AddComponent("inventory")
	inv:SetItem(1, "food_bowl")
	inv:SetItem("arm", "copper_sword")
	inv:SetItem("chestplate", "copper_chestplate")
	inv:SetItem("boots", "copper_boots")
	inv:SetItem("helmet", "copper_helmet")
	function inst:to_string()
		return "dummy // Health: " .. self.components.health.health
	end
	return inst
end
return Prefab("dummy", fn)