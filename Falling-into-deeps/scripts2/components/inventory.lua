local function create()
	local inst = {}
	inst.items = {}
	function inst:GetItem(slot)
		return self.items[slot]
	end
	function inst:RemoveItem(slot)
		self.items[slot] = nil
	end
	function inst:SetItem(slot, name)
		self.items[slot] = CreateItem(self, slot, name)
	end
	function inst:IsEmpty(slot)
		return not self.items[slot]
	end
	function inst:ChangeWithCursor(slot)
		MOUSE_SLOT.items[1], self.items[slot] = self.items[slot], MOUSE_SLOT.items[1]
		--[[if MOUSE_SLOT.item == self.items[slot].id then
			self.items[slot].amount = self.items[slot].amount + MOUSE_SLOT.amount

			MOUSE_SLOT.item = 0
			MOUSE_SLOT.amount = 0

			return
		end
		MOUSE_SLOT.item, self.items[slot].id = self.items[slot].id, MOUSE_SLOT.item
		MOUSE_SLOT.amount, self.items[slot].amount = self.items[slot].amount, MOUSE_SLOT.amount]]
	end
	--[[local inst = {}
	inst.items = {}
	function inst:AddSlot(slot)
		local i = {}
		i.id = 0
		i.amount = 0
		function i:Reduce(amount)
			self.amount = self.amount - amount
			if self.amount <= 0 then
				self.id = 0
				self.amount = 0
			end
			print(self.amount)
		end
		function i:GetItem()
			return ITEMS[self.id]
		end
		function i:IsEmpty()
			return self.id == 0
		end
		self.items[slot] = i
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
	function inst:GetItemStack(slot)
		return self.items[slot]
	end
	function inst:IsEmpty(slot)
		if self.items[slot].amount <= 0 then
			self.items[slot].id = 0
			self.items[slot].amount = 0
			return true
		end
		return self.items[slot].id == 0 
	end
	function inst:GetAmount(slot)
		return self.items[slot].amount
	end
	function inst:SetAmount(slot, a)
		self.items[slot].amount = a
	end]]
	--inst:SetItem("arm", "food_bowl")
	return inst
end

return create