local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.transform:addx(1)
	en.update = function() end
	print(en.transform.pos.x)
	print("created entity")
	return en
end

return create