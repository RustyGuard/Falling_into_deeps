local function fn(entity)
	local inst = {}
	function inst:Init(p, f, i, s)
		self.dfn = {p, f, i, s}
	end
	function inst:GetDefence(type)
		return self.dfn[type]
	end
	function inst:DebugInfo()
		print("Armor: (", self.dfn[1], self.dfn[2], self.dfn[3], self.dfn[4], ")")
	end

	return inst
end

return Prefab("armor", fn)