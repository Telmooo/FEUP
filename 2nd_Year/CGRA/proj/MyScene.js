/**
* MyScene
* @constructor
*/
class MyScene extends CGFscene {
    constructor() {
        super();
    }
    init(application) {
        super.init(application);
        this.initCameras();
        this.initLights();

        //Background color
        this.gl.clearColor(0.0, 0.0, 0.0, 1.0);

        this.gl.clearDepth(100.0);
        this.gl.enable(this.gl.DEPTH_TEST);
        this.gl.enable(this.gl.CULL_FACE);
        this.gl.depthFunc(this.gl.LEQUAL);

        this.setUpdatePeriod(50);

        this.enableTextures(true);

        //Initialize scene objects
        this.axis = new CGFaxis(this);
        this.vehicle = new MyVehicle(this, 4);
        this.cubemap = new MyCubeMap(this);
        this.terrain = new MyTerrain(this, 50, 8);

        this.objects=[
            undefined,
			new MySphere(this, 16, 8),
			new MyCylinder(this, 16),
            this.cubemap,
            new MyCircle(this, 8),
            new MyHelice(this),
            new MyHeliceSupport(this),
            new MyGondola(this),
            new MyRudder(this),
            new MyPlane(this, 10),
            new MyTerrain(this, 10, 4),
            new MySupply(this)
		];

		// Object interface variables
		this.objectList = {
            'None': 0,
			'Sphere': 1,
			'Cylinder': 2,
            'Cubemap': 3,
            'Circle': 4,
            'Helice': 5,
            'Helice Support': 6,
            'Gondola': 7,
            'Rudder': 8,
            'Plane': 9,
            'Terrain': 10,
            'Supply': 11
		};

        //------ Textures
        this.textures = [
            undefined,
            new CGFtexture(this, 'images/earth.jpg'),
            new CGFtexture(this, 'images/cubemap.png'),
            new CGFtexture(this, 'images/texture_map_helper.png')
        ];

        this.backgrounds = [
            [
                null, null, null, null, null, null
            ],
            [
                new CGFtexture(this, 'images/split_cubemap/bottom.png'),
                new CGFtexture(this, 'images/split_cubemap/top.png'),
                new CGFtexture(this, 'images/split_cubemap/front.png'),
                new CGFtexture(this, 'images/split_cubemap/back.png'),
                new CGFtexture(this, 'images/split_cubemap/left.png'),
                new CGFtexture(this, 'images/split_cubemap/right.png')
            ],
            [
                new CGFtexture(this, 'images/sky.png'),
                new CGFtexture(this, 'images/sky.png'),
                new CGFtexture(this, 'images/sky.png'),
                new CGFtexture(this, 'images/sky.png'),
                new CGFtexture(this, 'images/sky.png'),
                new CGFtexture(this, 'images/sky.png')
            ]
        ];

        this.textureList = {
            'None': 0,
            'Earth': 1,
            'Background': 2,
            'Helper':  3
        };

        this.backgroundList = {
            'None': 0,
            'Cloudy Day': 1,
            'Sky': 2
        };


        this.backgroundFilterIds = { 'Linear': 0, 'Nearest': 1 };
        //-------

        //------ Applied Material
        this.material = new CGFappearance(this);
        this.material.setAmbient(0.1, 0.1, 0.1, 1);
        this.material.setDiffuse(0.9, 0.9, 0.9, 1);
        this.material.setSpecular(0.1, 0.1, 0.1, 1);
        this.material.setShininess(10.0);
        this.material.setTextureWrap('REPEAT', 'REPEAT');

        //Objects connected to MyInterface
        this.displayAxis = true;
		this.selectedObject = 0;
        this.selectedTexture = 0;
        this.applyBackground = false;
        this.selectedBackground = 0;
        this.selectedFilter = 0;
        this.applyMaterial = false;
        this.displayNormals = false;

        this.keyP_pressed = false;

        // Vehicle Things
        this.showVehicle = true;
        this.MIN_SPEED = 0.05;
        this.MAX_SPEED = 10;
        this.SPEED = 0.5;
        this.ANGULAR_SPEED = 0.1;
        this.MIN_ANGULAR_SPEED = 0.02;
        this.MAX_ANGULAR_SPEED = 2;
        this.speedFactor = 1.0;
        this.scaleFactor = 1.0;
        this.rotSpeedFactor = 0.5;
        this.frictionFactor = 0.01;
        this.lastFrameTime = 0;
        this.automatic_pilot = false;
        this.ORBIT_RADIUS = 5;
        this.ORBIT_PERIOD = 5;
        this.ORBIT_ANGULAR_SPEED = (Math.PI * 2) / this.ORBIT_PERIOD;
        this.ORBIT_SPEED = this.ORBIT_ANGULAR_SPEED * this.ORBIT_RADIUS; // v = w * r
        this.reset = ()=>this.vehicle.reset();

        // Supplies
        this.RELOADING_TIME = 1000;
        this.reloading = false;
        this.time_reloading = 0;
        this.supplies = [
            new MySupply(this),
            new MySupply(this),
            new MySupply(this),
            new MySupply(this),
            new MySupply(this),
        ];
        this.supplyCounter = 0;
        // ----
    }
    initLights() {
        this.lights[0].setPosition(15, 2, 5, 1);
        this.lights[0].setDiffuse(1.0, 1.0, 1.0, 1.0);
        this.lights[0].enable();
        this.lights[0].update();

        this.lights[1].setPosition(0, 0, 0, 0);
        this.lights[1].setAmbient(1.0, 1.0, 1.0, 1.0);

        this.lights[2].setPosition(-15, 2, -5, 1);
        this.lights[2].setDiffuse(1.0, 1.0, 1.0, 1.0);
        this.lights[2].enable();
        this.lights[2].update();
    }
    initCameras() {
        this.camera = new CGFcamera(0.4, 0.1, 500, vec3.fromValues(15, 15, 15), vec3.fromValues(0, 0, 0));
    }
    setDefaultAppearance() {
        this.setAmbient(0.2, 0.4, 0.8, 1.0);
        this.setDiffuse(0.2, 0.4, 0.8, 1.0);
        this.setSpecular(0.2, 0.4, 0.8, 1.0);
        this.setShininess(10.0);
    }

