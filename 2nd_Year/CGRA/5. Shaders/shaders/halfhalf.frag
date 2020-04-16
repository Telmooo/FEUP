#ifdef GL_ES
precision highp float;
#endif

varying vec4 position;

void main() {
    vec4 blue = vec4(0.0, 0.0, 1.0, 1.0);
    vec4 yellow = vec4(1.0, 1.0, 0.0, 1.0);
    gl_FragColor = (position.y > 0.5) ? yellow : blue;
}
