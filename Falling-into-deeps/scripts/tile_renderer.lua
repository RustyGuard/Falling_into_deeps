local inst = {}
inst.tiles = {}
inst.width = 3
inst.height = 3

function inst:CorrectCoord(x, y)
	return x >= 1 and y >= 1 and x <= self.width and y <= self.height
end

function inst:Key(x, y)
	return x + y * self.width
end

function inst:GetTile(x, y)
	return self.tiles[self:Key(x, y)]
end

function inst:SetTile(x, y, tile)
	if not self:CorrectCoord(x, y) then
		print("Wrong: " .. x .. " " .. y)
		return
	end
	self.tiles[self:Key(x, y)] = tile
end

return inst