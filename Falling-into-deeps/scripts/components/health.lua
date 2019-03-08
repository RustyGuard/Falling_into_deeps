local function create()
	local inst = {}
	inst.max_health = 150
	inst.health = inst.max_health
	function inst:heal(hp)
		self.health = math.min(self.max_health, self.health + hp)
		print("Health: " .. self.health)
	end
	function inst:damage(dmg)
		self.health = math.max(0, self.health - dmg)
		print("Health: " .. self.health)
		if self.health == 0 then return true end
		return false
	end
	return inst
end

return create