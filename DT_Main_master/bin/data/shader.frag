
#version 150

in vec2 texcoordVarying;

uniform sampler2DRect texKinect;
uniform float time;
uniform vec2 texSize;
uniform vec2 texKinectSize;

out vec4 outputColor;

void main()
{
    vec2 tc = texcoordVarying;
    vec2 ratio = tc / texSize * texKinectSize;
    
    vec4 texel = texture(texKinect, ratio);
    texel = vec4(vec3(texel.rgb * 2.), texel.a);
    
    outputColor = texel;
}
