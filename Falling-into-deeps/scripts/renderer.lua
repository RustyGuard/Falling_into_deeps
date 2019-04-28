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
AddEntity("test3")
AddEntity("player")
local chest = AddEntity("chest")
chest.transform:move(64, 64)
---------------

gui = CreateUIItem("container")
local but = CreateUIItem("button")
but:SetLocation(64, 64)
but:SetSize(32, 64)
gui:AddItem(but)
SetContainer("gui", gui)

function update(delta) 
	ui_renderer:update(delta)
	tile_renderer:update(delta)
	entity_renderer:update(delta)
end

function render()
	ui_renderer:render()
	tile_renderer:render()
	entity_renderer:render()
end

print("All")