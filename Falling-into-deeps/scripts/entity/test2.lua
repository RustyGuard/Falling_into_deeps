local function create()
	local en = CreateEntity()
	local transform = en:AddComponent("transform")
	local animation = en:AddComponent("animation")
	animation:AddAnimation(1, "static"):Init("res/textures/test5.png")
	animation:Use(1)
	en.name = "test2"
	transform:CreateEntityCapability()
	return en
end

return create