init = function(inst)
	inst:AddComponent("transform")
end

update = function(inst, delta)
	--print("update2")
	inst:GetTransform():move(1, 1)
end

render = function(inst)
	--print("render2")
end
