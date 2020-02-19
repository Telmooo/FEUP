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

        // Checkbox element in GUI for diamond display
        this.gui.add(this.scene, 'displayDiamond', 0.1, 5).name('Display Diamond');

        // Checkbox element in GUI for triangle display
        this.gui.add(this.scene, 'displayTriangle', 0.1, 5).name('Display Triangle');

        // Checkbox element in GUI for parallelogram display
        this.gui.add(this.scene, 'displayParallelogram', 0.1, 5).name('Display Parallelogram');

        // Checkbox element in GUI for small triangle display
        this.gui.add(this.scene, 'displayTriangleSmall', 0.1, 5).name('Display Small Triangle');

        // Checkbox element in GUI for big triangle display
        this.gui.add(this.scene, 'displayTriangleBig', 0.1, 5).name('Display Big Triangle');

        // Checkbox element in GUI for big triangle display
        this.gui.add(this.scene, 'displayCircle', 0.1, 5).name('Display Circle');

        return true;
    }
}
