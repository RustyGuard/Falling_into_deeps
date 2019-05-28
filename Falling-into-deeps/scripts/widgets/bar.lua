require "scripts/widgets/widget"

Bar = Widget:extend()

function Bar:init(v)
	Widget.init(self)
	self.v = {get = function() return v.components.health.health end}
	self.max = {get = function() return v.components.health.maxhealth end}
	self.tex1 = CreateTexture("res/textures/test2.png")
	self.tex2 = CreateTexture("res/textures/test3.png")
	self.half.x = 64
end

function Bar:OnRender()
	DrawUI(self.tex1, self.pos, self.half, self.v / self.max, 1)
	DrawUI(self.tex2, self.pos, self.half, 1, 1)
end