local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.name = "test"
	function en:update()
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
		if self.transform.moved then
			Collide(self)
			self.transform.moved = false
		end
	end
	function en:render() self.transform:draw() end
	return en
end

return create