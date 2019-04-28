local function create()
	local inst = {}
	inst.items = {}
	function inst:AddSlot(slot)
		self.items[slot] = {}
		self.items[slot].id = 0
		self.items[slot].amount = 0
	end
	function inst:SetItem(slot, item)
		self.items[slot].id = item
	end
	function inst:ChangeWithCursor(slot)
		if MOUSE_SLOT.item == self.items[slot].id then
			self.items[slot].amount = self.items[slot].amount + MOUSE_SLOT.amount

			MOUSE_SLOT.item = 0
			MOUSE_SLOT.amount = 0

			return
		end
		MOUSE_SLOT.item, self.items[slot].id = self.items[slot].id, MOUSE_SLOT.item
		MOUSE_SLOT.amount, self.items[slot].amount = self.items[slot].amount, MOUSE_SLOT.amount
	end
	function inst:PutIn(inventory)
		-- Coming soon
	end
	function inst:GetItem(slot)
		return ITEMS[self.items[slot].id]
	end
	function inst:IsEmpty(slot)
		if self.items[slot].amount == 0 then
			self.items[slot].id = 0
			return true
		end
		return self.items[slot].id == 0 
	end
	function inst:GetAmount(slot)
		return self.items[slot].amount
	end
	function inst:SetAmount(slot, a)
		self.items[slot].amount = a
	end
	
	return inst
end

return create