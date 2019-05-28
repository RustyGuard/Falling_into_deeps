require "scripts/widgets/widget"

Button = Widget:extend()

function Button:init()
	Widget.init(self)
	self.tex = CreateTexture("res/textures/test6.png")
end

function Button:OnRender()
	DrawUI(self.tex, self.pos, self.half, 1, 1)
end

function Button:OnUpdate()
	
end