#ifdef GL_ES
precision highp float;
#endif

varying vec2 vTextureCoord;

uniform sampler2D uSampler3;
uniform sampler2D uSampler4;

uniform float timeFactor;

void main() {

    vec4 color = texture2D(uSampler3, vTextureCoord + vec2(timeFactor, timeFactor) * 0.01);

    gl_FragColor = color;
}
