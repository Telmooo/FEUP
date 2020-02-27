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

        //Checkbox element in GUI for axis display
        this.gui.add(this.scene, 'displayAxis').name('Display Axis');

        //Slider element in GUI
        this.gui.add(this.scene, 'scaleFactor', 0.1, 5).name('Scale Factor');

        this.gui.add(this.scene, 'displayTangram').name('Display Tangram');

        this.gui.add(this.scene, 'displayUnitCube').name('Display UCube');

        this.gui.add(this.scene, 'displayComposition').name('Display Comp');

        this.gui.add(this.scene, 'displayQuad').name('Display Quad');

        this.gui.add(this.scene, 'displayUnitCubeQ').name('Display UCubeQ');

        this.gui.add(this.scene, 'displayCompositionQ').name('Display CompQ');

        return true;
    }
}
