#shader vertex
#version 330 core

layout(location = 0)in vec4 position;
layout(location = 1)in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_MVP;
uniform float x_mul;
uniform float y_mul;

void main()
{
	vec4 res = u_MVP * position;
	res.z = 0.0;
	gl_Position = res;
	vec2 t = texCoord;
	t.x = t.x * x_mul;
	t.y = t.y * y_mul;
	v_TexCoord = t;
};

#shader fragment
#version 330 core

layout(location = 0)out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
	if (texColor.a < 0.3)
		discard;
};