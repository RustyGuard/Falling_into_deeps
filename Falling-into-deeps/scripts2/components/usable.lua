local function create()
	local inst = {}
	function inst:OnItemUse()
		print("Used!")
	end
	return inst
end

return create