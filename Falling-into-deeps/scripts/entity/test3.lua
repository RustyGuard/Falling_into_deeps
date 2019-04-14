local function create()
	local en = CreateEntity()
	en.name = "test3"
	en.transform = CreateComponent("transform")
	en.transform.static = true
	function en:update(delta) end
	function en:render() self.transform:draw() end
	SetEntity(en.id, en)
	en.transform.pos.x = math.random(-640, 640)
	en.transform.pos.y = math.random(-640, 640)
	return en
end

return create