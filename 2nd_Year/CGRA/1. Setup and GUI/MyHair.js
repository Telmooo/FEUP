/**
 * MyHair
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyHair extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }

    initBuffers() {
        this.vertices = [
            20, 6, 0, // 0
            25, 3, 0, // 1
            25, 4, 0, // 2
            23, 8, 0, // 3
            20, 10, 0, // 4
            27, 4, 0, // 5
            25, 8, 0, // 6
            27, 1, 0, // 7
            25, 0, 0, // 8
            27, 3, 0, // 9
            30, 2, 0, // 10
            26, 4, 0, // 11
            27.7, 1, 0 // 12
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 2,
            4, 2, 3,
            4, 11, 3,
            4, 12, 3,
            1, 5, 6,
            1, 7, 5,
            1, 8, 9,
            9, 10, 5

        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
