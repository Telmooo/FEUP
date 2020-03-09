/**
 * MySphere
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MySphere extends CGFobject {
    constructor(scene, lonDivisions, latDivisions, radius, centerX, centerY, centerZ) {
        super(scene);
        this.lonDivisions = lonDivisions;
        this.latDivisions = latDivisions;
        this.radius = radius;
        this.centerX = centerX;
        this.centerY = centerY;
        this.centerZ = centerZ;
        this.initBuffers();
    }

    initBuffers() {

        this.vertices = [
        ];

        this.normals = [
        ];

        var dlon = (Math.PI * 2)/this.lonDivisions, lon = 0;
        var dlat = Math.PI/this.latDivisions, lat = 0;
        var x, y, z;

        for (var i = 0; i <= this.latDivisions; i++, lat += dlat) {
            for (var j = 0; j <= this.lonDivisions; j++, lon += dlon) {
                x = this.centerX + this.radius * Math.cos(lon) * Math.sin(lat);
                y = this.centerY + this.radius * Math.sin(lon) * Math.sin(lat);
                z = this.centerZ + this.radius * Math.cos(lat);

                this.vertices.push(x); this.vertices.push(y); this.vertices.push(z);

                this.normals.push(x); this.normals.push(y); this.normals.push(z);
            }
        }

        this.indices = [
        ];
        var A, D;
        for (var i = 0; i < this.latDivisions; i++, lat += dlat) {
            for (var j = 0; j < this.lonDivisions; j++, lon += dlon) {
                /*
                    D - - - C
                    | \     |
                    |	\	|
                    |     \ |
                    A - - - B
                    Points[i][j] : i -> longitude && j -> latitude
                    A = [i  ][j  ]
                    B = [i+1][j  ]
                    C = [i+1][j+1]
                    D = [i  ][j+1]

                    B->A->D && C->B->D (clock-wise direction for sphere faces to point outwards)
                */
                A = i * (this.latDivisions+1) + j; // B = A + 1
                D = A + (this.lonDivisions+1); // C = D + 1

                this.indices.push(A+1); // B
                this.indices.push(A);
                this.indices.push(D);

                this.indices.push(D+1); // C
                this.indices.push(A+1); // B
                this.indices.push(D);
            }
        }

        this.primitiveType = this.scene.gl.TRIANGLES;

        this.initGLBuffers();
    }
}
