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
	function inst:GetPhysicDefence()
		return self:GetDefence("GetPhysicDefence")
	end
	function inst:GetFireDefence()
		return self:GetDefence("GetFireDefence")
	end
	function inst:GetIceDefence()
		return self:GetDefence("GetIceDefence")
	end
	function inst:GetShockDefence()
		return self:GetDefence("GetShockDefence")
	end
	function inst:GetDefence(name)
		local res = 0
		if self.items.helmet then
			res = res + self.items.helmet.components.armor[name](self.items.helmet.components.armor)
		end
		if self.items.chestplate then
			res = res + self.items.chestplate.components.armor[name](self.items.chestplate.components.armor)
		end
		if self.items.boots then
			res = res + self.items.boots.components.armor[name](self.items.boots.components.armor)
		end
		return res
	end
	return inst
end

return Prefab("inventory", fn)