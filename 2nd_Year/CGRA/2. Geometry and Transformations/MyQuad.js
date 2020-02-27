/**
 * MyQuad
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyQuad extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
	}
	initBuffers() {
        /*
            D - - - C
            |       |
			|	0	|
            |       |
            A - - - B
        */
		this.vertices = [
			-0.5, -0.5, 0,	// A (0)
			0.5, -0.5, 0,	// B (1)
			0.5, 0.5, 0,	// C (2)
			-0.5, 0.5, 0	// D (3)
		];

		// Counter-clockwise reference of vertices
		this.indices = [
			0, 1, 2,
            0, 2, 3
		];

		// The defined indices (and corresponding vertices)
		// will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}
}
