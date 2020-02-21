/**
 * MyPepega
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyPhineas extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }

    initBuffers() {
        this.vertices = [
            0, 0, 0,        // 0
            10, -5, 0,      // 1
            15, -1, 0,      // 2
            25, 3, 0,       // 3
            18, -3, 0,      // 4
            15, -5, 0,      // 5
            15, -10, 0,      // 6
            12, -7, 0       // 7
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 3,
            2, 4, 3,
            2, 5, 4,
            7, 6, 4
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
