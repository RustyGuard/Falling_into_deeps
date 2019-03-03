keys = require "res/scripts/keys"

init = function(inst)
	inst:AddComponent("transform")
	inst:GetTransform():move(128, 128)
	inst:AddComponent("inventory")
end

update = function(world, inst, delta)
	if (isPressed("a")) then
		inst:GetTransform():move(-1.5, 0)
	end
	if (isPressed("d")) then
		inst:GetTransform():move(1.5, 0)
	end
	if (isPressed("w")) then
		inst:GetTransform():move(0, -1.5)
	end
	if (isPressed("s")) then
		inst:GetTransform():move(0, 1.5)
	end
	if (inst:GetTransform():isMoved()) then
		world:collide(inst:GetTransform());
	end
end

render = function(inst)
	inst:GetTransform():draw()
end
