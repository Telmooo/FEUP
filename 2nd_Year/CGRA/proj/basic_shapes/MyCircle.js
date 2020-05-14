/**
 * MyCircle - double faced circle
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyCircle extends CGFobject {
    constructor(scene, nVertices) {
        super(scene);
        this.nVertices = nVertices;
        this.initBuffers();
    }

    /**
     * Initialize vertices, normals, texture coordinates and indices of the circle
     */
    initBuffers() {

        this.vertices = [ ];
        this.normals = [ ];
        this.texCoords = [ ];
        this.indices = [ ];


        var dangle = (Math.PI * 2)/this.nVertices, angle = 0;
        var x, y;

        for (var i = 0; i < this.nVertices; i++) {
            x = Math.cos(angle);
            y = Math.sin(angle);

            // Front
            this.vertices.push(x, y, 0);
            this.normals.push(0, 0, 1);
            this.texCoords.push(0.5 + x / 2, 1 - (0.5 + y / 2));
            this.indices.push(i * 2, ((i + 1) * 2) % (this.nVertices * 2), this.nVertices * 2);

            // Back
            this.vertices.push(x, y, 0);
            this.normals.push(0, 0, -1);
            this.texCoords.push(1 - (0.5 + x / 2), 1 - (0.5 + y / 2));
            this.indices.push(((i + 1) * 2 + 1) % (this.nVertices * 2), i * 2 + 1, this.nVertices * 2 + 1);

            angle += dangle;
        }

        this.vertices.push(0, 0, 0);    this.vertices.push(0, 0, 0);
        this.normals.push(0, 0, 1);     this.normals.push(0, 0, -1);
        this.texCoords.push(0.5, 0.5);  this.texCoords.push(0.5, 0.5);

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
