/**
 * MyCircle
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyCircle extends CGFobject {
    constructor(scene, nVertices) {
        super(scene);
        this.nVertices = nVertices;
        this.initBuffers();
    }

    initBuffers() {

        this.vertices = [
            0, 0, 0
        ];


        this.normals = [ 0, 0, 1 ];
        this.texCoords = [ 0.5, 0.5 ];

        var dangle = (Math.PI * 2)/this.nVertices, angle = 0;
        var x, y;

        for (var i = 0; i < this.nVertices; i++) {
            x = Math.cos(angle);
            y = Math.sin(angle);

            this.vertices.push(x, y, 0);
            this.normals.push(0, 0, 1);
            this.texCoords.push(0.5 + x / 2, 0.5 + y / 2);

            angle += dangle;
        }

        this.indices = [
        ];

        for (var i = 1; i <= this.nVertices; i++) {
            this.indices.push(i);
            this.indices.push(1 + i % this.nVertices);
            this.indices.push(0); // center
        }

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
