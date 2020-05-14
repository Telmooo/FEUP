/**
 * MyCubeMapVert
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyCubeMapVert extends CGFobject {
	constructor(scene) {
		super(scene);
		this.initBuffers();
        this.initNormalVizBuffers();
		this.filter = this.scene.gl.LINEAR;
		this.initMaterials();
	}

	initMaterials() {
		this.material = new CGFappearance(this.scene);
		this.material.setAmbient(1.0, 1.0, 1.0, 1.0);
        this.material.setDiffuse(0.0, 0.0, 0.0, 1.0);
        this.material.setSpecular(0.0, 0.0, 0.0, 1.0);
        this.material.setShininess(10.0);
        this.material.setTextureWrap('REPEAT', 'REPEAT');
	}
	initBuffers() {
        /*
               H---------G
             / |        /|                      y
            /  |       / |                      |
            E--------F   |                      |
            |  |  0  |   |                      |
            |  D-----|---C                      |------x
            | /      |  /                      /
            |/       | /                      /
         0->A--------B                       z
        */

		this.vertices = [];
		this.normals = [];

		for (let i = 0; i < 8; i++) {
			let x = 0.5, y = 0.5, z = 0.5;
			if (((i + 1) % 4) < 2) x *= -1;
			if (i < 4) y *= -1;
			if ((i % 4) >= 2) z *= -1;

			this.vertices.push(x, y, z); this.normals.push(((x > 0) ? -1 : 1), 0, 0); // X normal
			this.vertices.push(x, y, z); this.normals.push(0, ((y > 0) ? -1 : 1), 0); // Y normal
			this.vertices.push(x, y, z); this.normals.push(0, 0, ((z > 0) ? -1 : 1)); // Z normal

            /*
    			Vertices (A=0, B=1, ..., H=7) to get the real vertice on the array multiply by 3
    			Access vertice with X normal with offset=0
    			Access vertice with Y normal with offset=1
    			Access vertice with Z normal with offset=2
            */
		}
		this.indices = [
            // Interior faces
            // ---- Left face (x normal) (negative)
            0, 9, 21, // A->D->H
            0, 21, 12, // A->H->E

            // ---- Right face (x normal) (positive)
            15, 18, 6, // F->G->C
            15, 6, 3, // F->C->B

			// ---- Bottom face (y normal) (negative)
            1, 4, 7, // A->B->C
            1, 7, 10, // A->C->D

            // ---- Upper face (y normal) (positive)
            13, 19, 16, // E->G->F
            13, 22, 19, // E->H->G

            // ---- Back face (z normal) (negative)
            11, 8, 20, // D->C->G
            11, 20, 23, // D->G->H

            // ---- Front face (z normal) (positive)
            2, 14, 17,  // A->E->F
            2, 17, 5 // A->F->B
		];

        this.texCoords = [
			// A
            0.0, 2/3,  // X normal
            0.25, 1.0,  // Y normal
            1.0, 2/3,  // Z normal

            // B
            0.75, 2/3, // X normal
            0.5, 1.0,   // Y normal
            0.75, 2/3, // Z normal


            // C
            0.5, 2/3,  // X normal
            0.5, 2/3,  // Y normal
            0.5, 2/3,  // Z normal


            // D
            0.25, 2/3, // X normal
            0.25, 2/3, // Y normal
            0.25, 2/3, // Z normal


            // E
            0.0, 1/3,  // X normal
            0.25, 0.0,  // Y normal
            1.0, 1/3,  // Z normal


            // F
            0.75, 1/3, // X normal
            0.5, 0.0,   // Y normal
            0.75, 1/3, // Z normal


            // G
            0.5, 1/3,  // X normal
            0.5, 1/3,  // Y normal
            0.5, 1/3,  // Z normal


            // H
            0.25, 1/3, // X normal
            0.25, 1/3, // Y normal
            0.25, 1/3, // Z normal


        ];

		// The defined indices (and corresponding vertices)
		// will be read in groups of three to draw triangles
		this.primitiveType = this.scene.gl.TRIANGLES;

		this.initGLBuffers();
	}

	display() {
		this.material.apply();
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
		super.display();
	}

	/**
	 * @method changeMaterial
	 * Changes texture of faces
	 * 			Faces:
	 *				0 - Bottom
	 *				1 - Upper
	 *				2 - Front
	 *				3 - Back
	 *				4 - Left
	 *				5 - Right
	 *			Texture:
	 *				CGFtexture object
	 *				To remove material pass material as null
	 * @param texture - array of textures
	 */
	loadTexture(texture) {
		this.material.setTexture(texture);
	}

	/**
	 * @method changeFilter
	 * Changes filter
	 * 			Filter:
	 *				0 - Linear
	 *				1 - Nearest
	 * @param face - Face to change material
	 * @param material - Material to set to
	 */
	changeFilter(filter) {
		switch (filter) {
			case '0':
				this.filter = this.scene.gl.LINEAR;
				break;
			case '1':
				this.filter = this.scene.gl.NEAREST;
				break;
			default:
				this.filter = this.scene.gl.LINEAR;
				break;
		}
	}

	setFillMode() {
		this.primitiveType=this.scene.gl.TRIANGLES;
	}

	setLineMode() {
		this.primitiveType=this.scene.gl.LINES;
	};
}
