/**
* MyInterface
* @constructor
*/
class MyInterface extends CGFinterface {
    constructor() {
        super();
    }

    init(application) {
        // call CGFinterface init
        super.init(application);
        // init GUI. For more information on the methods, check:
        // http://workshop.chromeexperiments.com/examples/gui
        this.gui = new dat.GUI();

        var obj = this;

        //Checkbox element in GUI
        this.gui.add(this.scene, 'displayAxis').name('Display Axis');

        this.gui.add(this.scene, 'selectedObject', this.scene.objectList).name('Object Type');

        this.gui.add(this.scene, 'displayNormals').name("Display normals");

        this.gui.add(this.scene, 'applyMaterial').name("Apply Material");

        this.gui.add(this.scene, 'selectedTexture', this.scene.textureList).name('Texture').onChange(this.scene.updateAppliedTexture.bind(this.scene));

        var background_folder = this.gui.addFolder("Background Properties");

        background_folder.add(this.scene, 'applyBackground').name("Apply Background");

        background_folder.add(this.scene, 'selectedBackground', this.scene.backgroundList).name('Background').onChange(this.scene.updateBackgroundTexture.bind(this.scene));

        //Dropdown for texture filtering
        background_folder.add(this.scene, 'selectedFilter', this.scene.backgroundFilterIds).name('Selected Filter').onChange(this.scene.updateBackgroundFiltering.bind(this.scene));

        var vehicle_folder = this.gui.addFolder("Vehicle Properties");

        vehicle_folder.add(this.scene, 'showVehicle').name("Show Vehicle");

        vehicle_folder.add(this.scene, 'speedFactor', 0.1, 3).step(0.1).name("Speed Factor");

        vehicle_folder.add(this.scene, 'rotSpeedFactor', 0.1, 5).step(0.1).name("Rotation Speed Factor");

        vehicle_folder.add(this.scene, 'scaleFactor', 0.5, 3).step(0.1).name("Scale Factor");

        vehicle_folder.add(this.scene, 'frictionFactor', 0.01, 0.5).step(0.01).name("Friction Factor");

        vehicle_folder.add(this.scene, 'reset').name("Reset Vehicle");

        vehicle_folder.open();

        this.initKeys();

        return true;
    }

    initKeys() {
        // create reference from the scene to the GUI
        this.scene.gui=this;
        // disable the processKeyboard function
        this.processKeyboard=function(){};
        // create a named array to store which keys are being pressed
        this.activeKeys={};
    }

    processKeyDown(event) {
        // called when a key is pressed down
        // mark it as active in the array
        this.activeKeys[event.code]=true;
    };

    processKeyUp(event) {
        // called when a key is released, mark it as inactive in the array
        this.activeKeys[event.code]=false;
    };
    isKeyPressed(keyCode) {
        // returns true if a key is marked as pressed, false otherwise
        return this.activeKeys[keyCode] || false;
    }

}
