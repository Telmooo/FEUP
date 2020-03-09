/**
 * MyCylinderVert
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyCylinderVert extends CGFobject {
    constructor(scene, nVertices, radius, centerBX, centerBY, centerBZ, height) {
        super(scene);
        this.nVertices = nVertices;
        this.radius = radius;
        this.centerBX = centerBX;
        this.centerBY = centerBY;
        this.centerBZ = centerBZ;
        this.height = height;
        this.circle = new MyCircle(this.scene, this.nVertices, this.radius, this.centerBX, this.centerBY, this.centerBZ);
        this.quad = new MyQuad(this.scene);
        this.initBuffers();
    }

    initBuffers() {
        this.vertices = [
            this.centerBX, this.centerBY, this.centerBZ - this.height/2,
            this.centerBX, this.centerBY, this.centerBZ + this.height/2
        ];

        var dangle = (Math.PI * 2) / this.nVertices, angle = 0;
        var x, y;

        for (var i = 0; i < this.nVertices; i++) {
            x = this.centerBX + Math.cos(angle) * this.radius;
            y = this.centerBY + Math.sin(angle) * this.radius;

            this.vertices.push(x); this.vertices.push(y); this.vertices.push(this.centerBZ - this.height/2);
            this.vertices.push(x); this.vertices.push(y); this.vertices.push(this.centerBZ + this.height/2);

            angle += dangle;
        }

        this.indices = [
        ];

        for (var i = 2, j = 2; j <= this.nVertices; i += 2, j++) {
            // ---- Base - Counter Clock-wise
            this.indices.push(2 + (i + 2) % (this.nVertices * 2));
            this.indices.push(i);
            this.indices.push(0); // Base center
            // ---- Cover - Clock-wise
            this.indices.push(i+1);
            this.indices.push(2 + (i + 3) % (this.nVertices * 2));
            this.indices.push(1); // Cover center
            // ---- Walls
            this.indices.push(i);
            this.indices.push(2 + (i + 2) % (this.nVertices * 2));
            this.indices.push(i + 1);
            this.indices.push(2 + (i + 2) % (this.nVertices * 2));
            this.indices.push(2 + (i + 3) % (this.nVertices * 2));
            this.indices.push(i + 1);
        }

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
