/**
* MyVehicle - zepplin
* @constructor
* @param {CGFscene} scene - Reference to MyScene object
*/
class MyVehicle extends CGFobject {
    constructor(scene) {
        super(scene);
        this.body = new MySphere(this.scene, 32, 16);
        this.gondola = new MyGondola(this.scene);
        this.rudder = new MyRudder(this.scene);
        this.flag = new MyFlag(this.scene);
        this.orientation = 0;
        this.speed = 0;
        this.rotationSpeed = 0;
        this.horizontal_rudder_inclination = 0;
        this.MAX_HORIZONTAL_RUDDER_INCLINATION = Math.PI / 4;
        this.x = 0;
        this.y = 10;
        this.z = 0;
        this.initMaterials();
    }

    initMaterials() {
        this.bodyTex = new CGFappearance(this.scene);
        this.bodyTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.bodyTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.bodyTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.bodyTex.setShininess(10.0);
        this.bodyTex.loadTexture('images/vehicle/body/body.jpg');
        this.bodyTex.setTextureWrap('REPEAT', 'REPEAT');

        this.rudderTop = new CGFtexture(this.scene, 'images/vehicle/rudder/rudder_top.jpg');
        this.rudderConnectorTop = new CGFtexture(this.scene, 'images/vehicle/rudder/rudder_connector_top.jpg');
        this.rudderBot = new CGFtexture(this.scene, 'images/vehicle/rudder/rudder_bot.jpg');
        this.rudderConnectorBot = new CGFtexture(this.scene, 'images/vehicle/rudder/rudder_connector_bot.jpg');
        this.rudderSide = new CGFtexture(this.scene, 'images/vehicle/rudder/rudder_side.jpg');
        this.rudderConnectorSide = this.rudderConnectorTop;
    }

    display() {

        this.scene.pushMatrix();

        this.scene.translate(this.x, this.y, this.z);
        this.scene.rotate(this.orientation, 0, 1, 0);

        // ---- Body
        this.scene.pushMatrix();
        this.scene.scale(1, 1, 2);
        this.bodyTex.apply();
        this.body.display();
        this.scene.material.apply();
        this.scene.popMatrix();
        // ----

        // ---- Gondola
        this.scene.pushMatrix();
        this.scene.translate(0, -1.1, 0);
        this.scene.scale(0.25, 0.25, 0.25);
        this.gondola.display();
        this.scene.popMatrix();
        // ----

        // ---- Rudders
        // -- Upper
        this.scene.pushMatrix();
        this.scene.rotate(this.horizontal_rudder_inclination, 0, 1, 0);
        this.scene.translate(0, 0.7, -2);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.scene.rotate(Math.PI/2, 0, 1, 0);
        this.scene.scale(0.7, 0.7, 0.7);
        this.rudder.setBaseTexture(this.rudderTop);
        this.rudder.setConnectorTexture(this.rudderConnectorTop);
        this.rudder.display();
        this.scene.popMatrix();
        // --

        // -- Bottom
        this.scene.pushMatrix();
        this.scene.rotate(this.horizontal_rudder_inclination, 0, 1, 0);
        this.scene.translate(0, -0.7, -2);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.scene.rotate(-Math.PI/2, 0, 1, 0);
        this.scene.scale(0.7, 0.7, 0.7);
        this.rudder.setBaseTexture(this.rudderBot);
        this.rudder.setConnectorTexture(this.rudderConnectorBot);
        this.rudder.display();
        this.scene.popMatrix();
        // --

        // -- Right
        this.scene.pushMatrix();
        this.scene.translate(0.7, 0, -2);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.scene.scale(0.7, 0.7, 0.7);
        this.rudder.setBaseTexture(this.rudderSide);
        this.rudder.setConnectorTexture(this.rudderConnectorSide);
        this.rudder.display();
        this.scene.popMatrix();
        // --

        // -- Left
        this.scene.pushMatrix();
        this.scene.translate(-0.7, 0, -2);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.scene.rotate(Math.PI, 0, 1, 0);
        this.scene.scale(0.7, 0.7, 0.7);
        this.rudder.setBaseTexture(this.rudderSide);
        this.rudder.setConnectorTexture(this.rudderConnectorSide);
        this.rudder.display();
        this.scene.popMatrix();
        // --
        // ----

        // ---- Flag
        // -- Flag
        this.scene.pushMatrix();
        this.scene.rotate(this.horizontal_rudder_inclination, 0, 1, 0);
        this.scene.translate(0, 0, -4.3);
        this.scene.rotate(Math.PI/2, 0, 1, 0);
        this.scene.scale(2.5, 0.8, 1.0);
        this.flag.display();
        this.scene.popMatrix();
        // --

        this.scene.popMatrix();
    }

