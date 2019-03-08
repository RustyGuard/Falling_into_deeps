local function create(x, y)
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.transform.pos.x = x * 64
	en.transform.pos.y = y * 64
	en.transform.static = true
	function en:render() self.transform:draw() end
	SetEntity(en.id, en)
	return en
end

return create