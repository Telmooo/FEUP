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

        this.texCoords = [
            1.0, 1.0,
            0.67, 0.0,
            0.0, 0.0,
            0.33, 1.0
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }

    /**
	 * @method updateTexCoords
	 * Updates the list of texture coordinates of the quad
	 * @param {Array} coords - Array of texture coordinates
	 */
	updateTexCoords(coords) {
		this.texCoords = [...coords];
		this.updateTexCoordsGLBuffers();
	}
}
