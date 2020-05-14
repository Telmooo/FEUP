/**
 * MyFlag - vehicle animated flag
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyFlag extends CGFobject{
	constructor(scene) {
        super(scene);
        this.flag = new MyDoubleFacedPlane(this.scene, 20);
        this.flag_wire = new MyDoubleFacedPlane(this.scene, 6);
		this.instant = 0;
		this.amplitude = 0.2;
		this.instantFactor = 0.3;
		this.lengthFactor = 4.0;

        this.initMaterials();
        this.initShaders();
	}

    initMaterials() {
		this.flagMat = new CGFappearance(this.scene);
        this.flagMat.setAmbient(0.1, 0.1, 0.1, 1);
        this.flagMat.setDiffuse(0.9, 0.9, 0.9, 1);
        this.flagMat.setSpecular(0.1, 0.1, 0.1, 1);
        this.flagMat.setShininess(10.0);
        this.flagMat.setTextureWrap('REPEAT', 'REPEAT');

		this.flagWireTex = new CGFappearance(this.scene);
        this.flagWireTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.flagWireTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.flagWireTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.flagWireTex.setShininess(10.0);
        this.flagWireTex.setTextureWrap('REPEAT', 'REPEAT');
		this.flagWireTex.loadTexture('images/vehicle/flag/flag_wire.jpg');
    }

    initShaders() {
        this.shader = new CGFshader(this.scene.gl, "shaders/flag.vert", "shaders/flag.frag");

        this.shader.setUniformsValues({
			flagTextureSampler: 0,
			instant: 0,
		 	amplitude: this.amplitude,
			instantFactor : this.instantFactor,
			lengthFactor : this.lengthFactor,
		 	invert : 0.0 });
    }

    update(delta_time, speed) {
		this.instant += delta_time * (speed + 2);
		this.shader.setUniformsValues({ instant : this.instant });
	}

    display() {
		this.scene.setActiveShader(this.shader);
		// ---- Flag
		this.flagMat.apply();
		this.shader.setUniformsValues({ offset : 0.0 });
        this.flag.display();
		// ----

		// -- Flag Wires
		this.flagWireTex.apply();
		this.shader.setUniformsValues({ offset : -1.0 });
        // - Top
        this.scene.pushMatrix();
        this.scene.translate(-0.75, 0.3, 0);
        this.scene.scale(0.5, 0.01, 1);
        this.flag_wire.display();
        this.scene.popMatrix();
        // -
        // - Bot
		this.scene.pushMatrix();
		this.scene.translate(-0.75, -0.3, 0);
		this.scene.scale(0.5, 0.01, 1);
		this.flag_wire.display();
		this.scene.popMatrix();
        // -
        // --
		this.scene.material.apply();
		this.scene.setActiveShader(this.scene.defaultShader);
        // ----
    }

	setFlagTexture(texture) {
		this.flagMat.setTexture(texture);
	}

    enableNormalViz() {
        this.flag.enableNormalViz();
		this.flag_wire.enableNormalViz();
    }

    disableNormalViz() {
        this.flag.disableNormalViz();
		this.flag_wire.disableNormalViz();
    }

	setFillMode() {
		this.flag.setFillMode();
		this.flag_wire.setFillMode();
	}

	setLineMode() {
		this.flag.setLineMode();
		this.flag_wire.setLineMode();
	};
}
