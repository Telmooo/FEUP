/**
 * MyTriangle
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTriangle extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }
    initBuffers() {
        /*
            C
            | \
            A - B
        */
        this.vertices = [
            -1, -1, 0,  // A (0)
            1, -1, 0,   // B (1)
            -1, 1, 0    // C (2)
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 2
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
