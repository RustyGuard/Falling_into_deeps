local function fn()
	local inst = CreateEntity()
	inst:AddTag("building")
	function inst:to_string()
		return "chest"
	end
	return inst
end

return Prefab("chest", fn)