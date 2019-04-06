
#version 150

in vec2 texCoordVarying;

out vec4 outputColor;

float random2d(vec2 n) {
    return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

void main()
{
    
    outputColor = vec4(1.);
}
