/**
 * MyUnitCubeQuad
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyUnitCubeQuad extends CGFobject {
	constructor(scene) {
		super(scene);
        this.quad = new MyQuad(this.scene);
	}

    display() {
        this.scene.pushMatrix();

        // ---- Bottom Face
        this.scene.translate(0, 0, -0.5);
        this.scene.rotate(Math.PI, 1, 0, 0);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Upper Face
        this.scene.translate(0, 0, 0.5);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Front Face
        this.scene.translate(0.5, 0, 0);
        this.scene.rotate(Math.PI/2, 0, 1, 0);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Back Face
        this.scene.translate(-0.5, 0, 0);
        this.scene.rotate(-Math.PI/2, 0, 1, 0);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Left Face
        this.scene.translate(0, -0.5, 0);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Right Face
        this.scene.translate(0, 0.5, 0);
        this.scene.rotate(-Math.PI/2, 1, 0, 0);
        this.quad.display();
        // ----

        this.scene.popMatrix();
    }
}
