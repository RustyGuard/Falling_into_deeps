local function fn(entity)
	local inst = {}
	function inst:Init(p, f, i, s)
		self.dmg = {p, f, i, s}
	end
	function inst:GetDamage()
		return self.dmg
	end
	function inst:DebugInfo()
		print("Weapon: (", self.dmg[1], self.dmg[2], self.dmg[3], self.dmg[4], ")")
	end

	return inst
end

return Prefab("weapon", fn)