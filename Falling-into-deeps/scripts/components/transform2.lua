local function create()
	local inst = {}
	inst.pos = vec3()
	inst.pos.x = 0
	inst.pos.y = 0
	inst.half = vec3()
	inst.half.x = 32
	inst.half.y = 32
	inst.moved = true
	function inst:move(x, y) 
		self.pos.x = self.pos.x + x
		self.pos.y = self.pos.y + y
		self.moved = true
	end
	function inst:draw() Draw(self.pos, self.half) end
	function inst:collide(b)
		local dist_x = self.pos.x - b.pos.x;
		local dist_y = self.pos.y - b.pos.y;
		if math.abs(dist_x) < (self.half.x + b.half.x) and (math.abs(dist_y) < self.half.y + b.half.y) then
			if math.abs(dist_x) > math.abs(dist_y) then
				if dist_x > 0 then
					self.pos.x = b.pos.x + (self.half.x + b.half.x)
				else
					self.pos.x = b.pos.x - (self.half.x + b.half.x)
				end
			else
				if dist_y > 0 then
					self.pos.y = b.pos.y + (self.half.y + b.half.y)
				else
					self.pos.y = b.pos.y - (self.half.y + b.half.y)
				end
			end
			return true
		end
		return false
	end
	function inst:correctCamera()
		local x = - self.pos.x - GetCameraX()
		local y = - self.pos.y - GetCameraY()
		MoveCamera(x / 9, y / 9)
	end
	function inst:distation(b)
		return math.abs(self.pos.x - b.pos.x), math.abs(self.pos.y - b.pos.y)
	end

	return inst
end

return create