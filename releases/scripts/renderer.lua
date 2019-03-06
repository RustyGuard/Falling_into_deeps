entities = {}
registered_entity = {}
registered_component = {}
print("Renderer created")

--registered_component["transform"] = require "scripts/components/transform"
registered_entity["test"] = require "scripts/entity/test"
registered_entity["test2"] = require "scripts/entity/test2"
registered_entity["test3"] = require "scripts/entity/test3"

function update(delta)
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
end

registered_entity.test()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test2()
registered_entity.test3()