local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.name = "test2"
	function en:update(delta) 
		if self.transform.moved then
			Collide(self)
		end
	end
	function en:render() self.transform:draw() end
	en.transform.pos.x = math.random(-X_RANGE, X_RANGE)
	en.transform.pos.y = math.random(-Y_RANGE, Y_RANGE)
	SetEntity(en.id, en)
	return en
end

return create