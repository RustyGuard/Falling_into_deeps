#shader vertex
#version 330 core

layout(location = 0)in vec4 position;
layout(location = 1)in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_MVP;
uniform float z_coord;

void main()
{
	vec4 res = u_MVP * position;
	res.z = z_coord;
	//res.x = res.x * 0.5;
	gl_Position = res;
	v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

layout(location = 0)out vec4 color;

in vec2 v_TexCoord;

uniform vec3 u_Color;
uniform float u_Time;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord) * vec4(u_Color, 1.0f) * vec4(u_Time, -u_Time, -u_Time, 1.0f);
	color = texColor;
	if (texColor.a < 0.3)
		discard;
};