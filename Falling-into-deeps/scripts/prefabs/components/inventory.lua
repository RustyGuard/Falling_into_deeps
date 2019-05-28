local function foo(entity, button)
	for s, i in pairs(entity.components.inventory.items) do
		print("Slot: " .. s .. " // Item: " .. i:to_string())
	end
end

local function fn(entity)
	local inst = {}
	inst.items = {}
	function inst:SetItem(slot, name)
		self.items[slot] = FindPrefab(name):Create(self, slot)
	end
	function inst:GetArmSlot()
		return self.items.arm
	end
	function inst:GetHelmetSlot()
		return self.items.helmet
	end
	function inst:GetChestpateSlot()
		return self.items.chestplate
	end
	function inst:GetBootsSlot()
		return self.items.boots
	end
	function inst:GetSlotDefence(slot, type)
		if self.items[slot] and self.items[slot].components.armor then
			return self.items[slot].components.armor:GetDefence(type)
		end
		return 0
	end
	function inst:GetDefence(type)
		return self:GetSlotDefence("helmet", type) + self:GetSlotDefence("boots", type) + self:GetSlotDefence("chestplate", type)
	end
	function inst:DebugInfo()
		print("Inventory")
		print("[[[[[[[[[[[[[[[[[[[[[[[[[")
		for i, j in pairs(self.items) do
			print("Slot:" .. i)
			j:DebugInfo()
			print()
		end
		print("]]]]]]]]]]]]]]]]]]]]]]]]]")
	end
	return inst
end

return Prefab("inventory", fn)