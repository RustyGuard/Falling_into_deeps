local function create()
	local inst = {}

	inst.ui = {}

	function inst:AddItem(item)
		self.ui[#self.ui + 1] = item
	end

	function inst:update(m_pos)
		for id, item in pairs(self.ui) do
			item:update(m_pos)
		end
	end

	function inst:render()
		for id, item in pairs(self.ui) do
			item:render()
		end
	end

	return inst
end

return create