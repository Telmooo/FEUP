/**
 * MyParallelogram
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyParallelogram extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }
    initBuffers() {
        /*
                D - - - C
              / |   | /
          0->A - - - B
        */
        this.vertices = [
            0, 0, 0,    // A (0)
            2, 0, 0,    // B (1)
            3, 1, 0,    // C (2)
            1, 1, 0     // D (3)
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 3,
            1, 2, 3
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
