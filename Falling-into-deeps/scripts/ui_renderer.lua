local inst = {}

inst.pos = vec3()
inst.pos.x = 1200
inst.pos.y = 675

inst.half = vec3()
inst.half.x = 32
inst.half.y = 32
inst.item_func = {}
inst.ui = {}

function inst:AddItem(name)
	if not self.item_func[name] then
		self.item_func[name] = require("scripts/ui/" .. name)
	end
	i = self.item_func[name]()
	self.ui[#self.ui + 1] = i
	return i
end

-- Creating the button
local button = inst:AddItem("button")
button:SetLocation(64, 64)
button:SetSize(32, 64)
local function f()
	print("Callback")
end
button:SetCallback(f)
inst.texture = CreateTexture("res/textures/test.png")
-- End

function inst:update(delta)
	self.pos.x = GetMouseX()
	self.pos.y = GetMouseY()
	--self.pos.z = 200
	for id, item in pairs(self.ui) do
		item:update(self.pos)
	end
end

function inst:render()
	BindTexture(self.texture, 0)
	Draw(self.pos, self.half, 0.25)
	for id, item in pairs(self.ui) do
		item:render()
	end
end

return inst