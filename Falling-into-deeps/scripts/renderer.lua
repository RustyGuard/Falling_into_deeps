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

local tile_renderer = require "scripts/tile_renderer"
local entity_renderer = require "scripts/entity_renderer"
local ui_renderer = require "scripts/ui_renderer"

AddEntity("test2")
AddEntity("test2")
AddEntity("test3")
AddEntity("player")

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