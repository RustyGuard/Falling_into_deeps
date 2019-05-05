local inst = {}
inst.tiles = {}
inst.width = 3
inst.height = 3
inst.types = {}
inst.types.chest = require "scripts/tileentity/chest"

function inst:CorrectCoord(x, y)
	return x >= 0 and y >= 0 and x <= self.width and y <= self.height
end

function inst:Key(x, y)
	return x + y * self.width
end

function inst:GetTile(x, y)
	return self.tiles[self:Key(x, y)]
end

function SetTile(x, y, tile)
	if not inst:CorrectCoord(x, y) then
		print("Wrong: " .. x .. " " .. y)
		return
	end
	local p = inst:Key(x, y)
	if inst.tiles[p] then
		print("Already taken!")
		return
	end
	local v = vec3()
	v.x = x * 64
	v.y = y * 64
	inst.tiles[p] = inst.types[tile](p, v)
end

function RemoveTile(x, y)
	--inst.tiles[inst:GetKey(x, y)].remove()
	inst.tiles[inst:GetKey(x, y)] = nil
end

function inst:render()

end

function inst:update(delta)
	
end

function inst:PushEvent(type, ...)
	if self[type] then
		return self[type](self, ...)
	end
	return false
end

return inst