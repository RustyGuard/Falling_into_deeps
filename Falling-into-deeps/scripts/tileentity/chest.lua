local function create(p, v)
	local en = CreateEntity()
	en.transform = CreateComponent("transform")
	en.inventory = CreateComponent("inventory")
	en.animation = CreateComponent("animation")
	--en.components.health = CreateComponent("health")

	en.transform:SetCollidable()
	en.transform:SetDrawable()
	en.transform.static = true
	en.transform.pos = v
	en.position = p

	local anim1 = en.animation:AddAnimation(1, "over")
	anim1:Init("res/textures/chest/chest", 0.6, 4)
	en.animation:Use(1)
	anim1:Reverse()
	anim1:Max()

	en.name = "chest"

	function en:update(m_pos, delta)
		self.animation:update(delta)
	end

	function en:render()
		self.transform:Draw(self.animation:GetImage())
	end

	function en:OnMouseButtonReleased(b, p)
		if b == 0 and self.transform:IsInside(p) then
			local inv = CreateUIItem("container")
			for i = 1, 3 do
				local b = CreateUIItem("slot")
				b:SetLocation(- (i * 50) - 75, -200)
				b:SetSize(24, 24)
				b:Init(en.inventory, i)
				inv:AddItem(b)
			end
			SetContainer("gui", inv)
			self.animation:Get(1):Min()
			self.animation:Get(1):Reverse()
			return true
		end
		if b == 1 and self.transform:IsInside(p) then
			SetContainer("gui", nil)
			self.animation:Get(1):Min()
			self.animation:Get(1):Reverse()
			return true
		end
		return false
	end
	for i = 1, 3 do
		en.inventory:AddSlot(i)
		en.inventory:SetItem(i, 0)
		en.inventory:SetAmount(i, 0)
	end
	return en
end

return create