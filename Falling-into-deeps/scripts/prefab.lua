Prefab = class()
function Prefab:init(name, fn)
	self.name = name
	self.fn = fn

end
function Prefab:Create(...)
	return self.fn(...)
end

PREFABFILES = {
	"player",
	"chest",
	"components/transform",
	"components/inventory",
	"components/weapon",
	"components/health",
	"components/combat",
	"components/armor",
	"food_bowl",
	"dummy",
	"copper_sword",
	"copper_armor"
}

PREFABLIST = {}
for _, i in ipairs(PREFABFILES) do
	local prefab = require("scripts/prefabs/" .. i)
	if prefab.Create then
		table.insert(PREFABLIST, prefab)
	else
		for _, f in ipairs(prefab) do
			table.insert(PREFABLIST, f)
		end
	end
end
--[[for _, i in ipairs(PREFABLIST) do
	print(i.name)
end]]
FindPrefab = function(name)
	for _, i in ipairs(PREFABLIST) do
		if i.name == name then return i end
	end
end