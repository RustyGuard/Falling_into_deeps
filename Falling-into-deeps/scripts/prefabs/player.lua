local function OnUpdate(entity)
	local x = 0
		local y = 0
		if GetKey("a") then
			x = x - 1
		end
		if GetKey("d") then
			x = x + 1
		end
		if GetKey("w") then
			y = y - 1
		end
		if GetKey("s") then
			y = y + 1
		end
		entity.components.transform:Move(x, y)
		--[[if x < 0 then
			entity:UseAnimation("left")
		elseif x  > 0 then
			entity:UseAnimation("right")
		else
			if y < 0 then
				entity:UseAnimation("up")
			elseif y  > 0 then
				entity:UseAnimation("down")
			else
				entity:UseAnimation("idle")
			end
		end]]
end

local function fn()
	local inst = CreateEntity()
	inst:AddTag("player")
	inst:AddComponent("transform")
	inst:AddComponent("health")
	inst:AddComponent("combat")
	local inv = inst:AddComponent("inventory")
	inv:SetItem(1, "food_bowl")
	inv:SetItem("arm", "copper_sword")
	inst:AddListener("OnUpdate", OnUpdate)
	function inst:to_string()
		return "player // Health: " .. self.components.health.health
	end
	return inst
end
return Prefab("player", fn)