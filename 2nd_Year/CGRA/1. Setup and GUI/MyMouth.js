/**
 * MyMouth
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyMouth extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }

    initBuffers() {
        this.vertices = [
            12, -4, -0.2, // 0
            13, -7, -0.2, // 1
            15, -3, -0.2, // 2
            16, -6, -0.2 // 3
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 2,
            1, 3, 2
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
