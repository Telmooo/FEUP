/**
 * MyCylinder
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyCylinder extends CGFobject {
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
    }

    display() {
        //this.scene.rotate(-Math.PI/2, 1, 0, 0);
        this.scene.pushMatrix();
        // ---- Base
        this.scene.rotate(Math.PI, 1, 0, 0);
        this.scene.translate(0, this.height/2, 0);
        this.scene.rotate(-Math.PI/2, 1, 0, 0);
        this.circle.display();
        // ----
        this.scene.popMatrix();
        this.scene.pushMatrix();
        // ---- Cover
        this.scene.translate(0, this.height/2, 0);
        this.scene.rotate(-Math.PI/2, 1, 0, 0);
        this.circle.display();
        // ----
        this.scene.popMatrix();
        this.scene.pushMatrix();
        // ---- Walls
        var dangle = (Math.PI * 2)/this.nVertices, angle = 0;
        var dx = Math.sqrt(2 * this.radius * this.radius * (1 - Math.cos(dangle))); // lenght of a side of the circle

        for (var i = 0; i < this.nVertices; i++, angle += dangle) {
            this.scene.pushMatrix();
            this.scene.translate(this.radius * Math.sin(angle), 0, this.radius * Math.cos(angle));
            this.scene.translate(this.centerBX, this.centerBY, this.centerBZ);
            this.scene.rotate(angle, 0, 1, 0);
            this.scene.scale(dx, this.height, 1);
            this.quad.display();
            this.scene.popMatrix();
        }
        // ----
        this.scene.popMatrix();
    }
}
