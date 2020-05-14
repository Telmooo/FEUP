/**
 * MyTriangle
 * @constructor
 * @param {CGFscene} scene - Reference to MyScene object
 */
class MyTriangle extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
    }
    initBuffers() {
        /*
            C
            | \
        0-> A - B
        */
        this.vertices = [
            -0.5, -0.5, 0,  // A (0)
            0.5, -0.5, 0,   // B (1)
            -0.5, 0.5, 0,    // C (2)
            -0.5, -0.5, 0,  // A' (3)
            0.5, -0.5, 0,   // B' (4)
            -0.5, 0.5, 0    // C' (5)
        ];
        // Double-sided
        this.indices = [
            0, 1, 2,
            3, 5, 4
        ];

        this.normals = [
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,
            0, 0, -1,
            0, 0, -1,
            0, 0, -1
		];

        this.texCoords = [
            0.0, 1.0,
            1.0, 1.0,
            0.0, 0.0,
            0.0, 1.0,
            1.0, 1.0,
            0.0, 0.0
        ];

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }

    setFillMode() {
        this.primitiveType=this.scene.gl.TRIANGLES;
    }

    setLineMode() {
        this.primitiveType=this.scene.gl.LINES;
    };
}
