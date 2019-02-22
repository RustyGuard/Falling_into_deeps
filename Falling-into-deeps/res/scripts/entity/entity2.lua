init = function(inst)
	inst:AddComponent("transform")

end

update = function(inst, delta)
	--inst:GetTransform():move(1, 1)
end

render = function(inst)
	inst:GetTransform():draw()
end

interact = function(inst, entity)
	--print("interact 2")
	if (entity:GetTransform()) then
		entity:GetTransform():collide(inst:GetTransform())
	end
end
