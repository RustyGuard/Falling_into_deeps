local function CalcDamage(entity)
	if entity.components.inventory then
		local item = entity.components.inventory:GetArmSlot()
		if item and item.components.weapon then
			return item.components.weapon:GetDamage()
		end
	end
	return entity.components.combat:GetBaseDamage()
end

local function Punch(entity, aim)
	local dmg = CalcDamage(entity)
	local res = 0
	local inv = aim.components.inventory
	for type, d in ipairs(dmg) do
		if inv and d ~= 0 then
			res = res + math.max(1, d - inv:GetDefence(type))
		end
	end
	aim:PushEvent("DoDelta", -res)
end

local function fn(entity)
	local inst = {}
	entity:AddListener("Punch", Punch)
	function inst:GetBaseDamage() return self.base_dmg or {1, 0, 0, 0} end
	function inst:DebugInfo()
		print("Combat")
	end
	return inst
end

return Prefab("combat", fn)