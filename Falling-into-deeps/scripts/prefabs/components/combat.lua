local function Punch(entity, aim)
	if entity.components.inventory then
		aim:PushEvent("OnAttack", entity, entity.components.inventory:GetArmSlot())
	end
end

local function fn(entity)
	local inst = {}
	entity:AddListener("Punch", Punch)
	return inst
end

return Prefab("combat", fn)