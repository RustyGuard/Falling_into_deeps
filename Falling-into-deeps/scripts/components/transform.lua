local function create()
	local inst = {}
	inst.pos = vec3()
	inst.pos.x = 0
	inst.pos.y = 0
	inst.moved = true
	function inst:move(x, y)
		self.pos.x = self.pos.x + x
		self.pos.y = self.pos.y + y
		self.moved = true
	end
	function inst:CreateEntityCapability()
		self.half = vec3()
		self.half.x = 32
		self.half.y = 32
		self.collidable = true
		self.tex_half = vec3()
		self.tex_half.x = 32
		self.tex_half.y = 32
		function self:IsInside(a)
			local dist_x = math.abs(self.pos.x - a.x)
			local dist_y = math.abs(self.pos.y - a.y)
			return dist_x < self.tex_half.x and dist_y < self.tex_half.y
		end
		function inst:Correct(b)
			local dist_x = self.pos.x - b.pos.x
			local dist_y = self.pos.y - b.pos.y
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
		function inst:CorrectCamera()
			local x = - self.pos.x - GetCameraX()
			local y = - self.pos.y - GetCameraY()
			MoveCamera(x, y)
		end
		function inst:OnRender(entity)
			Draw(entity:GetImage(), self.pos, self.tex_half, 0.5)
		end
	end
	function inst:CreateUICapability()
		self.tex_half = vec3()
		self.tex_half.x = 32
		self.tex_half.y = 32

		function self:DrawUI(tex, a, b)
			DrawUI(tex, self.pos, self.tex_half, a, b)
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