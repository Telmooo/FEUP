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
        this.diamond = new MyDiamond(this);
        this.triangle = new MyTriangle(this);
        this.parallelogram = new MyParallelogram(this);
        this.triangleSmall = new MyTriangleSmall(this);
        this.triangleBig = new MyTriangleBig(this);
        this.circle = new MyCircle(this, 2, 0, 0, 0);

        // Phineas
        this.phineas = new MyPhineas(this);
        this.ear = new MyCircle(this, 1.4, 18, -3, 0);
        this.leftEye = new MyCircle(this, 1.5, 10, 1, -0.3);
        this.leftPupil = new MyCircle(this, 0.4, 10.5, 1.1, -0.2);
        this.rightEye = new MyCircle(this, 1.8, 13, 1.4, 0.3);
        this.rightPupil = new MyCircle(this, 0.4, 13.5, 1.3, 0.4);
        this.hair = new MyHair(this);
        this.teeth = new MyTeeth(this);
        this.mouth = new MyMouth(this);
        this.tongue = new MyTongue(this);
        this.eyebrows = new MyEyebrows(this);

        //Objects connected to MyInterface
        this.displayAxis = false;
        this.scaleFactor = 1;
        this.displayDiamond = false;
        this.displayTriangle = false;
        this.displayParallelogram = false;
        this.displayTriangleSmall = false;
        this.displayTriangleBig = false;
        this.displayCircle = false;
        this.displayPhineas = true;
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
        if (this.displayDiamond)
            this.diamond.display();

        if (this.displayTriangle)
            this.triangle.display();

        if (this.displayParallelogram)
            this.parallelogram.display();

        if (this.displayTriangleSmall)
            this.triangleSmall.display();

        if (this.displayTriangleBig)
            this.triangleBig.display();

        if (this.displayCircle)
            this.circle.display();

        if (this.displayPhineas) {
            this.setAmbient(0.9960, 0.8627, 0.7647, 1.0);
            this.setDiffuse(0.9960, 0.8627, 0.7647, 1.0);
            this.setSpecular(0.9960, 0.8627, 0.7647, 1.0);
            this.setShininess(10.0);
            this.phineas.display();
            this.ear.display();
            this.setAmbient(1.0, 1.0, 1.0, 1.0);
            this.setDiffuse(1.0, 1.0, 1.0, 1.0);
            this.setSpecular(1.0, 1.0, 1.0, 1.0);
            this.setShininess(10.0);
            this.leftEye.display();
            this.rightEye.display();
            this.setAmbient(0.0549, 0.28235, 0.4314, 1.0);
            this.setDiffuse(0.0549, 0.28235, 0.4314, 1.0);
            this.setSpecular(0.0549, 0.28235, 0.4314, 1.0);
            this.setShininess(10.0);
            this.leftPupil.display();
            this.rightPupil.display();
            this.setAmbient(0.9333, 0.3686, 0.2745, 1.0);
            this.setDiffuse(0.9333, 0.3686, 0.2745, 1.0);
            this.setSpecular(0.9333, 0.3686, 0.2745, 1.0);
            this.setShininess(10.0);
            this.hair.display();
            this.eyebrows.display();
            this.setAmbient(1.0, 1.0, 1.0, 1.0);
            this.setDiffuse(1.0, 1.0, 1.0, 1.0);
            this.setSpecular(1.0, 1.0, 1.0, 1.0);
            this.setShininess(10.0);
            this.teeth.display();
            this.setAmbient(0.7255, 0.2039, 0.1294, 1.0);
            this.setDiffuse(0.7255, 0.2039, 0.1294, 1.0);
            this.setSpecular(0.7255, 0.2039, 0.1294, 1.0);
            this.setShininess(10.0);
            this.mouth.display();
            this.setAmbient(0.9254, 0.5882, 0.4901, 1.0);
            this.setDiffuse(0.9254, 0.5882, 0.4901, 1.0);
            this.setSpecular(0.9254, 0.5882, 0.4901, 1.0);
            this.setShininess(10.0);
            this.tongue.display();
        }


        // ---- END Primitive drawing section
    }
}
