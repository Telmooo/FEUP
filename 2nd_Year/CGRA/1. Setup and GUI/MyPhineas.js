/**
 * MyPepega
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyPhineas extends CGFobject {
    constructor(scene) {
        super(scene);
        this.initBuffers();
        this.ear = new MyCircle(this.scene, 1.4, 18, -3, 0);
        this.leftEye = new MyCircle(this.scene, 1.5, 10, 1, -0.3);
        this.leftPupil = new MyCircle(this.scene, 0.4, 10.5, 1.1, -0.2);
        this.rightEye = new MyCircle(this.scene, 1.8, 13, 1.4, 0.3);
        this.rightPupil = new MyCircle(this.scene, 0.4, 13.5, 1.3, 0.4);
        this.hair = new MyHair(this.scene);
        this.teeth = new MyTeeth(this.scene);
        this.mouth = new MyMouth(this.scene);
        this.tongue = new MyTongue(this.scene);
        this.eyebrows = new MyEyebrows(this.scene);
        this.initMaterials();
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

    initMaterials() {
        // Skin Color
        this.skin = new CGFappearance(this.scene);
        this.skin.setAmbient(0.9960, 0.8627, 0.7647, 1.0);
        this.skin.setDiffuse(0.9960, 0.8627, 0.7647, 1.0);
        this.skin.setSpecular(0.9960, 0.8627, 0.7647, 1.0);
        this.scene.setShininess(10.0);

        // White Color
        this.white = new CGFappearance(this.scene);
        this.white.setAmbient(1.0, 1.0, 1.0, 1.0);
        this.white.setDiffuse(1.0, 1.0, 1.0, 1.0);
        this.white.setSpecular(1.0, 1.0, 1.0, 1.0);
        this.scene.setShininess(10.0);

        // Eye Color
        this.eye_color = new CGFappearance(this.scene);
        this.eye_color.setAmbient(0.0549, 0.28235, 0.4314, 1.0);
        this.eye_color.setDiffuse(0.0549, 0.28235, 0.4314, 1.0);
        this.eye_color.setSpecular(0.0549, 0.28235, 0.4314, 1.0);
        this.eye_color.setShininess(10.0);

        // Hair Color
        this.hair_color = new CGFappearance(this.scene);
        this.hair_color.setAmbient(0.9333, 0.3686, 0.2745, 1.0);
        this.hair_color.setDiffuse(0.9333, 0.3686, 0.2745, 1.0);
        this.hair_color.setSpecular(0.9333, 0.3686, 0.2745, 1.0);
        this.hair_color.setShininess(10.0);

        // Mouth Color
        this.mouth_color = new CGFappearance(this.scene);
        this.mouth_color.setAmbient(0.7255, 0.2039, 0.1294, 1.0);
        this.mouth_color.setDiffuse(0.7255, 0.2039, 0.1294, 1.0);
        this.mouth_color.setSpecular(0.7255, 0.2039, 0.1294, 1.0);
        this.mouth_color.setShininess(10.0);

        // Tongue Color
        this.tongue_color = new CGFappearance(this.scene);
        this.tongue_color.setAmbient(0.9254, 0.5882, 0.4901, 1.0);
        this.tongue_color.setDiffuse(0.9254, 0.5882, 0.4901, 1.0);
        this.tongue_color.setSpecular(0.9254, 0.5882, 0.4901, 1.0);
        this.tongue_color.setShininess(10.0);
    }

    display() {
        this.skin.apply();
        super.display();
        this.ear.display();
        this.white.apply();
        this.leftEye.display();
        this.rightEye.display();
        this.eye_color.apply();
        this.leftPupil.display();
        this.rightPupil.display();
        this.hair_color.apply();
        this.hair.display();
        this.eyebrows.display();
        this.white.apply()
        this.teeth.display();
        this.mouth_color.apply();
        this.mouth.display();
        this.tongue_color.apply();
        this.tongue.display();
    }
}
