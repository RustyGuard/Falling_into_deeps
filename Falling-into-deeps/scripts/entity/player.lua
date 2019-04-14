local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.components.health = CreateComponent("health")
	en.id = "player"
	en.name = "player"
	en.level = 1
	SetEntity(en.id, en)
	function en:update(delta)
		if (isPressed("a")) then
			self.transform:move(-1.5, 0)
		end
		if (isPressed("d")) then
			self.transform:move(1.5, 0)
		end
		if (isPressed("w")) then
			self.transform:move(0, -1.5)
		end
		if (isPressed("s")) then
			self.transform:move(0, 1.5)
		end
		if (isPressed("f")) then
			if self.components.health:damage(1) then
				DeleteEntity(en.id)
			end
		end
		if (isPressed("h")) then
			self.components.health:heal(1)
		end
		if self.transform.moved then
			Collide(self)
			self.transform.moved = false
		end
	end
	function en:render() self.transform:draw() end
	return en
end

return create