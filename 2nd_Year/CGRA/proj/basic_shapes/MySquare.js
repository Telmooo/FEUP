/**
 * MySquare - double faced quad
 *
 * @see MyQuad
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MySquare extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
	}
	initBuffers() {
        /*
        Double Sided Quad
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
			-0.5, 0.5, 0,	// D (3)
            -0.5, -0.5, 0,	// A' (4)
			0.5, -0.5, 0,	// B' (5)
			0.5, 0.5, 0,	// C' (6)
			-0.5, 0.5, 0	// D' (7)
		];

		// Counter-clockwise reference of vertices
		this.indices = [
			0, 1, 2,
            0, 2, 3,
            4, 6, 5,
            4, 7, 6
		];

		this.normals = [
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,
            0, 0, -1,
			0, 0, -1,
			0, 0, -1,
			0, 0, -1
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
            // Front Face
			0, 1,	// Bottom Left 	(A)
			1, 1,	// Bottom Right (B)
			1, 0,	// Top Right 	(C)
			0, 0,	// Top Left 	(D)
            // Back Face
            0, 1,	// Bottom Right (A')
			1, 1,	// Bottom Left  (B')
			1, 0,	// Top Left 	(C')
			0, 0,	// Top Right 	(D')
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

	setFillMode() {
        this.primitiveType=this.scene.gl.TRIANGLES;
    }

    setLineMode() {
        this.primitiveType=this.scene.gl.LINES;
    };
}
