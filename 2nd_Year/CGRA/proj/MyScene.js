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
        this.sphere = new MySphere(this, 16, 8);
        this.cylinder = new MyCylinder(this, 16);
        this.cubemap = new MyCubeMap(this);
        this.vehicle = new MyVehicle(this, 4);

        this.objects=[
            undefined,
			this.sphere,
			this.cylinder,
            this.cubemap
		];

		// Object interface variables
		this.objectList = {
            'None': 0,
			'Sphere': 1,
			'Cylinder': 2,
            'Cubemap': 3
		};

        //------ Textures
        this.earth = new CGFtexture(this, 'images/earth.jpg');

        this.textures = [
            undefined,
            new CGFtexture(this, 'images/earth.jpg'),
            new CGFtexture(this, 'images/cubemap.png')
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
            ]
        ];

        this.textureList = {
            'None': 0,
            'Earth': 1,
            'Background': 2
        };

        this.backgroundList = {
            'None': 0,
            'Cloudy Day': 1
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

        this.showVehicle = false;
        this.MIN_SPEED = 0.05;
        this.MAX_SPEED = 4;
        this.SPEED = 0.5;
        this.ANGULAR_SPEED = 0.1;
        this.speedFactor = 1.0;
        this.scaleFactor = 1.0;
        this.rotSpeedFactor = 1.0;
        this.frictionFactor = 0.05;
        this.reset = ()=>this.vehicle.reset();
    }
    initLights() {
        this.lights[0].setPosition(15, 2, 5, 1);
        this.lights[0].setDiffuse(1.0, 1.0, 1.0, 1.0);
        this.lights[0].enable();
        this.lights[0].update();
        this.lights[1].setPosition(0, 0, 0, 0);
        this.lights[1].setAmbient(1.0, 1.0, 1.0, 1.0);
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

        if (this.showVehicle) {
            this.vehicle.update();
        }
    }

    updateAppliedTexture() {
        this.material.setTexture(this.textures[this.selectedTexture]);
    }

    checkKeys() {
        var acc_direction = 0;
        var rot_direction = 0;

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
        if (this.gui.isKeyPressed("KeyR")) {
            this.vehicle.reset();
        }

        if (this.showVehicle) {
            this.vehicle.accelerate(acc_direction * this.SPEED * this.speedFactor, this.frictionFactor, this.MAX_SPEED, this.MIN_SPEED);

            if (rot_direction != 0) {
                this.vehicle.turn(rot_direction * this.ANGULAR_SPEED * this.rotSpeedFactor);
            }
        }

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
            this.scale(50, 50, 50);
            this.cubemap.display();
            this.lights[1].disable();
            this.lights[1].update();
            this.popMatrix();
        }

        this.setDefaultAppearance();

        // ---- BEGIN Primitive drawing section


        if (this.applyMaterial)
            this.material.apply();

        if (this.selectedObject > 0) {
            if (this.displayNormals)
                this.objects[this.selectedObject].enableNormalViz();
            else
                this.objects[this.selectedObject].disableNormalViz();

            this.objects[this.selectedObject].display();
        }

        if (this.showVehicle) {
            this.pushMatrix();
            this.scale(this.scaleFactor, this.scaleFactor, this.scaleFactor);
            this.vehicle.display();
            this.popMatrix();
        }

        // ---- END Primitive drawing section
    }
}
