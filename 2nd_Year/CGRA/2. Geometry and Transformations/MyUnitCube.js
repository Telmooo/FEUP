/**
 * MyUnitCube
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyUnitCube extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
	}
	initBuffers() {
        /*
               H---------G
             / |        /|
            /  |       / |
            E--------F   |
            |  |     |   |
            |  D-----|---C
            | /      |  /
            |/       | /
         0->A--------B
        */
		this.vertices = [
            // ---- Bottom face
			0, 0, 0,	// A (0)
			1, 0, 0,	// B (1)
			1, 1, 0,	// C (2)
			0, 1, 0,	// D (3)


            // ---- Upper face
			0, 0, 1,	// E (4)
			1, 0, 1,	// F (5)
			1, 1, 1,	// G (6)
			0, 1, 1     // H (7)
		];

		// Counter-clockwise reference of vertices
		this.indices = [
			// ---- Bottom face
            0, 2, 1,
            0, 3, 2,

            // ---- Upper face
            4, 5, 6,
            4, 6, 7,

            // ---- Front face
            0, 1, 5,
            0, 5, 4,

            // ---- Back face
            3, 6, 2,
            3, 7, 6,

            // ---- Left face
            0, 4, 3,
            4, 7, 3,

            // ---- Right face
            1, 2, 5,
            2, 6, 5
		];

		// The defined indices (and corresponding vertices)
		// will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}
}
