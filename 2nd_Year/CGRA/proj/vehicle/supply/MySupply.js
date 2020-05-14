/**
 * Possible states for vehicle supplies
 */
const SupplyStates = {
     INACTIVE: 0,
     FALLING: 1,
     LANDED: 2
};

/**
 * MySupply - vehicle supply box
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MySupply extends CGFobject {

    constructor(scene) {
		super(scene);
        this.quad = new MyQuad(this.scene);
        this.state = SupplyStates.INACTIVE;
        this.fallingSpeed = 0;
        this.speed = 0;
        this.orientation = 0;
        this.x = 0;
        this.y = 0;
        this.z = 0;
        this.g = 0;
        this.exploded = false;
        this.EXPLOSION_RADIUS = 4;

        this.facesPositionsOnLand = [];
        this.facesOrientationOnLand = [];

        this.initMaterials();
	}

    initMaterials() {
        this.supplyTex = new CGFappearance(this.scene);
        this.supplyTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.supplyTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.supplyTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.supplyTex.setShininess(10.0);
        this.supplyTex.loadTexture('images/vehicle/supply/crate.png');
        this.supplyTex.setTextureWrap('REPEAT', 'REPEAT');
    }

    update(delta_time, yLimit) {
        if (this.state == SupplyStates.FALLING) {
            this.fallingSpeed += -this.g * delta_time;

            let x_speed = Math.sin(this.orientation) * this.speed;
            let z_speed = Math.cos(this.orientation) * this.speed;

            this.x += x_speed * delta_time;
            this.y += this.fallingSpeed * delta_time;
            this.z += z_speed * delta_time;

            if (this.y <= yLimit) this.land(yLimit);
        }
    }

    drop(x, y, z, orientation, speed, acceleration) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.orientation = orientation;
        this.g = acceleration;
        this.speed = speed;
        this.fallingSpeed = 0;
        this.state = SupplyStates.FALLING;
    }

    land(yLimit) {
        this.orientation = 0;
        this.y = yLimit;
        this.state = SupplyStates.LANDED;

        let full_speed = Math.sqrt(this.speed * this.speed + this.fallingSpeed * this.fallingSpeed);
        this.fallingSpeed = 0;
        this.speed = 0;

        if (full_speed >= this.g * 2) {
            let ang = 0;
            for (let i = 0; i < 6; i++) {
                let offsetRadius = Math.random() * this.EXPLOSION_RADIUS;
                let offsetX = Math.sin(ang) * offsetRadius;
                let offsetZ = Math.cos(ang) * offsetRadius;

                this.facesPositionsOnLand.push(this.x + offsetX, this.y, this.z + offsetZ);
                this.facesOrientationOnLand.push(ang + Math.random() * (Math.PI*2));

                ang += Math.PI/8 + Math.random() * (Math.PI/5);
            }
            this.exploded = true;
        }
    }

    reset() {
        this.state = SupplyStates.INACTIVE;
        this.fallingSpeed = 0;
        this.speed = 0;
        this.orientation = 0;
        this.x = 0;
        this.y = 0;
        this.z = 0;
        this.exploded = false;
        this.facesPositionsOnLand = [];
        this.facesOrientationOnLand = [];
    }

    getFaceSize() {
        return 1;
    }

    isInactive() {
        return this.state == SupplyStates.INACTIVE;
    }

    hasLanded() {
        return this.state == SupplyStates.LANDED;
    }

    displayCube() {
        this.scene.pushMatrix();
        this.supplyTex.apply();
        this.scene.translate(this.x, this.y, this.z);
        this.scene.rotate(this.orientation, 0, 1, 0);

        this.scene.pushMatrix();

        // ---- Back Face
        this.scene.translate(0, 0, -0.5);
        this.scene.rotate(Math.PI, 0, 1, 0);
		this.scene.rotate(Math.PI/2, 0, 0, 1);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Front Face
        this.scene.translate(0, 0, 0.5);
		this.scene.rotate(Math.PI/2, 0, 0, 1);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Right Face
        this.scene.translate(0.5, 0, 0);
        this.scene.rotate(Math.PI/2, 0, 1, 0);
		this.scene.rotate(Math.PI/2, 0, 0, 1);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Left Face
        this.scene.translate(-0.5, 0, 0);
        this.scene.rotate(-Math.PI/2, 0, 1, 0);
		this.scene.rotate(-Math.PI/2, 0, 0, 1);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Bottom Face
        this.scene.translate(0, -0.5, 0);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.quad.display();
        // ----

        this.scene.popMatrix();
        this.scene.pushMatrix();

        // ---- Upper Face
        this.scene.translate(0, 0.5, 0);
        this.scene.rotate(-Math.PI/2, 1, 0, 0);
		this.scene.rotate(Math.PI, 0, 0, 1);
        this.quad.display();
        // ----
        this.scene.popMatrix();

        this.scene.material.apply();
        this.scene.popMatrix();
    }

    displayExploded() {
        this.supplyTex.apply();
        for (let i = 0; i < 6; i++) {
            this.scene.pushMatrix();
            this.scene.translate(this.facesPositionsOnLand[i * 3], this.facesPositionsOnLand[i * 3 + 1], this.facesPositionsOnLand[i * 3 + 2]);
            this.scene.rotate(this.facesOrientationOnLand[i], 0, 1, 0);
            this.scene.translate(0, -0.5, 0);
            this.scene.rotate(-Math.PI/2, 1, 0, 0);
            this.quad.display();
            this.scene.popMatrix();
        }
        this.scene.material.apply();
    }

    display() {
        switch (this.state) {
            case SupplyStates.FALLING:
                this.displayCube();
                break;
            case SupplyStates.LANDED:
                (this.exploded) ? this.displayExploded() : this.displayCube();
                break;
            default:
                break;
        }
    }

    enableNormalViz() {
        this.quad.enableNormalViz();
    }

    disableNormalViz() {
        this.quad.disableNormalViz();
    }

    setFillMode() {
        this.quad.setFillMode();
	}

	setLineMode() {
		this.quad.setLineMode();
	};
}
