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

        // Dropdown for objects
        this.gui.add(this.scene, 'selectedObject', this.scene.objectIDs).name('Selected Object');

        //Dropdown for textures
        this.gui.add(this.scene, 'selectedTexture', this.scene.textureIds).name('Selected Texture').onChange(this.scene.updateAppliedTexture.bind(this.scene));

        //Dropdown for texture filtering
        this.gui.add(this.scene, 'selectedFilter', this.scene.texFilterIds).name('Selected Filter').onChange(this.scene.updateTextureFiltering.bind(this.scene));

        // Minecraft Cube Texture
        this.gui.add(this.scene, 'cubeMineTex').name('Cube Mine Texture').onChange(this.scene.updateCubeMineTexture.bind(this.scene));
        //Dropdown for wrapping (S)
        this.gui.add(this.scene, 'wrapS', this.scene.wrappingS).name('Wrap S').onChange(this.scene.updateTextureWrapping.bind(this.scene));
        this.gui.add(this.scene, 'wrapT', this.scene.wrappingT).name('Wrap T').onChange(this.scene.updateTextureWrapping.bind(this.scene));

        //Groups for Texture coordinates per vertex (MyQuad)
        var f0 = this.gui.addFolder('Top Left Coords')
        f0.add(this.scene.texCoords, '6', -5.0, 5.0, 0.1).name('S Coord').onChange(this.scene.updateTexCoords.bind(this.scene)).step(0.001);
        f0.add(this.scene.texCoords, '7', -5.0, 5.0, 0.1).name('T Coord').onChange(this.scene.updateTexCoords.bind(this.scene)).step(0.001);
        var f1 = this.gui.addFolder('Top Right Coords')
        f1.add(this.scene.texCoords, '4', -5.0, 5.0, 0.1).name('S Coord').onChange(this.scene.updateTexCoords.bind(this.scene)).step(0.001);
        f1.add(this.scene.texCoords, '5', -5.0, 5.0, 0.1).name('T Coord').onChange(this.scene.updateTexCoords.bind(this.scene)).step(0.001);
        var f2 = this.gui.addFolder('Bottom Left Coords')
        f2.add(this.scene.texCoords, '0', -5.0, 5.0, 0.1).name('S Coord').onChange(this.scene.updateTexCoords.bind(this.scene)).step(0.001);
        f2.add(this.scene.texCoords, '1', -5.0, 5.0, 0.1).name('T Coord').onChange(this.scene.updateTexCoords.bind(this.scene)).step(0.001);
        var f3 = this.gui.addFolder('Bottom Right Coords')
        f3.add(this.scene.texCoords, '2', -5.0, 5.0, 0.1).name('S Coord').onChange(this.scene.updateTexCoords.bind(this.scene)).step(0.001);
        f3.add(this.scene.texCoords, '3', -5.0, 5.0, 0.1).name('T Coord').onChange(this.scene.updateTexCoords.bind(this.scene)).step(0.001);

        return true;
    }
}
