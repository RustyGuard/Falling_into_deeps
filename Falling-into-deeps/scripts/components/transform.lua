local function create()
	local inst = {}
	inst.pos = vec3()
	inst.pos.x = 30
	inst.pos.y = 300
	inst.half = vec3()
	function inst:addx(a) self.pos.x = self.pos.x + a end
	function inst.collide(a, b)
		dist_x = a.pos.x - b.pos.x;
		dist_y = a.pos.y - b.pos.y;
		if math.abs(dist_x) < (a.half.x + b.half.x) and (math.abs(dist_y) < a.half.y + b.half.y) then
			if math.abs(dist_x) > math.abs(dist_y) then
				if dist_x > 0 then
					a.pos.x = b.pos.x + (a.half.x + b.half.x)
				else
					a.pos.x = b.pos.x - (a.half.x + b.half.x)
				end
			else
				if dist_y > 0 then
					a.pos.y = b.pos.y + (a.half.y + b.half.y)
				else
					a.pos.y = b.pos.y - (a.half.y + b.half.y)
				end
			end
			return true
		end
		return false
	end

	print("created transform")
	return inst
end

return create