/**
 * MyCylinder
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyCylinder extends CGFobject {
    constructor(scene, slices) {
        super(scene);
        this.slices = slices;
        this.initBuffers();
    }

    /**
     * Initialize vertices, normals, texture coordinates and indices of the circle
     */
    initBuffers() {
        this.vertices = [];
        this.indices = [];
        this.normals = [];
        this.texCoords = [];

        var dangle = (Math.PI * 2) / this.slices, angle = 0;
        var x, z;
        var dTexCoord = 1 / this.slices, texCoord = 1;

        for (let i = 0; i <= this.slices; i++) {
            x = Math.cos(angle);
            z = Math.sin(angle);

            this.vertices.push(x, 0, z);
            this.vertices.push(x, 1, z);

            // indices -- clockwise
            this.indices.push(i * 2, (i * 2 + 1) % ((this.slices + 1) * 2), (i * 2 + 2) % ((this.slices + 1) * 2));
            this.indices.push((i * 2 + 1) % ((this.slices + 1) * 2), (i * 2 + 3) % ((this.slices + 1) * 2), (i * 2 + 2) % ((this.slices + 1) * 2));

            // normals
            this.normals.push(x, 0, z);
            this.normals.push(x, 0, z);

            // texcoords
            this.texCoords.push(texCoord, 1);
            this.texCoords.push(texCoord, 0);

            angle += dangle;
            texCoord -= dTexCoord;
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
