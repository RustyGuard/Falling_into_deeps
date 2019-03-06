local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	function en:update() 
		if self.transform.moved then
			Collide(self)
		end
	end
	function en:render() self.transform:draw() end
	return en
end

return create