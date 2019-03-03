init = function(inst)
	inst:AddComponent("transform")
end

update = function(world, inst, delta)
	--inst:GetTransform():move(0.1, 0.1)
	if (inst:GetTransform():isMoved()) then
		world:collide(inst:GetTransform());
	end
end

render = function(inst)
	inst:GetTransform():draw()
end
