local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	function en:update() 
		if self.transform.moved then
			Collide(self)
		end
	end
	function en:render() self.transform:draw() end
	en.transform.pos.x = math.random(-640, 640)
	en.transform.pos.y = math.random(-640, 640)
	SetEntity(en.id, en)
	return en
end

return create