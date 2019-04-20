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
	--function en:update(delta) 
		--if self.transform.moved then
			--Collide(self)
		--end
	--end
	function en:render() self.transform:Draw(self.texture) end
	--en.transform.pos.x = math.random(-X_RANGE, X_RANGE)
	--en.transform.pos.y = math.random(-Y_RANGE, Y_RANGE)
	--SetEntity(en.id, en)
	return en
end

return create