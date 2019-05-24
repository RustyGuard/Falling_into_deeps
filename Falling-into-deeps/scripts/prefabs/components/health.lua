local function OnAttack(entity, attacker, weapon)
	comp = entity.components.health
	print("Current: "..comp.health)
	comp.health = comp.health - math.max(weapon.components.weapon:GetPhysicDamage() - entity.components.inventory:GetPhysicDefence(), 1)
	print("After physic: "..comp.health)
	comp.health = comp.health - math.max(weapon.components.weapon:GetFireDamage() - entity.components.inventory:GetFireDefence(), 1)
	print("After fire: "..comp.health)
	comp.health = comp.health - math.max(weapon.components.weapon:GetIceDamage() - entity.components.inventory:GetIceDefence(), 1)
	print("After ice: "..comp.health)
	comp.health = comp.health - math.max(weapon.components.weapon:GetShockDamage() - entity.components.inventory:GetShockDefence(), 1)
	print("After shock: "..comp.health)

	if comp.health <= 0 then
		entity:PushEvent("OnDead", attacker, weapon)
		RemoveEntity(entity)
	end
end

local function fn(entity)
	local inst = {}
	
	function inst:SetMaxHealth(v)
		self.maxhealth = v
		self.health = v
	end

	inst:SetMaxHealth(100)

	entity:AddListener("OnAttack", OnAttack)

	return inst
end

return Prefab("health", fn)