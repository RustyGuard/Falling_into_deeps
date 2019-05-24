local function create()
	local en = CreateEntity()
	local transform = en:AddComponent("transform")
	--local animation = en:AddComponent("animation")
	en:AddAnimation(1, "static"):Init("res/textures/test5.png")
	en:UseAnimation(1)
	en.name = "test2"
	transform:CreateEntityCapability()
	return en
end

return create