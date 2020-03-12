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
            C - F - - B
              \ |     | \
                D - - E - A <- 0
        */
        this.vertices = [
            0, 0, 0,    // A (0)
            -1, 1, 0,    // B (1)
            -3, 1, 0,    // C (2)
            -2, 0, 0    // D (3)
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 2,
            0, 2, 3
        ];

        this.normals = [
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,
			0, 0, 1
		];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
