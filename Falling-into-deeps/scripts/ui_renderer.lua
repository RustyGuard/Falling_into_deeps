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
	self.ui[#self.ui + 1] = self.item_func[name]()
end
inst:AddItem("button")
inst.texture = CreateTexture("res/textures/test.png")

function inst:update(delta)
	self.pos.x = GetMouseX()
	self.pos.y = GetMouseY()
	for id, item in pairs(self.ui) do
		item:update(self.pos)
	end
end

function inst:render()
	BindTexture(self.texture, 0)
	Draw(self.pos, self.half)
	for id, item in pairs(self.ui) do
		item:render()
	end
end

return inst