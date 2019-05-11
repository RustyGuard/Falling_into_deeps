local function create(p, v)
	local en = CreateEntity()
	local transform = en:AddComponent("transform")
	local inventory = en:AddComponent("inventory")
	--local animation = en:AddComponent("animation")

	transform:CreateEntityCapability()
	transform.static = true
	transform.pos = v
	en.position = p

	local anim1 = en:AddAnimation(1, "over")
	anim1:Init("res/textures/chest/chest", 0.5, 4)
	en:UseAnimation(1)
	anim1:SetReversed(true)
	anim1:Max()

	en.name = "chest"

	function en:OnMouseButtonReleased(b)
		if b == 0 then
			local inv = CreateUIItem("container")
			for i = 1, 3 do
				local b = CreateUIItem("slot")
				b:SetLocation(- (i * 50) - 75, -200)
				b:SetSize(24, 24)
				b:Init(self.components.inventory, i)
				inv:AddItem(b)
			end
			SetContainer("gui", inv)
			self:GetAnimation(1):Min()
			self:GetAnimation(1):SetReversed(false)
			return true
		end
		if b == 1 then
			SetContainer("gui", nil)
			self:GetAnimation(1):Min()
			self:GetAnimation(1):SetReversed(true)
			return true
		end
		return false
	end
	for i = 1, 3 do
		inventory:AddSlot(i)
		inventory:SetItem(i, 0)
		inventory:SetAmount(i, 0)
	end
	return en
end

return create