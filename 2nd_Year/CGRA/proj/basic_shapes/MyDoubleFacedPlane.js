/**
 * MyDoubleFacedPlane - double faced plane
 *
 * @see MyPlane
 *
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyDoubleFacedPlane extends CGFobject{
	constructor(scene, nrDivs, minS, maxS, minT, maxT) {
		super(scene);
		// nrDivs = 1 if not provided
		nrDivs = typeof nrDivs !== 'undefined' ? nrDivs : 1;
		this.nrDivs = nrDivs;
		this.patchLength = 1.0 / nrDivs;
		this.minS = minS || 0;
		this.maxS = maxS || 1;
		this.minT = minT || 0;
		this.maxT = maxT || 1;
		this.q = (this.maxS - this.minS) / this.nrDivs;
		this.w = (this.maxT - this.minT) / this.nrDivs;
		this.initBuffers();
	}
	/**
     * Initialize vertices, normals, texture coordinates and indices of the circle
     */
	initBuffers() {
		// Generate vertices, normals, and texCoords
		this.vertices = [];
		this.normals = [];
		this.texCoords = [];
		var yCoord = 0.5;
		for (var j = 0; j <= this.nrDivs; j++) {
			var xCoord = -0.5;
			for (var i = 0; i <= this.nrDivs; i++) {
                this.vertices.push(xCoord, yCoord, 0);
				this.vertices.push(xCoord, yCoord, 0);
                this.normals.push(0, 0, 1);
				this.normals.push(0, 0, -1);
                this.texCoords.push(this.minS + i * this.q, this.minT + j * this.w);
				this.texCoords.push(this.minS + (this.nrDivs - i) * this.q, this.minT + j * this.w);
				xCoord += this.patchLength;
			}
			yCoord -= this.patchLength;
		}
		// Generating indices
		this.indices = [];

		var ind = 0;
		for (var j = 0; j < this.nrDivs; j++) {
			for (var i = 0; i < this.nrDivs; i++) {
				// Front Face
				this.indices.push(ind * 2, (ind + this.nrDivs + 1) * 2, (ind + this.nrDivs + 2) * 2);
				this.indices.push((ind) * 2, (ind + this.nrDivs + 2) * 2, (ind + 1) * 2);
				// Back face
				this.indices.push((ind + this.nrDivs + 1) * 2 + 1, ind * 2 + 1, (ind + this.nrDivs + 2) * 2 + 1);
				this.indices.push((ind + this.nrDivs + 2) * 2 + 1, (ind) * 2 + 1, (ind + 1) * 2 + 1);
				ind++;
			}
			ind++;
		}
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
