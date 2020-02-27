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

        //Initialize scene objects
        this.axis = new CGFaxis(this);
        this.tangram = new MyTangram(this);
        this.unitCube = new MyUnitCube(this);

        //Objects connected to MyInterface
        this.displayAxis = true;
        this.scaleFactor = 1;
        this.displayTangram = false;
        this.displayUnitCube = false;
        this.displayComposition = true;
    }
    initLights() {
        this.lights[0].setPosition(15, 2, 5, 1);
        this.lights[0].setDiffuse(1.0, 1.0, 1.0, 1.0);
        this.lights[0].enable();
        this.lights[0].update();
    }
    initCameras() {
        this.camera = new CGFcamera(0.4, 0.1, 500, vec3.fromValues(15, 15, 15), vec3.fromValues(0, 0, 0));
    }
    setDefaultAppearance() {
        this.setAmbient(1, 1, 1, 1.0);
        this.setDiffuse(0.2, 0.4, 0.8, 1.0);
        this.setSpecular(0.2, 0.4, 0.8, 1.0);
        this.setShininess(10.0);
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

        this.setDefaultAppearance();

        var sca = [this.scaleFactor, 0.0, 0.0, 0.0,
                    0.0, this.scaleFactor, 0.0, 0.0,
                    0.0, 0.0, this.scaleFactor, 0.0,
                    0.0, 0.0, 0.0, 1.0];

        this.multMatrix(sca);

        // ---- BEGIN Primitive drawing section
        if (this.displayTangram)
            this.tangram.display();

        if (this.displayUnitCube) {
            this.pushMatrix();
            this.translate(-0.5, -0.5, -0.5);
            this.unitCube.display();
            this.popMatrix();
        }

        if (this.displayComposition) {
            this.pushMatrix();
            // ---- Rotate and Translate to put composition parallel to xOz and upper left vertice on the origin
            // ----

            // ---- Translate and Scale to create base
            this.scale(10, 10, 1);
            this.translate(-0.5, -0.5, -1.05);
            // ----

            // ---- White Color
            this.setAmbient(1.0, 1.0, 1.0, 1.0);
    		this.setDiffuse(1.0, 1.0, 1.0, 1.0);
    		this.setSpecular(1.0, 1.0, 1.0, 1.0);
    		this.setShininess(10.0);
            // ----
            this.unitCube.display();
            this.popMatrix();
            this.tangram.display();
        }

        // ---- END Primitive drawing section
    }
}
