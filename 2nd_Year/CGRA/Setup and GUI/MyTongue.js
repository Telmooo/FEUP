/**
 * MyTongue
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTongue extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }

    initBuffers() {
        this.vertices = [
            13, -7, -0.15, // 0
            16, -5, -0.15, // 1
            15, -4, -0.15, // 2
        ];
        // Counter-clockwise reference of vertices
        this.indices = [
            0, 1, 2
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