    enableNormalViz() {
        this.body.enableNormalViz();
        this.gondola.enableNormalViz();
        this.rudder.enableNormalViz();
        this.flag.enableNormalViz();
    }

    disableNormalViz() {
        this.body.disableNormalViz();
        this.gondola.disableNormalViz();
        this.rudder.disableNormalViz();
        this.flag.disableNormalViz();
    }

    setFillMode() {
        this.body.setFillMode();
        this.gondola.setFillMode();
        this.rudder.setFillMode();
		this.flag.setFillMode();
	}

	setLineMode() {
        this.body.setLineMode();
        this.gondola.setLineMode();
        this.rudder.setLineMode();
		this.flag.setLineMode();
	};

    setFlagTexture(texture) {
		this.flag.setFlagTexture(texture);
	}

    enterPilotMode(speed, angular_speed) {
        this.speed = speed;
        this.rotationSpeed = angular_speed;
    }

    getX() {
        return this.x;
    }

    getY() {
        return this.y;
    }

    getZ() {
        return this.z;
    }

    getSpeed() {
        return this.speed;
    }

    getOrientation() {
        return this.orientation;
    }

    /**
     * As translations are from center of the body, the radius from the center to the bottom of the gondola is defined by
     * Radius = |translationY_gondola| + |scaleY_gondola| * radius_gondola
     * For the values used to determine the radius, see translations and scales of gondola
     */
    getRadiusFromCenterToBottom() {
        return 1.1 + 0.25 * this.gondola.getGondolaBodyRadius();
    }

    /**
     * Update vehicle position
     */
    update(time, delta_time, absolute_max_speed, absolute_max_rotation_speed) {
        this.turn(this.rotationSpeed * delta_time);

        let x_speed = Math.sin(this.orientation) * this.speed;
        let z_speed = Math.cos(this.orientation) * this.speed;

        this.x += x_speed * delta_time;
        this.z += z_speed * delta_time;

        this.gondola.update(this.speed, absolute_max_speed);

        this.flag.update(delta_time, this.speed);

        this.horizontal_rudder_inclination = (-this.rotationSpeed / absolute_max_speed) * this.MAX_HORIZONTAL_RUDDER_INCLINATION;
    }

    turn(angle) {
        this.orientation = (this.orientation + angle + Math.PI * 2) % (Math.PI * 2);
    }

    accelerate_rotation(angular_acceleration, friction_coef, absolute_max_rotation_speed, absolute_min_rotation_speed) {
        // restrict angle to 0-359 degrees
        let new_angular_speed = this.rotationSpeed + angular_acceleration;
        new_angular_speed = Math.max(-absolute_max_rotation_speed, new_angular_speed);
        new_angular_speed = Math.min(absolute_max_rotation_speed, new_angular_speed);
        this.rotationSpeed = new_angular_speed;

        let friction_acc = Physics.friction(friction_coef);

        if (this.rotationSpeed > 0) {
            new_angular_speed = this.rotationSpeed - friction_acc;
            if (new_angular_speed < absolute_min_rotation_speed) {
                new_angular_speed = 0;
            }
            this.rotationSpeed = new_angular_speed;
        } else if (this.rotationSpeed < 0) {
            new_angular_speed = this.rotationSpeed + friction_acc;
            if (new_angular_speed > -absolute_min_rotation_speed) {
                new_angular_speed = 0;
            }
            this.rotationSpeed = new_angular_speed;
        }
    }

