/**
 * MyBillboard - supply counter board
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyBillboard extends CGFobject{
	constructor(scene) {
        super(scene);
        this.billboard = new MyPlane(this.scene, 10);
        this.back = new MyPlane(this.scene, 10);
        this.progressBar = new MyPlane(this.scene, 10);
        this.post = new MySquare(this.scene);

        this.initMaterials();
        this.initShaders();
	}

    initMaterials() {
        this.billboardTex = new CGFappearance(this.scene);
        this.billboardTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.billboardTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.billboardTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.billboardTex.setShininess(10.0);
        this.billboardTex.setTextureWrap('REPEAT', 'REPEAT');
		this.billboardTex.loadTexture('images/terrain/billboard/billboard.jpg');

        this.backTex = new CGFappearance(this.scene);
        this.backTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.backTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.backTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.backTex.setShininess(10.0);
        this.backTex.setTextureWrap('REPEAT', 'REPEAT');

        this.progressBarTex = new CGFappearance(this.scene);
        this.progressBarTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.progressBarTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.progressBarTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.progressBarTex.setShininess(10.0);
        this.progressBarTex.setTextureWrap('REPEAT', 'REPEAT');
		this.progressBarTex.loadTexture('images/texture_map_helper.png');

		this.postTex = new CGFappearance(this.scene);
        this.postTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.postTex.setDiffuse(0.2, 0.2, 0.2, 1);
        this.postTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.postTex.setShininess(10.0);
    }

    initShaders() {
        this.shader = new CGFshader(this.scene.gl, "shaders/progressBar.vert", "shaders/progressBar.frag");

        this.shader.setUniformsValues({
            percent: 0.0
        });
    }

	updateShader(percent) {
		this.shader.setUniformsValues({
            percent: percent
        });
	}

    display() {
        // ---- Billboard
        this.scene.pushMatrix();
        this.scene.translate(0, 1.5, 0);
        this.scene.scale(2, 1, 1);
        this.billboardTex.apply();
        this.billboard.display();
        this.scene.popMatrix();
        // ----

        // ---- Back
        this.scene.pushMatrix();
        this.scene.translate(0, 1.5, 0);
        this.scene.scale(2, 1, 1);
        this.scene.rotate(Math.PI, 0, 1, 0);
        this.backTex.apply();
        this.back.display();
        this.scene.popMatrix();
        // ----

        // ---- Progress Bar
        this.scene.pushMatrix();
        this.scene.translate(0, 1.25, 0.01);
        this.scene.scale(1.5, 0.2, 1);
        this.progressBarTex.apply();
        this.scene.setActiveShader(this.shader);
        this.progressBar.display();
        this.scene.setActiveShader(this.scene.defaultShader);
        this.scene.popMatrix();
        // ----

        // ---- Posts
		this.postTex.apply();
        // Left
        this.scene.pushMatrix();
        this.scene.translate(0.95, 0.5, 0);
        this.scene.scale(0.1, 1, 1);
        this.post.display();
        this.scene.popMatrix();
        // Right
        this.scene.pushMatrix();
        this.scene.translate(-0.95, 0.5, 0);
        this.scene.scale(0.1, 1, 1);
        this.post.display();
        this.scene.popMatrix();
        // ----
		this.postTex.apply();

		this.scene.material.apply();
    }

    enableNormalViz() {
        this.billboard.enableNormalViz();
        this.progressBar.enableNormalViz();
        this.post.enableNormalViz();
    }

    disableNormalViz() {
        this.billboard.disableNormalViz();
        this.progressBar.disableNormalViz();
        this.post.disableNormalViz();
    }

	setFillMode() {
		this.billboard.setFillMode();
        this.back.setFillMode();
        this.progressBar.setFillMode();
        this.post.setFillMode();
	}

	setLineMode() {
		this.billboard.setLineMode();
        this.back.setLineMode();
        this.progressBar.setLineMode();
        this.post.setLineMode();
	};
}
