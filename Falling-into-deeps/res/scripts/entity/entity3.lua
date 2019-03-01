init = function(inst)
	inst:AddComponent("transform")
	inst:GetTransform():move(-50.0, 0.0)
	inst:GetTransform():setMovable(false)
end

update = function(world, inst, delta)
end

render = function(inst)
	inst:GetTransform():draw()
end
