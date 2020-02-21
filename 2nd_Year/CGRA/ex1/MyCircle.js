/**
 * MyCircle
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyCircle extends CGFobject {
    constructor(scene, radius, centerX, centerY, centerZ) {
        super(scene);
        this.radius = radius;
        this.centerX = centerX;
        this.centerY = centerY;
        this.centerZ = centerZ;
        this.initBuffers();
    }

    initBuffers() {
        this.noVertices = 100;

        this.vertices = [
            this.centerX, this.centerY, this.centerZ
        ];

        var dangle = (Math.PI * 2)/this.noVertices, angle = 0;
        var x, y;

        for (var i = 0; i < this.noVertices; i++) {
            x = this.centerX + Math.cos(angle) * this.radius;
            y = this.centerY + Math.sin(angle) * this.radius;

            this.vertices.push(x); this.vertices.push(y); this.vertices.push(this.centerZ);

            angle += dangle;
        }

        this.indices = [
        ];

        for (var i = 1; i <= this.noVertices; i++) {
            this.indices.push(i);
            this.indices.push(1 + i % this.noVertices);
            this.indices.push(0); // center
        }

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
