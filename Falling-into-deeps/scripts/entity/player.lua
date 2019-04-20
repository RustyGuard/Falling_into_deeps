local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.transform:SetCollidable()
	en.transform:SetDrawable()
	--en.components.health = CreateComponent("health")
	en.name = "player"
	en.texture = CreateTexture("res/textures/test4.png")
	ChangeId(en.id, "player")
	function en:update(delta)
		if GetKey("a") ~= GLFW_RELEASE then
			self.transform:move(-1.5, 0)
		end
		if GetKey("d") ~= GLFW_RELEASE then
			self.transform:move(1.5, 0)
		end
		if GetKey("w") ~= GLFW_RELEASE then
			self.transform:move(0, -1.5)
		end
		if GetKey("s") ~= GLFW_RELEASE then
			self.transform:move(0, 1.5)
		end
		--if (isPressed("f")) then
			--if self.components.health:damage(1) then
				--DeleteEntity(en.id)
			--end
		--end
		--if (isPressed("h")) then
			--self.components.health:heal(1)
		--end
	end
	function en:render()
		self.transform:Draw(self.texture)
	end
	return en
end

return create