/**
 * MyTable
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTable extends CGFobject {
    constructor(scene) {
        super(scene);
        this.unitCube = new MyUnitCubeQuad(this.scene);
        this.initMaterials();
    }

    initMaterials() {
        // Table Color
        var color = hexToRgbA("#4d3900");
        this.table_color = new CGFappearance(this.scene);
        this.table_color.setAmbient(color[0], color[1], color[2], 1.0);
        this.table_color.setDiffuse(color[0], color[1], color[2], 1.0);
        this.table_color.setSpecular(1.0, 1.0, 1.0, 1.0);
        this.table_color.setShininess(10.0);

        // Black Color
        this.black = new CGFappearance(this.scene);
        this.black.setAmbient(0.0, 0.0, 0.0, 1.0);
        this.black.setDiffuse(0.0, 0.0, 0.0, 1.0);
        this.black.setSpecular(1.0, 1.0, 1.0, 1.0);
        this.black.setShininess(10.0);
    }

    display() {
        this.scene.pushMatrix();
        // ---- Table
        this.scene.scale(10, 1, 5);
        this.table_color.apply();
        this.unitCube.display();
        // ----
        this.scene.popMatrix();
        this.scene.pushMatrix();
        // ---- Legs
        this.scene.translate(0, -3.5, 0);
        this.scene.scale(1, 6, 1);
        this.black.apply();
        // PP Leg
        this.scene.pushMatrix();
        this.scene.translate(4.5, 0, 2);
        this.unitCube.display();
        this.scene.popMatrix();
        // PN Leg
        this.scene.pushMatrix();
        this.scene.translate(4.5, 0, -2);
        this.unitCube.display();
        this.scene.popMatrix();
        // NP Leg
        this.scene.pushMatrix();
        this.scene.translate(-4.5, 0, 2);
        this.unitCube.display();
        this.scene.popMatrix();
        // NN Leg
        this.scene.pushMatrix();
        this.scene.translate(-4.5, 0, -2);
        this.unitCube.display();
        this.scene.popMatrix();
        // ----
        this.scene.popMatrix();
    }
}
