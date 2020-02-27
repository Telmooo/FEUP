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
                C
              /   \
             /     \
            A   0   D
             \     /
              \   /
                B
        */
		this.vertices = [
			-1, 0, 0,	// A (0)
			0, -1, 0,	// B (1)
			0, 1, 0,	// C (2)
			1, 0, 0		// D (3)
		];

		// Counter-clockwise reference of vertices
		this.indices = [
			0, 1, 2,
			1, 3, 2
		];

		// The defined indices (and corresponding vertices)
		// will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}
}
