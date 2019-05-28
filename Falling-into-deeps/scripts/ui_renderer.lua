local inst = {}
inst.widgets = {}
function AddWidget(w)
	table.insert(inst.widgets, w)
end

function inst:PushEvent(type, ...)
	if self[type] then
		return self[type](self, ...)
	end
	for _, i in ipairs(self.widgets) do
		if i:PushEvent(type, ...) then
			return true
		end
	end
	return false
end

function inst:OnMouseButtonReleased(button)
	local x = GetMouseX()
	local y = GetMouseY()
	for _, i in ipairs(self.widgets) do
		if i:IsInside(x, y) then
			i:PushEvent("OnMouseButtonReleased", button)
			return true
		end
	end
end

return inst