GLFW_RELEASE = 0
GLFW_PRESS = 1
GLFW_REPEAT = 2

local component_func = {}
function CreateComponent(c)
	if not component_func[c] then
		component_func[c] = require("scripts/components/" .. c)
	end
	return component_func[c]()
end

-- Item init
ITEMS = {}
ITEMS[1] = require "scripts/item/copper_sword"
ITEMS[2] = require "scripts/item/copper_ingot"
ITEMS[3] = require "scripts/item/food_bowl"

local tile_renderer = require "scripts/tile_renderer"
local ui_renderer = require "scripts/ui_renderer"
local entity_renderer = require "scripts/entity_renderer"

-- Entity init
AddEntity("test2")
AddEntity("test2")
AddEntity("player")
---------------
SetTile(1, 1, "chest")
SetTile(3, 2, "chest")
---------------

function PushEvent(type, ...)
	local b = tile_renderer:PushEvent(type, ...) or ui_renderer:PushEvent(type, ...) or entity_renderer:PushEvent(type, ...)
end

print("All")