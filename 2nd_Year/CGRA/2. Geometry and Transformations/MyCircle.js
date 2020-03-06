/**
 * MyCircle
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyCircle extends CGFobject {
    constructor(scene, nVertices, radius, centerX, centerY, centerZ) {
        super(scene);
        this.nVertices = nVertices;
        this.radius = radius;
        this.centerX = centerX;
        this.centerY = centerY;
        this.centerZ = centerZ;
        this.initBuffers();
    }

    initBuffers() {

        this.vertices = [
            this.centerX, this.centerY, this.centerZ
        ];

        var dangle = (Math.PI * 2)/this.nVertices, angle = 0;
        var x, y;

        for (var i = 0; i < this.nVertices; i++) {
            x = this.centerX + Math.cos(angle) * this.radius;
            y = this.centerY + Math.sin(angle) * this.radius;

            this.vertices.push(x); this.vertices.push(y); this.vertices.push(this.centerZ);

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
