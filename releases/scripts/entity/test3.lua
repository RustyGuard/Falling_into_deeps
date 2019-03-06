local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.transform.static = true
	function en:update() end
	function en:render() self.transform:draw() end
	return en
end

return create