local inst = {}

inst.entity_func = {}
inst.entities = {}

function CreateEntity()
	local en = {}
	local id = #inst.entities + 1
	en.id = id
	inst.entities[id] = en
	return en
end

function ChangeId(last, new)
	if inst.entities[new] then
		print("This id is already taken.")
		return
	end
	local en = inst.entities[last]
	inst.entities[last] = nil
	inst.entities[new] = en
	en.id = new
end

function AddEntity(name)
	if not inst.entity_func[name] then
		inst.entity_func[name] = require("scripts/entity/" .. name)
	end
	return inst.entity_func[name]()
end


function inst:render()
	for id, en in pairs(self.entities) do
		if en.render then
			en:render()
		end
	end
end

function inst:update(delta)
	for id, en in pairs(self.entities) do
		if en.update then
			en:update(delta)
		end
		if en.transform and (en.transform.collidable and en.transform.moved) then
			for i, e in pairs(self.entities) do
				if e ~= en and e.transform then
					if e.transform.static then
						en.transform:Correct(e.transform)
					else
						if e.transform:Correct(en.transform) then
							for ide, ene in pairs(self.entities) do
								if ene ~= e then
									if e.transform:Correct(ene.transform) then
										en.transform:Correct(e.transform)
									end
								end
							end
						end
					end
				end
			end
			en.transform.moved = false
		end
	end
end

return inst