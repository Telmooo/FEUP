/**
 * MyTerrain
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTerrain extends CGFobject {
	constructor(scene, width, height) {
		super(scene);
        this.terrain = new MyPlane(this.scene, 20);
		this.width = width;
		this.height = height;
        this.initShaders();
		this.initTextures();
	}

    initShaders() {
        this.shader = new CGFshader(this.scene.gl, "shaders/terrain.vert", "shaders/terrain.frag");

		this.shader.setUniformsValues({ uSampler2: 1, uSampler3: 2, maxHeight: this.height });
    }

	initTextures() {
		this.terrainColor = new CGFtexture(this.scene, "images/terrain/terrain.jpg");
		this.terrainHeightMap = new CGFtexture(this.scene, "images/terrain/heightmap.jpg");
	}

    display() {
		this.scene.pushMatrix();
		this.scene.setActiveShader(this.shader);
		this.terrainColor.bind(0);
		this.terrainHeightMap.bind(2);
		this.scene.rotate(-Math.PI / 2, 1, 0, 0);
		this.scene.scale(this.width, this.width, 1);
		this.terrain.display();
		this.terrainColor.unbind(0);
		this.terrainHeightMap.unbind(2);
		this.scene.setActiveShader(this.scene.defaultShader);
		this.scene.popMatrix();
    }

	enableNormalViz() {
		this.terrain.enableNormalViz();
	}

	disableNormalViz() {
		this.terrain.disableNormalViz();
	}
}
