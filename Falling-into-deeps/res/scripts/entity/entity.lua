keys = require "res/scripts/keys"

init = function(inst)
	inst:AddComponent("transform")
	inst:GetTransform():move(128, 128)
	inst:AddComponent("inventory")
end

update = function(inst, delta)
	if (isPressed("a")) then
		inst:GetTransform():move(-1, 0)
	end
	if (isPressed("d")) then
		inst:GetTransform():move(1, 0)
	end
	if (isPressed("w")) then
		inst:GetTransform():move(0, -1)
	end
	if (isPressed("s")) then
		inst:GetTransform():move(0, 1)
	end
end

render = function(inst)
	inst:GetTransform():draw()
end

interact = function(inst, entity)
	--print("interact")
	if (entity:GetTransform()) then
		entity:GetTransform():collide(inst:GetTransform())
	end
end
