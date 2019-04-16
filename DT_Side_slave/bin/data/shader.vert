// dummy vertex shader
#version 410

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;

out vec2 varyingTexcoord;

void main() {
    
    varyingTexcoord = texcoord;
    gl_Position = modelViewProjectionMatrix * position;
    
}
