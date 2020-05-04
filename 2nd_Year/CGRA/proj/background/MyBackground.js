/**
 * MyTerrain
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTerrain extends CGFobject {
	constructor(scene) {
		super(scene);
        this.terrain = new MyTerrain(this.scene, 50, 8);
        this.box = new MyCubeMap(this);
		this.width = width;
		this.height = height;
        this.initShaders();
		this.initTextures();
	}

    display() {
    }

	enableNormalViz() {
		this.terrain.enableNormalViz();
	}

	disableNormalViz() {
		this.terrain.disableNormalViz();
	}
}
