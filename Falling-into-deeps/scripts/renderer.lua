local entities = {}
local tiles = {}
local registered_tiles = {}
local registered_entity = {}
local registered_component = {}

print("Renderer creating.")

-- If tile is 'nil' then it equals grass
local TILES_WIDTH = 4
local TILES_HEIGHT = 4

function GetNextId()
	for i = 1, 10000 do
		if not entities[i] then
			return i
		end
	end
end

--registered_component["transform"] = require "scripts/components/transform"
registered_entity["test2"] = require "scripts/entity/test2"
registered_entity["test3"] = require "scripts/entity/test3"
registered_entity["player"] = require "scripts/entity/player"

function SetTile(x, y, tile)
	if x < 1 or y < 1 or x > TILES_WIDTH or y > TILES_HEIGHT then
		print("Wrong coordinates: " .. x .. " ".. y)
		return
	end
	if not registered_tiles[tile] then
		registered_tiles[tile] = require("scripts/tile/" .. tile)
	end
	tiles[GetPos(x, y)] = registered_tiles[tile](x, y).id
end

function GetPos(x, y)
	return x + y * TILES_WIDTH
end

function update(delta)
	--print("update")
	if entities.player then
		--entities.player:update()
		entities.player.transform:correctCamera()
	end
	for id, entity in pairs(entities) do
		if entity.update then
			entity:update()
		end
	end
end

function render(delta)
	--entities.player:render()
	for id, entity in pairs(entities) do
		if entity.render then
			entity:render()
		end
	end
end

function CreateComponent(c)
	if not registered_component[c] then
		registered_component[c] = require("scripts/components/" .. c)
	end
	return registered_component[c]()
end


function Collide(entity)
	for id, en in ipairs(entities) do
		if en.transform and en~=entity then
			if not en.transform.static then
				if en.transform:collide(entity.transform) then
					Collide(en)
				end
			else
				if entity.transform:collide(en.transform) then
					Collide(entity)
				end
			end
		end
	end
end

function SetEntity(id, entity)
	entities[id] = entity
end

function CreateEntity()
	local inst = {}
	inst.components = {}
	inst.id = GetNextId()
	return inst
end

function DeleteEntity(id)
	entities[id] = nil
end


registered_entity.player()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()

SetTile(1, 1, "void")
SetTile(3, 1, "void")

print("Creating end.")