/**
 * MyQuad
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
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

		this.normals = [
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,
			0, 0, 1
		];

		/*
		Texture coords (s,t)
		+----------> s
        |
        |
		|
		v
        t
        */

		this.texCoords = [
			0, 1,	// Bottom Left 	(A)
			1, 1,	// Bottom Right (B)
			1, 0,	// Top Right 	(C)
			0, 0	// Top Left 	(D)
		];

		// The defined indices (and corresponding vertices)
		// will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}

	setFillMode() {
		this.primitiveType=this.scene.gl.TRIANGLES;
	}

	setLineMode() {
		this.primitiveType=this.scene.gl.LINES;
	};
}
