entities = {}
tiles = {}
registered_tiles = {}
registered_entity = {}
registered_component = {}

print("Renderer created")

-- If tile is 'nil' then it equals grass
TILES_WIDTH = 2
TILES_HEIGHT = 2

--registered_component["transform"] = require "scripts/components/transform"
registered_entity["test"] = require "scripts/entity/test"
registered_entity["test2"] = require "scripts/entity/test2"
registered_entity["test3"] = require "scripts/entity/test3"

function SetTile(x, y, tile)
	if x < 1 or y < 1 or x > TILES_WIDTH or y > TILES_HEIGHT then
		print("Wrong coordinates: " .. x .. " ".. y)
		return
	end
	if not registered_tiles[tile] then
		registered_tiles[tile] = require("scripts/tile/" .. tile)
	end
	tiles[GetPos(x, y)] = registered_tiles[tile](x, y)
end

function GetPos(x, y)
	return x + y * TILES_WIDTH
end

function update(delta)
	entities[1].transform:correctCamera()
	for id, entity in pairs(entities) do
		if entity.update then
			entity:update()
		end
	end
end

function render(delta)
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

function CreateEntity()
	local inst = {}
	inst.components = {}
	for i = 1, 10000 do
		if not entities[i] then
			entities[i] = inst
			print("id: " .. i)
			break
		end
	end
	return inst
end

function Collide(entity)
	for id, en in pairs(entities) do
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
	for id, en in pairs(tiles) do
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

registered_entity.test()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test3()
SetTile(1, 1, "void")
SetTile(2, 2, "void")
SetTile(3, 2, "void")
SetTile(2, 0, "void")
SetTile(1, 2, "void")
print(entities[1].name)