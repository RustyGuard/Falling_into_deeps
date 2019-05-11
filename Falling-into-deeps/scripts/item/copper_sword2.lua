local inst = {}

inst.texture = CreateTexture("res/textures/items/copper_sword.png")

function inst:OnMouseButtonReleased(stack, b, p)
	if b == 0 then
		local en = GetByPoint(p)
		if en then
			return en:PushEvent("attack", 5)
		else
			print("Attack on ground: " .. p.x .. " " .. p.y)
		end
		return true
	end
	return false
end

return inst