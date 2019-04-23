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
	local i = self.item_func[name]()
	self.ui[#self.ui + 1] = i
	return i
end

function AddUIItem(name)
	return inst:AddItem(name)
end

-- Creating the button
--local button = inst:AddItem("button")
--button:SetLocation(64, 64)
--button:SetSize(32, 64)
local function f()
	print("Callback")
end
--button:SetCallback(f)
-- End

--inst.texture = CreateTexture("res/textures/test.png")
MOUSE_SLOT = {}
MOUSE_SLOT.item = 2
MOUSE_SLOT.amount = 5

-- Creating the progress bar
--local progress = inst:AddItem("progress_bar")
--progress:SetLocation(256, 256)
--progress:SetSize(64, 32)
-- End


function inst:update(delta)
	self.pos.x = GetMouseX()
	self.pos.y = GetMouseY()
	for id, item in pairs(self.ui) do
		item:update(self.pos)
	end
end

function inst:render()
	--DrawUI(self.texture, self.pos, self.half, 1, 1)
	for id, item in pairs(self.ui) do
		item:render()
	end
	if MOUSE_SLOT.item ~= 0 then
		DrawUI(ITEMS[MOUSE_SLOT.item].texture, self.pos, self.half, 1, 1)
	end
end

return inst