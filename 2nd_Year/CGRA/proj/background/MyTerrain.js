/**
 * MyTerrain
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyTerrain extends CGFobject {
	constructor(scene, width, height) {
		super(scene);
        this.terrain = new MyPlane(this.scene, 20);
		this.width = width;
		this.height = height;
        this.initShaders();
		this.initMaterials();
	}

    initShaders() {
        this.shader = new CGFshader(this.scene.gl, "shaders/terrain.vert", "shaders/terrain.frag");

		this.shader.setUniformsValues({ terrainTextureSampler: 0, terrainHeightMapSampler: 1, maxHeight: this.height });
    }

	initMaterials() {
		this.terrainColor = new CGFtexture(this.scene, "images/terrain/terrain.jpg");
		this.terrainHeightMap = new CGFtexture(this.scene, "images/terrain/heightmap.jpg");

		this.terrainTex = new CGFappearance(this.scene);
        this.terrainTex.setAmbient(0.9, 0.9, 0.9, 1);
        this.terrainTex.setDiffuse(0.1, 0.1, 0.1, 1);
        this.terrainTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.terrainTex.setShininess(10.0);
        this.terrainTex.setTextureWrap('REPEAT', 'REPEAT');
		this.terrainTex.setTexture(this.terrainColor);
	}

    display() {
		this.scene.pushMatrix();
		this.terrainTex.apply();
		this.scene.setActiveShader(this.shader);
		this.terrainHeightMap.bind(1);
		this.scene.rotate(-Math.PI / 2, 1, 0, 0);
		this.scene.scale(this.width, this.width, 1);
		this.terrain.display();
		this.terrainHeightMap.unbind(1);
		this.scene.setActiveShader(this.scene.defaultShader);
		this.scene.popMatrix();
    }

	enableNormalViz() {
		this.terrain.enableNormalViz();
	}

	disableNormalViz() {
		this.terrain.disableNormalViz();
	}

	setFillMode() {
		this.terrain.setFillMode();
	}

	setLineMode() {
		this.terrain.setLineMode();
	};
}
