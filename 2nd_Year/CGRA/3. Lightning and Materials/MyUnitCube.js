/**
 * MyUnitCube
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyUnitCube extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
        this.initNormalVizBuffers();
	}
	initBuffers() {
        /*
               H---------G
             / |        /|
            /  |       / |
            E--------F   |
            |  |  0  |   |
            |  D-----|---C
            | /      |  /
            |/       | /
         0->A--------B
        */

		this.vertices = [];
		this.normals = [];

		for (let i = 0; i < 8; i++) {
			let x = 0.5, y = 0.5, z = 0.5;
			if ((i % 4) >= 2) x *= -1;
			if (((i + 1) % 4) < 2) y *= -1;
			if (i < 4) z *= -1;

			this.vertices.push(x, y, z); // X normal
			this.vertices.push(x, y, z); // Y normal
			this.vertices.push(x, y, z); // Z normal

			this.normals.push(((x < 0) ? -1 : 1), 0, 0); // X normal
			this.normals.push(0, ((y < 0) ? -1 : 1), 0); // Y normal
			this.normals.push(0, 0, ((z < 0) ? -1 : 1)); // Z normal
		}

		/*
			Vertices (A=0, B=1, ..., H=7) to get the real vertice on the array multiply by 3
			Access vertice with X normal with offset=0
			Access vertice with Y normal with offset=1
			Access vertice with Z normal with offset=2
		*/
		this.indices = [
			// ---- Bottom face (z normal)
            2, 8, 5,	// A->C->B
            2, 11, 8,	// A->D->C

            // ---- Upper face (z normal)
            14, 17, 20,	// E->F->G
            14, 20, 23,	// A->G->H

            // ---- Front face (y normal)
            1, 4, 16,	// A->B->F
            1, 16, 13,	// A->F->E

            // ---- Back face (y normal)
            10, 19, 7,	// D->G->C
            10, 22, 19,	// D->H->G

            // ---- Left face (x normal)
            0, 12, 9,	// A->E->C
            12, 21, 9,	// E->H->C

            // ---- Right face (x normal)
            3, 6, 15,	// B->C->F
            6, 18, 15	// C->G->F
		];

		// The defined indices (and corresponding vertices)
		// will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}
}
