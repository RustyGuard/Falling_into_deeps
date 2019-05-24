local function create()
	local inst = {}

	inst.ui = {}

	function inst:AddItem(item)
		self.ui[#self.ui + 1] = item
	end

	function inst:update(m_pos)
		for id, item in pairs(self.ui) do
			if item.update then
				item:update(m_pos)
			end
		end
	end

	function inst:render()
		for id, item in pairs(self.ui) do
			item:render()
		end
	end
	function inst:OnMouseButtonReleased(button, pos)
		for id, item in pairs(self.ui) do
			if item.OnMouseButtonReleased then
				if item:OnMouseButtonReleased(button, pos) then
					return true
				end
			end
		end
		return false
	end

	return inst
end

return create