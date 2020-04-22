/**
 * MyCubeMap
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyCubeMap extends CGFobject {
	constructor(scene) {
		super(scene);
        this.quad = new MyQuad(this.scene);
		this.filter = this.scene.gl.LINEAR;
	}

    display() {
    /*    this.scene.pushMatrix();

        // ---- Bottom Face
        this.scene.translate(0, 0, -0.5);
		if (typeof this.bottomMaterial != "undefined") {
			this.bottomMaterial.apply();
		}
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Upper Face
        this.scene.translate(0, 0, 0.5);
        this.scene.rotate(Math.PI, 0, 1, 0);
		if (typeof this.upperMaterial != "undefined") {
			this.upperMaterial.apply();
		}
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Front Face
        this.scene.translate(0.5, 0, 0);
        this.scene.rotate(-Math.PI/2, 0, 1, 0);
		if (typeof this.frontMaterial != "undefined") {
			this.frontMaterial.apply();
		}
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Back Face
        this.scene.translate(-0.5, 0, 0);
        this.scene.rotate(Math.PI/2, 0, 1, 0);
		if (typeof this.backMaterial != "undefined") {
			this.backMaterial.apply();
		}
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
        this.quad.display();
        // ----

        this.scene.popMatrix();*/
        this.scene.pushMatrix();

        // ---- Left Face
    	this.scene.translate(0, -0.5, 0);
        this.scene.rotate(-Math.PI/2, 1, 0, 0);
		if (typeof this.leftMaterial != "undefined") {
			this.leftMaterial.apply();
		}
		this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
        this.quad.display();
        // ----

        this.scene.popMatrix();/*
        this.scene.pushMatrix();

        // ---- Right Face
    /*    this.scene.translate(0, 0.5, 0);
        this.scene.rotate(-Math.PI/2, 1, 0, 0);
		if (typeof this.rightMaterial != "undefined") {
			this.scene.gl.texParameteri(this.scene.gl.TEXTURE_2D, this.scene.gl.TEXTURE_MAG_FILTER, this.filter);
			this.rightMaterial.apply();
		}
        this.quad.display();
        // ----

        this.scene.popMatrix();*/
    }

	/**
	 * @method changeMaterial
	 * Changes material of face specified
	 * 			Faces:
	 *				0 - Bottom
	 *				1 - Upper
	 *				2 - Front
	 *				3 - Back
	 *				4 - Left
	 *				5 - Right
	 *			Material:
	 *				CGFappearance object
	 *				To remove material pass material as undefined
	 * @param face - Face to change material
	 * @param material - Material to set to
	 */
	changeMaterial(face, material) {
		switch (face) {
			case 0:
				this.bottomMaterial = material;
				break;
			case 1:
				this.upperMaterial = material;
				break;
			case 2:
				this.frontMaterial = material;
				break;
			case 3:
				this.backMaterial = material;
				break;
			case 4:
				this.leftMaterial = material;
				break;
			case 5:
				this.rightMaterial = material;
				break;
			default:
				return;
		}
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
