/**
 * MyCubeMap
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyCubeMap extends CGFobject {
	constructor(scene) {
		super(scene);
	    this.quad = new MyQuad(this.scene);
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

    display() {
		this.scene.pushMatrix();

		// ---- Bottom Face
		this.scene.translate(0, -0.5, 0);
		this.scene.rotate(-Math.PI/2, 1, 0, 0);
		this.material.setTexture(this.bottomTexture);
		this.material.apply();
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
		this.quad.display();
		// ----

		this.scene.popMatrix();

		this.scene.pushMatrix();

		// ---- Upper Face
		this.scene.translate(0, 0.5, 0);
		this.scene.rotate(Math.PI/2, 1, 0, 0);
		this.material.setTexture(this.upperTexture);
		this.material.apply();
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
		this.quad.display();
		// ----

		this.scene.popMatrix();

		this.scene.pushMatrix();

		// ---- Front Face
		this.scene.translate(0, 0, 0.5);
		this.scene.rotate(Math.PI, 0, 1, 0);
		this.material.setTexture(this.frontTexture);
		this.material.apply();
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
		this.quad.display();
		// ----

		this.scene.popMatrix();

		this.scene.pushMatrix();

		// ---- Back Face
		this.scene.translate(0, 0, -0.5);
		this.material.setTexture(this.backTexture);
		this.material.apply();
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
		this.quad.display();
		// ----

		this.scene.popMatrix();

		this.scene.pushMatrix();

		// ---- Left Face
		this.scene.translate(0.5, 0, 0);
		this.scene.rotate(-Math.PI/2, 0, 1, 0);
		this.material.setTexture(this.leftTexture);
		this.material.apply();
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
		this.quad.display();
		// ----

		this.scene.popMatrix();

		this.scene.pushMatrix();

		// ---- Right Face
		this.scene.translate(-0.5, 0, 0);
		this.scene.rotate(Math.PI/2, 0, 1, 0);
		this.material.setTexture(this.rightTexture);
		this.material.apply();
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
		this.quad.display();
		// ----

		this.scene.popMatrix();
    }

	enableNormalViz() {
		this.quad.enableNormalViz();
	}

	disableNormalViz() {
		this.quad.disableNormalViz();
	}

	setFillMode() {
		this.quad.setFillMode();
	}

	setLineMode() {
		this.quad.setLineMode();
	};

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
		this.bottomTexture = texture[0];
		this.upperTexture = texture[1];
		this.frontTexture = texture[2];
		this.backTexture = texture[3];
		this.leftTexture = texture[4];
		this.rightTexture = texture[5];
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
}
