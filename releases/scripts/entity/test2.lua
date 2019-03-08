local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	function en:render() self.transform:draw() end
	return en
end

return create