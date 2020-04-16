attribute vec3 aVertexPosition;
attribute vec3 aVertexNormal;
attribute vec2 aTextureCoord;

uniform mat4 uMVMatrix;
uniform mat4 uPMatrix;
uniform mat4 uNMatrix;

uniform sampler2D uSampler4;

varying vec2 vTextureCoord;

uniform float timeFactor;

void main() {

    vTextureCoord = aTextureCoord;

    vec3 offset = aVertexNormal * texture2D(uSampler4, vTextureCoord + vec2(timeFactor, timeFactor) * 0.01).r;

    gl_Position = uPMatrix * uMVMatrix * vec4(aVertexPosition + 0.075 * offset, 1.0);

}
