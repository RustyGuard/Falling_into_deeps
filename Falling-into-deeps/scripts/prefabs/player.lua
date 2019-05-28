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
		if x < 0 then
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
		end
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

	local anim1 = inst:AddAnimation("idle", "cycle")
	anim1:Init("res/textures/player/idle", 0.5, 4)
	local anim2 = inst:AddAnimation("left", "cycle")
	anim2:Init("res/textures/player/left", 0.5, 4)
	local anim3 = inst:AddAnimation("right", "cycle")
	anim3:Init("res/textures/player/right", 0.5, 4)
	local anim4 = inst:AddAnimation("up", "cycle")
	anim4:Init("res/textures/player/up", 0.5, 4)
	local anim5 = inst:AddAnimation("down", "cycle")
	anim5:Init("res/textures/player/down", 0.5, 4)

	inst:UseAnimation("idle")

	inst:AddListener("OnUpdate", OnUpdate)
	return inst
end
return Prefab("player", fn)