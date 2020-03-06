/**
 * MyRoom
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyRoom extends CGFobject {
    constructor(scene) {
        super(scene);
        this.table = new MyTable(this.scene);
        this.unitCube = new MyUnitCubeQuad(this.scene);
        this.initMaterials();
    }

    initMaterials() {
        // Floor Color
        var color = hexToRgbA("#ccffcc");
        this.floor_color = new CGFappearance(this.scene);
        this.floor_color.setAmbient(color[0], color[1], color[2], 1.0);
        this.floor_color.setDiffuse(color[0], color[1], color[2], 1.0);
        this.floor_color.setSpecular(1.0, 1.0, 1.0, 1.0);
        this.floor_color.setShininess(10.0);

        // Wall Color
        color = hexToRgbA("#ffccff");
        this.wall_color = new CGFappearance(this.scene);
        this.wall_color.setAmbient(color[0], color[1], color[2], 1.0);
        this.wall_color.setDiffuse(color[0], color[1], color[2], 1.0);
        this.wall_color.setSpecular(1.0, 1.0, 1.0, 1.0);
        this.wall_color.setShininess(10.0);


    }

    display() {
        this.scene.pushMatrix();
        // ---- Floor
        this.scene.translate(0, -6.5, 0)
        this.scene.scale(50, 1, 50);
        this.floor_color.apply();
        this.unitCube.display();
        // ----
        this.scene.popMatrix();
        this.scene.pushMatrix();
        // ---- Walls
        this.wall_color.apply();
        // Front & Back Walls
        this.scene.pushMatrix();
        this.scene.translate(-25.5, -6, 0);
        this.scene.scale(1, 30, 50);
        this.unitCube.display();
        this.scene.popMatrix();
        this.scene.pushMatrix();
        this.scene.translate(25.5, -6, 0);
        this.scene.scale(1, 30, 50);
        this.unitCube.display();
        this.scene.popMatrix();
        // Side Walls
        this.scene.pushMatrix();
        this.scene.translate(0, -6, -25.5);
        this.scene.scale(50, 30, 1);
        this.unitCube.display();
        this.scene.popMatrix();
        this.scene.pushMatrix();
        this.scene.translate(0, -6, 25.5);
        this.scene.scale(50, 30, 1);
        this.unitCube.display();
        this.scene.popMatrix();
        // ----
        // ---- Tables
        this.table.display();
        // ----
    }
}
