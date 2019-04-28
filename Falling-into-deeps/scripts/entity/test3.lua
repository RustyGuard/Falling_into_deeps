local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.name = "test2"
	en.texture = CreateTexture("res/textures/test5.png")
	en.transform:SetCollidable()
	en.transform:SetDrawable()
	en.transform.static = true
	en.transform.pos.x = -64
	en.transform.pos.y = -64
	function en:render() self.transform:Draw(self.texture) end
	return en
end

return create