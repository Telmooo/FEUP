/**
 * MyDiamond
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyDiamond extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
	}
	initBuffers() {
        /*
                D
              /   \
             /     \
            A   0   C
             \     /
              \   /
                B
        */
		this.vertices = [
			-1, 0, 0,	// A (0)
			0, -1, 0,	// B (1)
			1, 0, 0,	// C (2)
			0, 1, 0		// D (3)
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
			0.0, 0.5,
			0.5, 1.0,
			1.0, 0.5,
			0.5, 0.0
		];

		// The defined indices (and corresponding vertices)
		// will be read in groups of three to draw triangles
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
