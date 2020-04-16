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
        this.enableTextures(true);

        //Initialize scene objects
        this.axis = new CGFaxis(this);
        this.quad = new MyQuad(this);
        this.tangram = new MyTangram(this);
        this.unitCube = new MyUnitCubeQuad(this);

        this.objects = [this.quad, this.tangram, this.unitCube];

        // Labels and ID's for object selection on MyInterface
        this.objectIDs = { 'Quad': 0 , 'Tangram': 1, 'UnitCube': 2 };

        //------ Applied Material
        this.quadMaterial = new CGFappearance(this);
        this.quadMaterial.setAmbient(0.1, 0.1, 0.1, 1);
        this.quadMaterial.setDiffuse(0.9, 0.9, 0.9, 1);
        this.quadMaterial.setSpecular(0.1, 0.1, 0.1, 1);
        this.quadMaterial.setShininess(10.0);
        this.quadMaterial.loadTexture('images/default.png');
        this.quadMaterial.setTextureWrap('REPEAT', 'REPEAT');

        this.mineBottom = new CGFappearance(this);
        this.mineBottom.setAmbient(0.1, 0.1, 0.1, 1);
        this.mineBottom.setDiffuse(0.9, 0.9, 0.9, 1);
        this.mineBottom.setSpecular(0.1, 0.1, 0.1, 1);
        this.mineBottom.setShininess(10.0);
        this.mineBottom.loadTexture('images/mineBottom.png');
        this.mineBottom.setTextureWrap('REPEAT', 'REPEAT');

        this.mineTop = new CGFappearance(this);
        this.mineTop.setAmbient(0.1, 0.1, 0.1, 1);
        this.mineTop.setDiffuse(0.9, 0.9, 0.9, 1);
        this.mineTop.setSpecular(0.1, 0.1, 0.1, 1);
        this.mineTop.setShininess(10.0);
        this.mineTop.loadTexture('images/mineTop.png');
        this.mineTop.setTextureWrap('REPEAT', 'REPEAT');

        this.mineSide = new CGFappearance(this);
        this.mineSide.setAmbient(0.1, 0.1, 0.1, 1);
        this.mineSide.setDiffuse(0.9, 0.9, 0.9, 1);
        this.mineSide.setSpecular(0.1, 0.1, 0.1, 1);
        this.mineSide.setShininess(10.0);
        this.mineSide.loadTexture('images/mineSide.png');
        this.mineSide.setTextureWrap('REPEAT', 'REPEAT');
        //------

        //------ Textures
        this.texture1 = new CGFtexture(this, 'images/board.jpg');
        this.texture2 = new CGFtexture(this, 'images/floor.png');
        this.texture3 = new CGFtexture(this, 'images/window.jpg');
        //-------

        //-------Objects connected to MyInterface
        this.selectedObject = 2;
        this.displayAxis = true;
        this.scaleFactor = 5;
        this.selectedTexture = -1;
        this.selectedFilter = 0;
        this.cubeMineTex = false;
        this.wrapS = 0;
        this.wrapT = 0;

        this.textures = [this.texture1, this.texture2, this.texture3];
        this.texCoords = [0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0];
        this.wrappingMethods = ['REPEAT', 'CLAMP_TO_EDGE', 'MIRRORED_REPEAT'];

        this.textureIds = { 'Board': 0, 'Floor': 1, 'Window': 2 };
        this.texFilterIds = { 'Linear': 0, 'Nearest': 1 };
        this.wrappingS = { 'Repeat': 0, 'Clamp to edge': 1, 'Mirrored repeat': 2 };
        this.wrappingT = { 'Repeat': 0, 'Clamp to edge': 1, 'Mirrored repeat': 2 };

      }

    initLights() {
        this.lights[0].setPosition(5, 2, 5, 1);
        this.lights[0].setDiffuse(1.0, 1.0, 1.0, 1.0);
        this.lights[0].enable();
        this.lights[0].update();
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

    //Function that resets selected texture in quadMaterial
    updateAppliedTexture() {
        this.quadMaterial.setTexture(this.textures[this.selectedTexture]);
    }

    //Function that updates wrapping mode in quadMaterial
    updateTextureWrapping() {
        this.quadMaterial.setTextureWrap(this.wrappingMethods[this.wrapS], this.wrappingMethods[this.wrapT]);
    }

    //Function that updates texture coordinates in MyQuad
    updateTexCoords() {
        this.quad.updateTexCoords(this.texCoords);
    }

    updateCubeMineTexture() {
        if (this.cubeMineTex) {
            if (this.selectedObject == this.objectIDs['UnitCube']) {
                this.unitCube.changeMaterial(0, this.mineBottom); // change bottom material
                this.unitCube.changeMaterial(1, this.mineTop); // change top material
                this.unitCube.changeMaterial(2, this.mineSide); // change side material
                this.unitCube.changeMaterial(3, this.mineSide); // change side material
                this.unitCube.changeMaterial(4, this.mineSide); // change side material
                this.unitCube.changeMaterial(5, this.mineSide); // change side material
            }
        } else {
            for (let i = 0; i < 6; i++) {
                this.unitCube.changeMaterial(i, undefined);
            }
        }
    }

    updateTextureFiltering() {
        if (typeof this.objects[this.selectedObject].changeFilter == "function")
            this.objects[this.selectedObject].changeFilter(this.selectedFilter);
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

        this.scale(this.scaleFactor, this.scaleFactor, this.scaleFactor);

        // ---- BEGIN Primitive drawing section
        this.quadMaterial.apply();

        this.objects[this.selectedObject].display();


        // ---- END Primitive drawing section
    }
}
