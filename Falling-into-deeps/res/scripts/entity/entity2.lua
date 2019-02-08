init = function(inst)
	inst:AddComponent("transform")
end

update = function(inst, delta)
	inst:GetTransform():move(1, 1)
end

render = function(inst)
	inst:GetTransform():draw()
end
