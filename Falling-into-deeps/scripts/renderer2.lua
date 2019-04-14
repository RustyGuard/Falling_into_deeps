local entities = {}
local tiles = {}
local tile_entities = {}
local registered_tiles = {}
local registered_entity = {}
local registered_component = {}
local uploaded_entities = {}
local time = 0
local time_load = 0

X_RANGE = 64
Y_RANGE = 64
local ENTITY_COUNT = 12
local time_limit = 2.0
local load_limit = 20.0
print("Renderer creating.")

function CreateComponent(c)
	if not registered_component[c] then
		registered_component[c] = require("scripts/components/" .. c)
	end
	return registered_component[c]()
end

-- If tile is 'nil' then it equals grass
local TILES_WIDTH = 4000
local TILES_HEIGHT = 4000

local tile_pos = CreateComponent("transform")
tile_pos.pos.x = 32
tile_pos.pos.y = 32

--registered_component["transform"] = require "scripts/components/transform"
registered_entity["test2"] = require "scripts/entity/test2"
registered_entity["test3"] = require "scripts/entity/test3"
registered_entity["player"] = require "scripts/entity/player"

registered_tiles[0] = require "scripts/tile/grass"
registered_tiles[1] = require "scripts/tile/void"

function SetTile(x, y, tile)
	if not InRange(x, y) then
		print("Wrong coordinates: " .. x .. " ".. y)
		return
	end
	tiles[GetPos(x, y)] = tile
end

function GetTile(x, y)
	return tiles[GetPos(x, y)]
end

function GetPos(x, y)
	return x + y * TILES_WIDTH
end

function InRange(x, y)
	return x >= 1 and y >= 1 and x <= TILES_WIDTH and y <= TILES_HEIGHT
end

function update(delta)
	time = time + delta
	time_load = time_load + delta
	if time > time_limit then
		time = time - time_limit
		local x = 0
		local y = 0
		for id, entity in pairs(entities) do
			if entity ~= entities.player then
				x, y = entity.transform:distation(entities.player.transform)
				if x > 4480 or y > 4480 then
					local i = #uploaded_entities + 1
					uploaded_entities[i] = entity
					--print("Entity uploaded: "..entity.id)
					entities[entity.id] = nil
					entity.id = i
				elseif x > 1280 or y > 1280 then
					entity.level = 3
				elseif x > 690 or y > 690 then
					entity.level = 2
				else
					entity.level = 1
				end
			end
		end		
	end
	if time_load > load_limit then
		time_load = time_load - load_limit
		local x = 0
		local y = 0
		for id, entity in pairs(uploaded_entities) do
				x, y = entity.transform:distation(entities.player.transform)
				if x < 4480 or y < 4480 then
					local i = #entities + 1
					entities[i] = entity
					uploaded_entities[entity.id] = nil
					--print("Entity loaded: " .. entity.id)
					entity.id = i
				end
		end
	end
	if entities.player then
		entities.player.transform:correctCamera()
	end
	for id, entity in pairs(entities) do
		if entity.update then
			entity:update(delta)
		end
	end
end

function render(delta)
	if entities.player then
		tx = math.floor(entities.player.transform.pos.x / 64)
		ty = math.floor(entities.player.transform.pos.y / 64)
	end
	for i = tx - 8, tx + 8 do
		for j = ty - 8, ty + 8 do
			if InRange(i, j) then
				if GetTile(i, j) == 1 then
					tile_pos.pos.x = i * 64
					tile_pos.pos.y = j * 64
					Draw(tile_pos.pos, tile_pos.half)
				end
			end
		end
	end

	for id, entity in pairs(entities) do
		if entity.render and entity.level == 1 then
			entity:render()
		end
	end
end



function Collide(entity)
	local tx = math.floor(entity.transform.pos.x / 64)
	local ty = math.floor(entity.transform.pos.y / 64)

	for i = tx - 1, tx + 1 do
		for j = ty - 1, ty + 1 do
			if InRange(i, j) then
				if GetTile(i, j) == 1 then
					tile_pos.pos.x = i * 64
					tile_pos.pos.y = j * 64
					entity.transform:collide(tile_pos) 
				end
			end
		end
	end
	for id, en in pairs(entities) do
		if en.transform and en~=entity and en.level ~=3 then
			if en.transform.static or en.level == 2 then
				if entity.transform:collide(en.transform) then
					Collide(entity)
				end
			else
				if en.transform:collide(entity.transform) then
					Collide(en)
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
	inst.id = #entities + 1
	-- 1 is a loadable zone
	-- 2 is a buffer zone
	-- 3 is a upload zone
	inst.level = 3
	return inst
end

function DeleteEntity(id)
	entities[id] = nil
end


registered_entity.player()
for i = 0, ENTITY_COUNT do
	registered_entity.test2()
end
registered_entity.test2()

for i = 1, 40 do
	SetTile(i, i, 1)
end
--SetTile(1, 1, 1)
SetTile(3, 1, 1)

print("Creating end.")