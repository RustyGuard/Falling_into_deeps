function CreateEntity()
	local en = {}
	en.tags = {}
	-------------------------------------------
	function en:AddTag(tag)
		table.insert(self.tags, tag)
	end
	function en:HasTag(tag)
		for _, i in ipairs(self.tags) do
			if i == tag then return true end
		end
		return false
	end
	------------------------------------------
	en.components = {}
	function en:AddComponent(name)
		local c = FindPrefab(name):Create(self)
		self.components[name] = c
		return c
	end
	------------------------------------------
	en.listeners = {}
	function en:AddListener(type, fn)
		if not self.listeners[type] then self.listeners[type] = {} end
		self.listeners[type][fn] = true
	end
	function en:RemoveListener(type, fn)
		self.listeners[type][fn] = nil
	end
	function en:PushEvent(type, ...)
		if self.listeners[type] then
			for i, v in pairs(self.listeners[type]) do
				if v then i(self, ...) end
			end
		end
	end
	return en
end

require "scripts/prefab"

local entity_renderer = require "scripts/entity_renderer"
local tile_renderer = require "scripts/tile_renderer"
local ui_renderer = require "scripts/ui_renderer"

dummy = AddEntity("dummy")
player = AddEntity("player")

player:PushEvent("Punch", dummy)

function PushEvent(type, ...)
	if type == "OnMouseButtonReleased" then
		player:PushEvent("Punch", dummy)
	end
	local b = tile_renderer:PushEvent(type, ...) or ui_renderer:PushEvent(type, ...) or entity_renderer:PushEvent(type, ...)
end