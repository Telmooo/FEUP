#ifdef GL_ES
precision highp float;
#endif

varying vec2 vTextureCoord;

uniform float percent;

void main() {
    vec4 color;
    if (vTextureCoord.s < percent) {
        vec4 red = vec4(1.0, 0.0, 0.0, 1.0);
        vec4 green = vec4(0.0, 1.0, 0.0, 1.0);
        color = mix(red, green, vTextureCoord.s);
    } else {
        color = vec4(0.5, 0.5, 0.5, 1.0);
    }

    gl_FragColor = color;
}
