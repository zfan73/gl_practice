#shader vertex
#version 400 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 a_color;
layout(location = 2) in vec2 texCoord;
layout(location = 3) in float texIndex;

out vec2 v_TexCoord;
out vec4 v_color;
out float v_TexIndex;
uniform mat4 u_MVP;

void main()
{
   gl_Position = u_MVP * position;
   v_color = a_color;
   v_TexCoord = texCoord;
   v_TexIndex = texIndex;
}

#shader fragment
#version 400 core
layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
in float v_TexIndex;
uniform sampler2D u_Texure[2];

void main()
{
   int index = int(v_TexIndex);
   color = texture(u_Texure[index], v_TexCoord);
}