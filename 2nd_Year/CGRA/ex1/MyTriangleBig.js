/**
 * MyTriangleBig
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTriangleBig extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }

    initBuffers() {
        /*
                C
              /   \
             /     \
            A - - - B
        */
        this.vertices = [
            -2, 0, 0,   // A (0)
            2, 0, 0,    // B (1)
            0, 2, 0     // C (2)
        ];

        this.indices = [
            0, 1, 2
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
