local function create()
	local en = CreateEntity()
	en.name = "test3"
	en.transform = CreateComponent("transform")
	en.transform.static = true
	function en:update() end
	function en:render() self.transform:draw() end
	SetEntity(en.id, en)
	return en
end

return create