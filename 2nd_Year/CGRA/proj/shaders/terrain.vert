attribute vec3 aVertexPosition;
attribute vec3 aVertexNormal;
attribute vec2 aTextureCoord;

uniform mat4 uMVMatrix;
uniform mat4 uPMatrix;
uniform mat4 uNMatrix;

varying vec2 vTextureCoord;

uniform sampler2D uSampler3;
uniform float maxHeight;

void main() {
	vTextureCoord = aTextureCoord;
	vec3 offset = aVertexNormal * texture2D(uSampler3, vTextureCoord).r;
	gl_Position = uPMatrix * uMVMatrix * vec4(aVertexPosition + maxHeight * offset, 1.0);
}
