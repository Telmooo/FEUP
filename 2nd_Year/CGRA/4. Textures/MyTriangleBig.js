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
            A - 0 - B
        */
        this.vertices = [
            -2, 0, 0,   // A (0)
            2, 0, 0,    // B (1)
            0, 2, 0     // C (2)
        ];

        this.indices = [
            0, 1, 2
        ];

        this.normals = [
			0, 0, 1,
			0, 0, 1,
			0, 0, 1
		];

        this.texCoords = [
            0.0, 1.0,
            1.0, 1.0,
            0.5, 0.0
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
