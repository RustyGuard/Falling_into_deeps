local function create()
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.inventory = CreateComponent("inventory")
	en.animation = CreateComponent("animation")
	--en.components.health = CreateComponent("health")

	en.transform:SetCollidable()
	en.transform:SetDrawable()
	en.transform.static = true

	local anim1 = en.animation:AddAnimation(1, "static")
	anim1:SetImage("res/textures/chest.png")
	en.animation:Use(1)

	en.name = "chest"

	function en:update(m_pos, delta)
		if GetMouseButton(0) == GLFW_PRESS and self.transform:IsInside(m_pos) then
			local inv = CreateUIItem("container")
			for i = 1, 3 do
				local b = CreateUIItem("slot")
				b:SetLocation(- (i * 50) - 75, -200)
				b:SetSize(24, 24)
				b:Init(en.inventory, i)
				inv:AddItem(b)
			end
			SetContainer("gui", inv)
		end
		if GetMouseButton(1) == GLFW_PRESS and self.transform:IsInside(m_pos) then
			SetContainer("gui", nil)
		end

	end

	function en:render()
		self.transform:Draw(self.animation:GetImage())
	end
	for i = 1, 3 do
		en.inventory:AddSlot(i)
		en.inventory:SetItem(i, 0)
		en.inventory:SetAmount(i, 0)
	end
	return en
end

return create