local function fn(entity)
	local inst = {}
	function inst:Init(p, f, i, s)
		self.physic_dfn = p
		self.fire_dfn = f
		self.ice_dfn = i
		self.shock_dfn = s
	end
	function inst:GetPhysicDefence()
		return self.physic_dfn
	end
	function inst:GetFireDefence()
		return self.fire_dfn
	end
	function inst:GetIceDefence()
		return self.ice_dfn
	end
	function inst:GetShockDefence()
		return self.shock_dfn
	end
	function inst:to_string()
		return self.physic_dfn .. ", " .. self.fire_dfn .. ", " .. self.ice_dfn .. ", " .. self.shock_dfn
	end
	return inst
end

return Prefab("armor", fn)