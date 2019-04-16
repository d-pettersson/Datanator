
#version 150

in vec2 texCoordVarying;

uniform sampler2DRect texDisplacement;

uniform float time;

out vec4 outputColor;

float POWER = 0.04; // How much the effect can spread horizontally
float VERTICAL_SPREAD = 50.; // How vertically is the sin wave spread
float ANIM_SPEED = 0.4f; // Animation speed

//2D (returns 0 - 1)
float random2d(vec2 n) {
    return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

float randomRange (in vec2 seed, in float min, in float max) {
    return min + random2d(seed) * (max - min);
}

void main() {
    
    vec2 tc = gl_FragCoord.xy;
    
    vec2 offset = vec2(random2d(vec2(5., time*.001))*10., vec2(0., 0.));
    
    float y = (tc.y + time * ANIM_SPEED) * VERTICAL_SPREAD;
    
    tc.x += (
                          // This is the heart of the effect, feel free to modify
                          // The sin functions here or add more to make it more complex
                          // and less regular
                          sin(y)
                          + sin(y * 10.0) * 0.2
                          + sin(y * 50.0) * 0.03
                          )
    * POWER // Limit by maximum spread
    * sin(tc.y * 3.14) // Disable on edges / make the spread a bell curve
    * sin(time); // And make the power change in time
    
    vec4 tex = texture(texDisplacement, tc);
    tex.gb += texture(texDisplacement, tc + offset).gb;
    tex.r = texture(texDisplacement, tc + offset * -.2).r;
    
    outputColor = tex;
}
