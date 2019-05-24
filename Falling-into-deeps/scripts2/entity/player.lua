local function create()
	local en = CreateEntity()

	--en.transform = CreateComponent("transform")
	local transform = en:AddComponent("transform")
	--inventory = CreateComponent("inventory")
	local inventory = en:AddComponent("inventory")
	--en.animation = CreateComponent("animation")
	--local animation = en:AddComponent("animation")
	--en.components.health = CreateComponent("health")

	transform:CreateEntityCapability()

	local anim1 = en:AddAnimation("idle", "cycle")
	anim1:Init("res/textures/player/idle", 0.5, 4)
	local anim1 = en:AddAnimation("left", "cycle")
	anim1:Init("res/textures/player/left", 0.5, 4)
	local anim1 = en:AddAnimation("right", "cycle")
	anim1:Init("res/textures/player/right", 0.5, 4)
	local anim1 = en:AddAnimation("up", "cycle")
	anim1:Init("res/textures/player/up", 0.5, 4)
	local anim1 = en:AddAnimation("down", "cycle")
	anim1:Init("res/textures/player/down", 0.5, 4)

	en:UseAnimation("idle")

	en.name = "player"
	--ChangeId(en.id, "player")

	function en:OnUpdate(delta)
		local x = 0
		local y = 0
		if GetKey("a") then
			x = x - 1.5
		end
		if GetKey("d") then
			x = x + 1.5
		end
		if GetKey("w") then
			y = y - 1.5
		end
		if GetKey("s") then
			y = y + 1.5
		end
		self.components.transform:move(x, y)
		if x < 0 then
			self:UseAnimation("left")
		elseif x  > 0 then
			self:UseAnimation("right")
		else
			if y < 0 then
				self:UseAnimation("up")
			elseif y  > 0 then
				self:UseAnimation("down")
			else
				self:UseAnimation("idle")
			end
		end
		
		--self.components.animation:update(delta)
		--if (isPressed("f")) then
			--if self.components.health:damage(1) then
				--DeleteEntity(en.id)
			--end
		--end
		--if (isPressed("h")) then
			--self.components.health:heal(1)
		--end
	end

	function en:attack(dmg)
		print("Ouch: " .. dmg .. "!")
	end

	local inv = CreateUIItem("container")
	for i = 1, 3 do
		--inventory:AddSlot(i)
		inventory:SetItem(1, "food_bowl")
		--inventory:SetAmount(i, i)
		local b = CreateUIItem("slot")
		b:SetLocation(- (i * 50) - 75, -300)
		b:SetSize(24, 24)
		b:Init(inventory, i)
		inv:AddItem(b)
	end
	SetContainer("p_inventory", inv)
	return en
end

return create