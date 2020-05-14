attribute vec3 aVertexPosition;
attribute vec3 aVertexNormal;
attribute vec2 aTextureCoord;

uniform mat4 uMVMatrix;
uniform mat4 uPMatrix;
uniform mat4 uNMatrix;

varying vec2 vTextureCoord;

uniform float instant;
uniform float amplitude;
uniform float instantFactor;
uniform float lengthFactor;
uniform float offset;

void main() {
    vTextureCoord = aTextureCoord;
    vec3 offset = vec3(0, 0, 1) * amplitude * sin(instantFactor * instant + lengthFactor * (offset + (aVertexPosition.x + 0.5)));
    gl_Position = uPMatrix * uMVMatrix * vec4(aVertexPosition + offset, 1.0);
}
