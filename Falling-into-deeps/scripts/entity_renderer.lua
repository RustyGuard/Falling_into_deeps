local inst = {}
inst.entities = {}

function AddEntity(name)
	local en = FindPrefab(name):Create()
	table.insert(inst.entities, en)
	return en
end

function RemoveEntity(entity)
	for i, v in ipairs(inst.entities) do
		if entity == v then
			table.remove(inst.entities, i)
			return
		end
	end
end

function FindFirstWithTag(tag)
	for _, i in ipairs(inst.entities) do
		if i:HasTag(tag) then return i end
	end
end

function inst:PushEvent(type, ...)
	for _, i in ipairs(self.entities) do
		i:PushEvent(type, ...)
	end
	if self[type] then
		return self[type](self, ...)
	end
	return false
end

function inst:OnKeyReleased(key)
	if key == 73 then
		for _, en in ipairs(self.entities) do
			en:DebugInfo()
		end
	end
end

return inst