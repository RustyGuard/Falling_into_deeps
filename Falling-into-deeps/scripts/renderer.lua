entities = {}
registered_entity = {}
registered_component = {}
print("Renderer created")

--registered_component["transform"] = require "scripts/components/transform"
registered_entity["test"] = require "scripts/entity/test"
registered_entity["test2"] = require "scripts/entity/test2"

function update(delta)
	for id, entity in pairs(entities) do
		if entity.update then
			entity:update()
			print("update")
		else
			print("hasnt")
		end
	end
	print("****")
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

function render() 
end

registered_entity.test()
registered_entity.test2()
registered_entity.test()