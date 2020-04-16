/**
* MyVehicle
* @constructor
*/
class MyVehicle extends CGFobject {
    constructor(scene, slices) {
        super(scene);
        this.slices = slices;
        this.initBuffers();
        this.orientation = 0;
        this.speed = 0;
        this.x = 0;
        this.y = 0;
        this.z = 0;
    }

    initBuffers() {
        this.vertices = [];
        this.indices = [];
        this.normals = [];
        this.texCoords = [];

        var dangle = (2 * Math.PI) / this.slices, angle = 0;
        var dTexCoord = 1 / this.slices, texCoord = 1;

        for (let i = 0; i < this.slices; i++) {

            let sa = Math.sin(angle);
            let saa = Math.sin(angle + dangle);
            let ca = Math.cos(angle);
            let caa = Math.cos(angle + dangle);

            this.vertices.push(0, 0, 0.5);
            this.vertices.push(ca, sa, -0.5);
            this.vertices.push(caa, saa, -0.5);

            // cross product
            let normal = [
                0.5*saa-0.5*sa,
                0.5*ca-0.5*caa,
                ca*saa-caa*sa
            ];

            let norm = Math.sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);

            normal[0] /= norm;
            normal[1] /= norm;
            normal[2] /= norm;

            this.normals.push(...normal);
            this.normals.push(...normal);
            this.normals.push(...normal);

            this.indices.push(3 * i, 3 * i + 1, 3 * i + 2);

            this.texCoords.push(0.5, 0);
            this.texCoords.push(texCoord, 1);
            this.texCoords.push(texCoord - dTexCoord, 1);

            angle += dangle;
            texCoord -= dTexCoord;
        }

        this.primitiveType = this.scene.gl.TRIANGLES;
        this.initGLBuffers();
    }

    display() {

        this.scene.pushMatrix();

        this.scene.translate(this.x, this.y, this.z);
        this.scene.rotate(this.orientation, 0, 1, 0);

        super.display();

        this.scene.popMatrix();
    }

    /**
     * Update vehicle position
     */
    update() {
        let x_speed = Math.sin(this.orientation) * this.speed;
        let z_speed = Math.cos(this.orientation) * this.speed;

        this.x += x_speed;
        this.z += z_speed;

        console.log(this.x);
                console.log(this.z);
    }

    turn(angle) {
        // restrict angle to 0-359 degrees
        this.orientation = (this.orientation + angle + Math.PI * 2) % (Math.PI * 2);
    }

    accelerate(increment, friction_coef, absolute_max_speed, absolute_min_speed) {
        let friction_acc = Physics.friction(friction_coef);

        let new_speed = this.speed + increment;
        new_speed = Math.max(-absolute_max_speed, new_speed);
        new_speed = Math.min(absolute_max_speed, new_speed);
        this.speed = new_speed;

        if (this.speed > 0) {
            new_speed = this.speed - friction_acc;
            if (new_speed < absolute_min_speed) {
                new_speed = 0;
            }
            this.speed = new_speed;
        } else if (this.speed < 0) {
            new_speed = this.speed + friction_acc;
            if (new_speed > -absolute_min_speed) {
                new_speed = 0;
            }
            this.speed = new_speed;
        }
    }

    reset() {
        this.orientation = 0;
        this.speed = 0;
        this.x = 0;
        this.y = 0;
        this.z = 0;
    }
}
