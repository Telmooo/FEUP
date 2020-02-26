/**
 * MyTeeth
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTeeth extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }

    initBuffers() {
        this.vertices = [
            11, -4, -0.1, // 0
            11.5, -5, -0.1, // 1
            15, -3, -0.1, // 2
            16, -1.6, -0.1, // 3
            12, -6.5, -0.1, // 4
            12.5, -7, -0.1, // 5
            15, -5.5, -0.1 // 6
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 2,
            0, 2, 3,
            4, 5, 6
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
