/**
* MyVehicle
* @constructor
*/
class MyVehicle extends CGFobject {
    constructor(scene) {
        super(scene);
        this.body = new MySphere(this.scene, 32, 16);
        this.gondola = new MyGondola(this.scene);
        this.rudder = new MyRudder(this.scene);
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
        this.bodyTex.loadTexture('images/vehicle/body.png');
        this.bodyTex.setTextureWrap('REPEAT', 'REPEAT');
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
        this.rudder.display();
        this.scene.popMatrix();
        // --

        // -- Right
        this.scene.pushMatrix();
        this.scene.translate(0.7, 0, -2);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.scene.scale(0.7, 0.7, 0.7);
        this.rudder.display();
        this.scene.popMatrix();
        // --

        // -- Left
        this.scene.pushMatrix();
        this.scene.translate(-0.7, 0, -2);
        this.scene.rotate(Math.PI/2, 1, 0, 0);
        this.scene.rotate(Math.PI, 0, 1, 0);
        this.scene.scale(0.7, 0.7, 0.7);
        this.rudder.display();
        this.scene.popMatrix();
        // --
        // ----

        this.scene.popMatrix();
    }

    enableNormalViz() {
        this.body.enableNormalViz();
    }

    disableNormalViz() {
        this.body.disableNormalViz();
    }

    /**
     * Update vehicle position
     */
    update(delta_time, absolute_max_speed, absolute_max_rotation_speed) {
        this.turn(this.rotationSpeed * delta_time);

        let x_speed = Math.sin(this.orientation) * this.speed;
        let z_speed = Math.cos(this.orientation) * this.speed;

        this.x += x_speed * delta_time;
        this.z += z_speed * delta_time;

        this.gondola.update(this.speed, absolute_max_speed);

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
            new_speed = this.speed + friction_acc;
            if (new_speed > -absolute_min_speed) {
                new_speed = 0;
            }
            this.speed = new_speed;
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
* MyGondola
* @constructor
*/
class MyGondola extends CGFobject {
    constructor(scene) {
        super(scene);
        this.gondolaBody = new MyCylinder(this.scene, 32);
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
        this.gondolaBodyTex.loadTexture('images/vehicle/gondola.png');
        this.gondolaBodyTex.setTextureWrap('REPEAT', 'REPEAT');
    }

    display() {
        // ---- Body
        this.scene.pushMatrix();
        this.scene.translate(0, 0, -2);
        this.scene.rotate(Math.PI / 2, 1, 0, 0);
        this.scene.scale(1, 4, 1);
        this.gondolaBodyTex.apply();
        this.gondolaBody.display();
        this.scene.material.apply();
        this.scene.popMatrix();
        // ----

        // ---- Front Extreme
        this.scene.pushMatrix();
        this.scene.translate(0, 0, 2);
        this.gondolaExtremes.display();
        this.scene.popMatrix();
        // ----

        // ---- Back Extreme
        this.scene.pushMatrix();
        this.scene.translate(0, 0, -2);
        this.gondolaExtremes.display();
        this.scene.popMatrix();
        // ----

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
}

/**
* MyHelice
* @constructor
*/
class MyHeliceSupport extends CGFobject {
    constructor(scene) {
        super(scene);
        this.support = new MySphere(this.scene, 16, 8);
        this.helice = new MyHelice(this.scene);
        this.initMaterials();
    }

    initMaterials() {

    }

    display() {
        // ---- Support
        this.scene.pushMatrix();
        this.scene.scale(0.3, 0.4, 1);
        this.support.display();
        this.scene.popMatrix();
        // ----

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
}

/**
* MyHelice
* @constructor
*/
class MyHelice extends CGFobject {
    constructor(scene) {
        super(scene);
        this.helice = new MyCircle(this.scene, 8);
        this.heliceJoint = new MySphere(this.scene, 12, 6);
        this.defaultRotationSpeed = 0.08;
        this.MAX_ROTATION_SPEED = 0.8;
        this.angle = 0;
    }

    display() {
        this.scene.pushMatrix();
        this.scene.rotate(this.angle, 0, 0, 1);

        // ---- Down-left helice
        this.scene.pushMatrix();
        this.scene.rotate(-Math.PI/4, 0, 0, 1);
        this.scene.translate(0, 1, 0);
        this.scene.scale(0.25, 1, 1);
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
        this.heliceJoint.display();
        this.scene.popMatrix();
        // ----
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
}

/**
* MyRudder
* @constructor
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
        this.rudderBaseTex.loadTexture('images/vehicle/rudder_base.png');
        this.rudderBaseTex.setTextureWrap('REPEAT', 'REPEAT');

        this.rudderConnectorTex = new CGFappearance(this.scene);
        this.rudderConnectorTex.setAmbient(0.1, 0.1, 0.1, 1);
        this.rudderConnectorTex.setDiffuse(0.9, 0.9, 0.9, 1);
        this.rudderConnectorTex.setSpecular(0.1, 0.1, 0.1, 1);
        this.rudderConnectorTex.setShininess(10.0);
        this.rudderConnectorTex.loadTexture('images/vehicle/rudder_connector.png');
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
}
