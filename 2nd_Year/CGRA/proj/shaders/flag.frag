#ifdef GL_ES
precision highp float;
#endif

varying vec2 vTextureCoord;

uniform sampler2D flagTextureSampler;

void main() {
    vec4 color = texture2D(flagTextureSampler, vTextureCoord);
    gl_FragColor = color;
}
