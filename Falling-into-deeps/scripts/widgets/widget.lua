Widget = class()

function Widget:init()
	self.pos = vec3()
	self.half = vec3()
	self.half.x = 32
	self.half.y = 32
	self.listeners = {}
	print("Created")
end

function Widget:setSize(w, h)
	self.half.x = w
	self.half.y = h
end

function Widget:setLocation(x, y)
	self.pos.x = x
	self.pos.y = y
end

function Widget:addListener(event, fn)
	if not self.listeners[event] then 
		self.listeners[event] = {}
	end
	self.listeners[event][fn] = true
end

function Widget:removeListener(event, fn)
	self.listeners[event][fn] = nil
end

function Widget:PushEvent(event, ...)
	if self.listeners[event] then
		for i, _ in pairs(self.listeners[event]) do
			i(self, ...)
		end
	end
	if self[event] then
		return self[event](self, ...)
	end
end

function Widget:IsInside(x, y)
	return math.abs(self.pos.x - x) < self.half.x and math.abs(self.pos.y - y) < self.half.y
end