    updateBackgroundTexture() {
        this.cubemap.loadTexture(this.backgrounds[this.selectedBackground]);
    }

    updateBackgroundFiltering() {
            this.cubemap.changeFilter(this.selectedFilter);
    }

    // called periodically (as per setUpdatePeriod() in init())
    update(t){
        this.checkKeys();

        this.updateElements(t);

        this.lastFrameTime = t;
    }

    updateElements(t) {
        let elapsed_secs = Physics.millisToSec(t - this.lastFrameTime);

        if (this.showVehicle) {
            this.vehicle.update(elapsed_secs, this.MAX_SPEED, this.MAX_ANGULAR_SPEED);
        }

        for (let i = 0; i < this.supplies.length; i++) {
            this.supplies[i].update(elapsed_secs, this.scaleFactor * this.supplies[i].getFaceSize() / 2);
        }

        if (this.reloading) {
            this.time_reloading -= (t - this.lastFrameTime);
            if (this.time_reloading <= 0) {
                this.time_reloading = 0;
                this.reloading = false;
            }
        }
    }

    updateAppliedTexture() {
        this.material.setTexture(this.textures[this.selectedTexture]);
    }

    checkKeys() {
        var acc_direction = 0;
        var rot_direction = 0;

        if (this.gui.isKeyPressed("KeyP") && !this.keyP_pressed) {
            this.keyP_pressed = true;
            this.automatic_pilot = !this.automatic_pilot;

            if (this.automatic_pilot) this.vehicle.enterPilotMode(this.ORBIT_SPEED, this.ORBIT_ANGULAR_SPEED);
        } else {
            this.keyP_pressed = false;
        }


        if (!this.automatic_pilot) {
            if (this.gui.isKeyPressed("KeyW")) {
                acc_direction += 1;
            }
            if (this.gui.isKeyPressed("KeyA")) {
                rot_direction += 1;
            }
            if (this.gui.isKeyPressed("KeyS")) {
                acc_direction -= 1;
            }
            if (this.gui.isKeyPressed("KeyD")) {
                rot_direction -= 1;
            }

            if (this.showVehicle) {
                this.vehicle.accelerate(acc_direction * this.SPEED * this.speedFactor, this.frictionFactor, this.MAX_SPEED, this.MIN_SPEED);

                this.vehicle.accelerate_rotation(rot_direction * this.ANGULAR_SPEED * this.rotSpeedFactor, this.frictionFactor, this.MAX_ANGULAR_SPEED, this.MIN_ANGULAR_SPEED);
            }
        }
        if (this.gui.isKeyPressed("KeyR")) {
            this.resetElements();
        }

        if (this.gui.isKeyPressed("KeyL")) {
            this.dropSupply();
        }
    }