    accelerate(increment, friction_coef, absolute_max_speed, absolute_min_speed) {
        let friction_acc = Physics.friction(friction_coef);

        let new_speed = this.speed + increment;
        new_speed = Math.max(-absolute_max_speed, new_speed);
        new_speed = Math.min(absolute_max_speed, new_speed);
        this.speed = new_speed;

        if (this.speed > 0) {
            new_speed = this.speed - friction_acc;
            if (new_speed < absolute_min_speed) {
                new_speed = 0;
            }
            this.speed = new_speed;
        } else if (this.speed < 0) {
            this.speed = 0;
        }
    }

    reset() {
        this.orientation = 0;
        this.speed = 0;
        this.rotationSpeed = 0;
        this.x = 0;
        this.y = 10;
        this.z = 0;
    }
}

/**
 * MyGondola - zone of the zepplin where passengers sit
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyGondola extends CGFobject {
    constructor(scene) {
        super(scene);
        this.gondolaBody = new MyCylinder(this.scene, 16);
        this.gondolaExtremes = new MySphere(this.scene, 16, 8);
        this.helice = new MyHeliceSupport(this.scene);
        this.initMaterials();
    }

    initMaterials() {
        this.gondolaBodyTex = new CGFappearance(this.scene);
        this.gondolaBodyTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.gondolaBodyTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.gondolaBodyTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.gondolaBodyTex.setShininess(10.0);
        this.gondolaBodyTex.loadTexture('images/vehicle/gondola/gondola3.jpg');
        this.gondolaBodyTex.setTextureWrap('REPEAT', 'REPEAT');

        this.gondolaFrontTex = new CGFappearance(this.scene);
        this.gondolaFrontTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.gondolaFrontTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.gondolaFrontTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.gondolaFrontTex.setShininess(10.0);
        this.gondolaFrontTex.loadTexture('images/vehicle/gondola/gondola_extremes3.jpg');
        this.gondolaFrontTex.setTextureWrap('REPEAT', 'REPEAT');

        this.gondolaBackTex = new CGFappearance(this.scene);
        this.gondolaBackTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.gondolaBackTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.gondolaBackTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.gondolaBackTex.setShininess(10.0);
        this.gondolaBackTex.loadTexture('images/vehicle/gondola/gondola_extremes4.jpg');
        this.gondolaBackTex.setTextureWrap('REPEAT', 'REPEAT');
    }

    display() {
        // ---- Body
        this.scene.pushMatrix();
        this.scene.translate(0, 0, -2);
        this.scene.rotate(Math.PI / 2, 1, 0, 0);
        this.scene.scale(1, 4, 1);
        this.gondolaBodyTex.apply();
        this.gondolaBody.display();
        this.scene.popMatrix();
        // ----

        // ---- Front Extreme
        this.scene.pushMatrix();
        this.scene.translate(0, 0, 2);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.gondolaFrontTex.apply();
        this.gondolaExtremes.display();
        this.scene.popMatrix();
        // ----

        // ---- Back Extreme
        this.scene.pushMatrix();
        this.scene.translate(0, 0, -2);
        this.scene.rotate(-Math.PI/2, 1, 0, 0);
        this.gondolaBackTex.apply();
        this.gondolaExtremes.display();
        this.scene.popMatrix();
        // ----
        this.scene.material.apply();
        // ---- Left Helice
        this.scene.pushMatrix();
        this.scene.translate(-1.2, 0, -2.2);
        this.helice.display();
        this.scene.popMatrix();
        // ----

        // ---- Right Helice
        this.scene.pushMatrix();
        this.scene.translate(1.2, 0, -2.2);
        this.helice.display();
        this.scene.popMatrix();
        // ----
    }

    /**
     * The radius of the cylinder isn't changed, only the height
     */
    getGondolaBodyRadius() {
        return 1;
    }

    update(speed, absolute_max_speed) {
        this.helice.update(speed, absolute_max_speed);
    }

    enableNormalViz() {
        this.gondolaBody.enableNormalViz();
        this.gondolaExtremes.enableNormalViz();
        this.helice.enableNormalViz();
    }

    disableNormalViz() {
        this.gondolaBody.disableNormalViz();
        this.gondolaExtremes.disableNormalViz();
        this.helice.disableNormalViz();
    }

    setFillMode() {
        this.gondolaBody.setFillMode();
        this.gondolaExtremes.setFillMode();
		this.helice.setFillMode();
	}

	setLineMode() {
        this.gondolaBody.setLineMode();
        this.gondolaExtremes.setLineMode();
		this.helice.setLineMode();
	};
}

