#shader vertex
#version 330 core

layout(location = 0)in vec4 position;
layout(location = 1)in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_MVP;

void main()
{
	vec4 res = u_MVP * position;
	res.z = 0.0;
	gl_Position = res;
	v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

layout(location = 0)out vec4 color;

in vec2 v_TexCoord;

uniform vec3 u_Color;
uniform sampler2D u_Texture;
uniform float x_mul;
uniform float y_mul;

void main()
{
	if (v_TexCoord.x > x_mul)
		discard;
	if (v_TexCoord.y > y_mul)
		discard;
	vec4 texColor = texture(u_Texture, v_TexCoord) * vec4(u_Color, 1.0f);
	color = texColor;
	if (texColor.a < 0.3)
		discard;
};