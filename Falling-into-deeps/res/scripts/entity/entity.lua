init = function(inst)
	inst:AddComponent("transform")
	inst:GetTransform():move(128, 128)
end

update = function(inst, delta)
	--print("update1")
end

render = function(inst)
	--print("render1")
end