/**
 * MyHeliceSupport - component that supports the helice
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyHeliceSupport extends CGFobject {
    constructor(scene) {
        super(scene);
        this.support = new MySphere(this.scene, 16, 8);
        this.helice = new MyHelice(this.scene);
        this.initMaterials();
    }

    initMaterials() {
        this.heliceSupportTex = new CGFappearance(this.scene);
        this.heliceSupportTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.heliceSupportTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.heliceSupportTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.heliceSupportTex.setShininess(10.0);
        this.heliceSupportTex.loadTexture('images/vehicle/helice/helice_support.jpg');
        this.heliceSupportTex.setTextureWrap('REPEAT', 'REPEAT');
    }

    display() {
        // ---- Support
        this.scene.pushMatrix();
        this.scene.scale(0.3, 0.4, 1);
        this.heliceSupportTex.apply();
        this.support.display();
        this.scene.popMatrix();
        // ----
        this.scene.material.apply();
        // ---- Helice
        this.scene.pushMatrix();
        this.scene.translate(0, 0, -1);
        this.scene.scale(0.4, 0.4, 0.4);
        this.helice.display();
        this.scene.popMatrix();
        // ----
    }

    update(speed, absolute_max_speed) {
        this.helice.update(speed, absolute_max_speed);
    }

    enableNormalViz() {
        this.support.enableNormalViz();
        this.helice.enableNormalViz();
    }

    disableNormalViz() {
        this.support.disableNormalViz();
        this.helice.disableNormalViz();
    }

    setFillMode() {
        this.support.setFillMode();
        this.helice.setFillMode();
	}

	setLineMode() {
        this.support.setLineMode();
        this.helice.setLineMode();
	};
}

/**
 * MyHelice - vehicle helice
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyHelice extends CGFobject {
    constructor(scene) {
        super(scene);
        this.helice = new MyCircle(this.scene, 8);
        this.heliceJoint = new MySphere(this.scene, 12, 6);
        this.defaultRotationSpeed = 0.08;
        this.MAX_ROTATION_SPEED = 0.8;
        this.angle = 0;
        this.initMaterials();
    }

    initMaterials() {
        this.heliceTex = new CGFappearance(this.scene);
        this.heliceTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.heliceTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.heliceTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.heliceTex.setShininess(10.0);
        this.heliceTex.loadTexture('images/vehicle/helice/helice.jpg');
        this.heliceTex.setTextureWrap('REPEAT', 'REPEAT');

        this.jointTex = new CGFappearance(this.scene);
        this.jointTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.jointTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.jointTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.jointTex.setShininess(10.0);
        this.jointTex.loadTexture('images/vehicle/helice/joint.jpg');
        this.jointTex.setTextureWrap('REPEAT', 'REPEAT');
    }

    display() {
        this.scene.pushMatrix();
        this.scene.rotate(this.angle, 0, 0, 1);

        // ---- Down-left helice
        this.scene.pushMatrix();
        this.scene.rotate(-Math.PI/4, 0, 0, 1);
        this.scene.translate(0, 1, 0);
        this.scene.scale(0.25, 1, 1);
        this.heliceTex.apply();
        this.helice.display();
        this.scene.popMatrix();
        // ----
        // ---- Up-right helice
        this.scene.pushMatrix();
        this.scene.rotate(3 * Math.PI/4, 0, 0, 1);
        this.scene.translate(0, 1, 0);
        this.scene.scale(0.25, 1, 1);
        this.helice.display();
        this.scene.popMatrix();
        // ----
        this.scene.popMatrix();

        // ---- Helice Joint
        this.scene.pushMatrix();
        this.scene.scale(0.1, 0.1, 0.1);
        this.jointTex.apply();
        this.heliceJoint.display();
        this.scene.popMatrix();
        // ----
        this.scene.material.apply();
    }

    update(speed, absolute_max_speed) {
        if (this.speed >= 0)
            this.angle += (this.defaultRotationSpeed + (speed / absolute_max_speed) * this.MAX_ROTATION_SPEED);
        else
            this.angle -= (this.defaultRotationSpeed + (speed / absolute_max_speed) * this.MAX_ROTATION_SPEED);
    }

    enableNormalViz() {
        this.helice.enableNormalViz();
        this.heliceJoint.enableNormalViz();
    }

    disableNormalViz() {
        this.helice.disableNormalViz();
        this.heliceJoint.disableNormalViz();
    }

    setFillMode() {
        this.helice.setFillMode();
        this.heliceJoint.setFillMode();
	}

	setLineMode() {
        this.helice.setLineMode();
        this.heliceJoint.setLineMode();
	};
}

/**
 * MyRudder - vehicle rudder
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyRudder extends CGFobject {
    constructor(scene) {
        super(scene);
        this.rudderBase = new MySquare(this.scene);
        this.rudderConnector = new MyTriangle(this.scene);
        this.initMaterials();
    }

    initMaterials() {
        this.rudderBaseTex = new CGFappearance(this.scene);
        this.rudderBaseTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.rudderBaseTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.rudderBaseTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.rudderBaseTex.setShininess(10.0);
        this.rudderBaseTex.setTextureWrap('REPEAT', 'REPEAT');

        this.rudderConnectorTex = new CGFappearance(this.scene);
        this.rudderConnectorTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.rudderConnectorTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.rudderConnectorTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.rudderConnectorTex.setShininess(10.0);
        this.rudderConnectorTex.setTextureWrap('REPEAT', 'REPEAT');
    }

    display() {
        // ---- Base
        this.rudderBaseTex.apply();
        this.rudderBase.display();
        this.scene.material.apply();
        // ----

        // ---- Connector
        this.scene.pushMatrix();
        this.scene.translate(0, 1, 0);
        this.rudderConnectorTex.apply();
        this.rudderConnector.display();
        this.scene.material.apply();
        this.scene.popMatrix();
    }

    enableNormalViz() {
        this.rudderBase.enableNormalViz();
        this.rudderConnector.enableNormalViz();
    }

    disableNormalViz() {
        this.rudderBase.disableNormalViz();
        this.rudderConnector.disableNormalViz();
    }

    setFillMode() {
        this.rudderBase.setFillMode();
        this.rudderConnector.setFillMode();
	}

	setLineMode() {
        this.rudderBase.setLineMode();
        this.rudderConnector.setLineMode();
	};

    setBaseTexture(texture) {
        this.rudderBaseTex.setTexture(texture);
    }

    setConnectorTexture(texture) {
        this.rudderConnectorTex.setTexture(texture);
    }
}
