local function OnRender(entity)
	comp = entity.components.transform
	Draw(entity:GetImage(), comp.pos, comp.tex_half, 0.5)
end

local function fn(entity)
	local inst = {}
	inst.pos = vec3()
	inst.pos.x = 0
	inst.pos.y = 0
	inst.half = vec3()
	inst.half.x = 32
	inst.half.y = 32
	inst.tex_half = vec3()
	inst.tex_half.x = 32
	inst.tex_half.y = 32
	function inst:Move(x, y)
		if x ~= 0 or y ~= 0 then
			self.pos.x = self.pos.x + x
			self.pos.y = self.pos.y + y
		end
	end
	function inst:DebugInfo()
		print("Transform: (" .. self.pos.x .. " "..self.pos.y..")")
	end
	inst.texture = CreateTexture("res/textures/test.png")
	entity:AddListener("OnRender", OnRender)
	return inst
end

return Prefab("transform", fn)