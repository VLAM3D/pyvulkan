// From:
// C:\VulkanSDK\1.0.3.1\Samples\API-Samples\template\template.cpp
#version 400
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable
layout (std140, binding = 0) uniform buf {
        mat4 mvp;
} ubuf;

layout (location = 0) in vec4 pos;
layout (location = 1) in vec2 inTexCoords;
layout (location = 0) out vec2 texcoord;
out gl_PerVertex { 
    vec4 gl_Position;
};
void main() {
   texcoord = inTexCoords;
   gl_Position = ubuf.mvp * pos;

   // GL->VK conventions
   gl_Position.y = -gl_Position.y;
   gl_Position.z = (gl_Position.z + gl_Position.w) / 2.0;
}