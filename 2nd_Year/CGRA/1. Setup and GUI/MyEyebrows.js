/**
 * MyEyebrows
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyEyebrows extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }

    initBuffers() {
        this.vertices = [
            9.5, 3.4, 0,
            10.5, 3.8, 0,
            10, 3.9, 0,
            12.5, 4.3, 0,
            13.5, 4, 0,
            13, 4.5, 0
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 2,
            3, 4, 5
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
