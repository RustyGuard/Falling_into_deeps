local inst = {}

function inst:PushEvent(type, ...)
	if self[type] then
		return self[type](self, ...)
	end
	return false
end

return inst