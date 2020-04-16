attribute vec3 aVertexPosition;
attribute vec3 aVertexNormal;

uniform mat4 uMVMatrix;
uniform mat4 uPMatrix;
uniform mat4 uNMatrix;

varying vec4 position;

void main() {
    vec4 pos = uPMatrix * uMVMatrix * vec4(aVertexPosition, 1.0);
    gl_Position = position = pos;
}
