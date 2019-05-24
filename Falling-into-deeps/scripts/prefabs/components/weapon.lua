local function fn(entity)
	local inst = {}
	function inst:Init(p, f, i, s)
		self.physic_dmg = p
		self.fire_dmg = f
		self.ice_dmg = i
		self.shock_dmg = s
	end
	function inst:GetPhysicDamage()
		return self.physic_dmg
	end
	function inst:GetFireDamage()
		return self.fire_dmg
	end
	function inst:GetIceDamage()
		return self.ice_dmg
	end
	function inst:GetShockDamage()
		return self.shock_dmg
	end
	function inst:to_string()
		return self.physic_dmg .. ", " .. self.fire_dmg .. ", " .. self.ice_dmg .. ", " .. self.shock_dmg
	end
	return inst
end

return Prefab("weapon", fn)