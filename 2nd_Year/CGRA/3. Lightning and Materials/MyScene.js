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
        this.initMaterials();

        //Background color
        this.gl.clearColor(0.0, 0.0, 0.0, 1.0);

        this.gl.clearDepth(100.0);
        this.gl.enable(this.gl.DEPTH_TEST);
        this.gl.enable(this.gl.CULL_FACE);
        this.gl.depthFunc(this.gl.LEQUAL);

        //Initialize scene objects
        this.axis = new CGFaxis(this);
        this.plane = new MyPlane(this, 5);
        this.cone = new MyCone(this, 3, 1);
        this.pyramid = new MyPyramid(this, 3, 1);
        this.tangram = new MyTangram(this);
        this.unitCube = new MyUnitCube(this);
        this.cylinder = new MyCylinder(this, 100, 1, 0, 0, 0, 1);
        this.sphere = new MySphere(this, 50, 50, 1, 0, 0, 0);

        this.objects = [this.plane, this.pyramid, this.cone, this.tangram, this.unitCube, this.cylinder, this.sphere];

        // Labels and ID's for object selection on MyInterface
        this.objectIDs = { 'Plane': 0 , 'Pyramid': 1, 'Cone': 2, 'Tangram': 3, 'UnitCube': 4, 'Cylinder': 5, 'Sphere': 6};

        //Other variables connected to MyInterface
        this.selectedObject = 0;
        this.selectedMaterial = 0;
        this.displayAxis = true;
        this.displayNormals = false;
        this.objectComplexity = 0.5;
        this.scaleFactor = 2.0;
        this.globalLight = 0.3;
        this.tangramCustom = false;

    }
    initLights() {
        this.setGlobalAmbientLight(0.3, 0.3, 0.3, 1.0);

        this.lights[0].setPosition(2.0, 2.0, -1.0, 1.0);
        this.lights[0].setDiffuse(1.0, 1.0, 1.0, 1.0);
        this.lights[0].setSpecular(1.0, 1.0, 1.0, 1.0);
        this.lights[0].disable();
        this.lights[0].setVisible(true);
        this.lights[0].update();

        this.lights[1].setPosition(0.0, -1.0, 2.0, 1.0);
        this.lights[1].setDiffuse(1.0, 1.0, 1.0, 1.0);
        this.lights[1].setSpecular(1.0, 1.0, 0.0, 1.0);
        this.lights[1].disable();
        this.lights[1].setVisible(true);
        this.lights[1].update();
    }
    initCameras() {
        this.camera = new CGFcamera(0.4, 0.1, 500, vec3.fromValues(10, 10, 10), vec3.fromValues(0, 0, 0));
    }

    updateCustomMaterial() {
        var rgba;

        this.customMaterial.setAmbient(...hexToRgbA(this.customMaterialValues['Ambient']));
        this.customMaterial.setDiffuse(...hexToRgbA(this.customMaterialValues['Diffuse']));
        this.customMaterial.setSpecular(...hexToRgbA(this.customMaterialValues['Specular']));

        this.customMaterial.setShininess(this.customMaterialValues['Shininess']);
    };

    updateObjectComplexity(){
        if (typeof this.objects[this.selectedObject].updateBuffers == "function")
            this.objects[this.selectedObject].updateBuffers(this.objectComplexity);
    }

    updateGlobalLight() {
        this.setGlobalAmbientLight(this.globalLight, this.globalLight, this.globalLight, 1.0);
    }

    updateTangramCustom() {
        if (this.tangramCustom)
            this.tangram.green = this.customMaterial; // put diamond material to custom
        else
            this.tangram.initMaterials(); // reset materials
    }


    initMaterials() {
        // Red Ambient (no diffuse, no specular)
        this.material1 = new CGFappearance(this);
        this.material1.setAmbient(1, 0, 0, 1.0);
        this.material1.setDiffuse(0, 0, 0, 1.0);
        this.material1.setSpecular(0, 0, 0, 1.0);
        this.material1.setShininess(10.0);

        // Red Diffuse (no ambient, no specular)
        this.material2 = new CGFappearance(this);
        this.material2.setAmbient(0.0, 0.0, 0.0, 1.0);
        this.material2.setDiffuse(1, 0, 0, 1.0);
        this.material2.setSpecular(0, 0, 0, 1.0);
        this.material2.setShininess(10.0);

        // Red Specular (no ambient, no diffuse)
        this.material3 = new CGFappearance(this);
        this.material3.setAmbient(0, 0, 0, 1.0);
        this.material3.setDiffuse(0, 0, 0, 1.0);
        this.material3.setSpecular(1, 0, 0, 1.0);
        this.material3.setShininess(10.0);

        // Wood Color
        let wood_color = hexToRgbA("#e8af6a");
        this.wood = new CGFappearance(this);
        this.wood.setAmbient(...wood_color);
        this.wood.setDiffuse(...wood_color);
        this.wood.setSpecular(0.0, 0.0, 0.0, 1.0);
        this.wood.setShininess(10.0);

        // Custom material (can be changed in the interface)
        // initially midrange values on ambient, diffuse and specular, on R, G and B respectively

        this.customMaterialValues = {
            'Ambient': '#0000ff',
            'Diffuse': '#ff0000',
            'Specular': '#000000',
            'Shininess': 10
        }
        this.customMaterial = new CGFappearance(this);

        this.updateCustomMaterial();

        this.materials = [this.material1, this.material2, this.material3, this.customMaterial, this.wood];

        // Labels and ID's for object selection on MyInterface
        this.materialIDs = {'Red Ambient': 0, 'Red Diffuse': 1, 'Red Specular': 2, 'Custom': 3, 'Wood': 4 };
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

        // lights
        this.lights[0].update();
        this.lights[1].update();

        // Draw axis
        if (this.displayAxis)
            this.axis.display();

        // global light
        this.updateGlobalLight();

        // ---- BEGIN Primitive drawing section

        this.materials[this.selectedMaterial].apply();

        this.pushMatrix();
        this.scale(this.scaleFactor,this.scaleFactor,this.scaleFactor);

        if (this.displayNormals)
            this.objects[this.selectedObject].enableNormalViz();
        else
            this.objects[this.selectedObject].disableNormalViz();

        this.objects[this.selectedObject].display();
        this.popMatrix();
        // ---- END Primitive drawing section
    }
}
