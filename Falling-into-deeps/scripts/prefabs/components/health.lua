local function DoDelta(entity, v)
	local comp = entity.components.health
	comp.health = math.min(math.max(comp.health + v, 0), comp.maxhealth)
	if comp.health == 0 then
		entity:PushEvent("OnDead")
		RemoveEntity(entity)
	end
end

local function fn(entity)
	local inst = {}
	
	function inst:SetMaxHealth(v)
		self.maxhealth = v
		self.health = v
	end

	function inst:DoDelta(v)
		self.health = math.min(math.max(self.health + v, 0), self.maxhealth)
		print(self.health)
	end

	inst:SetMaxHealth(100)

	entity:AddListener("DoDelta", DoDelta)

	function inst:DebugInfo()
		print("Health: (Current: " .. self.health .. "Max: ".. self.maxhealth ..")")
	end

	return inst
end

return Prefab("health", fn)