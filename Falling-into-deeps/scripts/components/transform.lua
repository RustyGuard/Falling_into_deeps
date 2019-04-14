local function create()
	local inst = {}
	inst.pos = vec3()
	inst.pos.x = 0
	inst.pos.y = 0
	function inst:SetCollidable()
		self.half = vec3()
		self.half = 0
		self.half = 0
	end
	function inst:SetDrawable()
		self.tex_half = vec3()
		self.tex_half.x = 0
		self.tex_half.y = 0

		function self:Draw()
			Draw(self.pos, self.tex_half)
		end

		function self:IsInside(a)
			local dist_x = math.abs(self.pos.x - a.x)
			local dist_y = math.abs(self.pos.y - a.y)
			return dist_x < self.tex_half.x and dist_y < self.tex_half.y
		end

	end
	return inst
end

return create