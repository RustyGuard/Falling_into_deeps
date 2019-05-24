local inst = {}

inst.pos = vec3()
inst.pos.x = 0
inst.pos.y = 0
inst.half = vec3()
inst.half.x = 32
inst.half.y = 32
MOUSE_SLOT = CreateComponent("inventory")
--MOUSE_SLOT:SetItem(1, "copper_sword")

local item_func = {}
inst.ui = {}

function CreateUIItem(name)
	if not item_func[name] then
		item_func[name] = require("scripts/ui/" .. name)
	end
	return item_func[name]()
end

function GetContainer(name)
	return inst.ui[name]
end

function SetContainer(name, cont)
	inst.ui[name] = cont
end

function inst:OnUpdate(delta)
	self.pos.x = GetMouseX()
	self.pos.y = GetMouseY()
	for id, item in pairs(self.ui) do
		if item.update then
			item:update(self.pos)
		end
	end
end

function inst:OnRender()
	for id, item in pairs(self.ui) do
		item:render()
	end
	if not MOUSE_SLOT:IsEmpty(1) then
		DrawUI(MOUSE_SLOT:GetItem(1):GetImage(), self.pos, self.half, 1, 1)
	end
end

function inst:PushEvent(type, ...)
	if self[type] then
		return self[type](self, ...)
	end
	return false
end

function inst:OnMouseButtonReleased(button)
	for id, item in pairs(self.ui) do
		if item.OnMouseButtonReleased then
			if item:OnMouseButtonReleased(button, self.pos) then
				return true
			end
		end
	end
end

return inst