    dropSupply() {
        if (this.supplyCounter < this.supplies.length && !this.reloading) {
            for (let i = 0; i < this.supplies.length; i++) {
                if (this.supplies[i].isInactive()) {
                    // To drop from bottom of the vehicle, there's a need to lower the Y value by the radius of the vehicle from the center to the bottom
                    // and also lower by half of the supply size
                    let y_thrown = this.vehicle.getY() - (this.vehicle.getRadiusFromCenterToBottom() + this.supplies[i].getFaceSize() / 2) * this.scaleFactor;
                    this.supplies[i].drop(this.vehicle.getX(), y_thrown, this.vehicle.getZ(), this.vehicle.getOrientation(), 0.4 * this.vehicle.getSpeed(), 0);
                    this.supplyCounter++;
                    this.time_reloading = this.RELOADING_TIME;
                    this.reloading = true;
                    break;
                }
            }
        }
    }

    resetElements() {
        if (this.showVehicle)
            this.vehicle.reset();

        for (let i = 0; i < this.supplies.length; i++) {
            this.supplies[i].reset();
        }

        this.reloading = false;
        this.time_reloading = 0;
        this.supplyCounter = 0;
    }


    display() {
        // ---- BEGIN Background, camera and axis setup
        // Clear image and depth buffer everytime we update the scene
        this.gl.viewport(0, 0, this.gl.canvas.width, this.gl.canvas.height);
        this.gl.clear(this.gl.COLOR_BUFFER_BIT | this.gl.DEPTH_BUFFER_BIT);
        // Initialize Model-View matrix as identity (no transformation
        this.updateProjectionMatrix();
        this.loadIdentity();
        // Apply transformations corresponding to the camera position relative to the origin
        this.applyViewMatrix();

        // Draw axis
        if (this.displayAxis)
            this.axis.display();

        if (this.applyBackground) {
            this.pushMatrix();
            this.lights[1].enable();
            this.lights[1].update();
            this.pushMatrix();
            this.translate(0, 24.999, 0);
            this.scale(50, 50, 50);
            this.cubemap.display();
            this.popMatrix();
            this.terrain.display();
            this.lights[1].disable();
            this.lights[1].update();
            this.popMatrix();
        }

        this.setDefaultAppearance();

        // ---- BEGIN Primitive drawing section

        this.material.apply();

        if (this.selectedObject > 0) {
            if (this.displayNormals)
                this.objects[this.selectedObject].enableNormalViz();
            else
                this.objects[this.selectedObject].disableNormalViz();

            this.objects[this.selectedObject].display();
        }

        if (this.showVehicle) {
            if (this.displayNormals)
                this.vehicle.enableNormalViz();
            else
                this.vehicle.disableNormalViz();
            this.pushMatrix();
            this.scale(this.scaleFactor, this.scaleFactor, this.scaleFactor);
            this.vehicle.display();
            this.popMatrix();

        }
        for (let i = 0; i < this.supplies.length; i++) {
            if (!this.supplies[i].isInactive()) {
                if (this.displayNormals)
                    this.supplies[i].enableNormalViz();
                else
                    this.supplies[i].disableNormalViz();

                this.pushMatrix();
                this.scale(this.scaleFactor, this.scaleFactor, this.scaleFactor);
                this.supplies[i].display();
                this.popMatrix();
            }
        }

        // ---- END Primitive drawing section
        // restore default shader (will be needed for drawing the axis in next frame)
		this.setActiveShader(this.defaultShader);
    }
}
