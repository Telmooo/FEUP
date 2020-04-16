/**
 * MyTangram
 * @constructor
 * @param scene - Reference to MyScene object
 */
class MyTangram extends CGFobject {
	constructor(scene) {
		super(scene);
		this.diamond = new MyDiamond(this.scene);
		this.triangle = new MyTriangle(this.scene);
		this.parallelogram = new MyParallelogram(this.scene);
		this.triangleBig = new MyTriangleBig(this.scene);
		this.triangleSmall = new MyTriangleSmall(this.scene);
		this.initMaterials();
	}

    initMaterials() {
        // Tangram Texture
        this.texture = new CGFappearance(this.scene);
		this.texture.setAmbient(0.1, 0.1, 0.1, 1);
        this.texture.setDiffuse(0.9, 0.9, 0.9, 1);
        this.texture.setSpecular(0.1, 0.1, 0.1, 1);
        this.texture.setShininess(10.0);
        this.texture.loadTexture('images/tangram.png');
        this.texture.setTextureWrap('REPEAT', 'REPEAT');
    }

	display() {
		// Reflection over the X axis
		var x_axis_reflection = [ 1.0, 0.0, 0.0, 0.0,
								  0.0, -1.0, 0.0, 0.0,
								  0.0, 0.0, 1.0, 0.0,
								  0.0, 0.0, 0.0, 1.0
								];
		// Reflection over the Y axis
		var y_axis_reflection = [ -1.0, 0.0, 0.0, 0.0,
								  0.0, 1.0, 0.0, 0.0,
								  0.0, 0.0, 1.0, 0.0,
								  0.0, 0.0, 0.0, 1.0
								];
		// Rotation of 90º counter-clockwise direction in the Z axis
		var z_axis_ccpi_rotation = [ 0.0, 1.0, 0.0, 0.0,
								   -1.0, 0.0, 0.0, 0.0,
								   0.0, 0.0, 1.0, 0.0,
								   0.0, 0.0, 0.0, 1.0
								  ];
	    // Rotation of 90º clockwise direction in the Z axis
  		var z_axis_cpi_rotation = [ 0.0, -1.0, 0.0, 0.0,
  								    1.0, 0.0, 0.0, 0.0,
  								    0.0, 0.0, 1.0, 0.0,
  								    0.0, 0.0, 0.0, 1.0
  								  ];

		this.scene.pushMatrix();
		// ---- Red Triangle
		var red_triangle_transl = [ 1.0, 0.0, 0.0, 0.0,
									0.0, 1.0, 0.0, 0.0,
									0.0, 0.0, 1.0, 0.0,
									0.0, 3.0, 0.0, 1.0
									];
		this.scene.multMatrix(red_triangle_transl);
		this.triangleSmall.updateTexCoords([
									    0.25, 0.75,
									    0.75, 0.75,
									    0.5, 0.5
									]);

		this.texture.apply();
		this.triangleSmall.display();
		// ----

		this.scene.popMatrix();
		this.scene.pushMatrix();

		// ---- Pink Triangle
		var pink_triangle_transl = [ 1.0, 0.0, 0.0, 0.0,
								  	 0.0, 1.0, 0.0, 0.0,
								  	 0.0, 0.0, 1.0, 0.0,
								  	 0.0, 2.0, 0.0, 1.0
									];
		this.scene.multMatrix(pink_triangle_transl);
		this.scene.multMatrix(z_axis_cpi_rotation);
		this.triangle.updateTexCoords([
										0.0, 1.0,
										0.5, 1.0,
										0.0, 0.5
									]);

		this.texture.apply();
		this.triangle.display();
		// ----

		this.scene.popMatrix();
		this.scene.pushMatrix();

		// ---- Orange Triangle
	    var orange_triangle_transl = [ 1.0, 0.0, 0.0, 0.0,
								  	   0.0, 1.0, 0.0, 0.0,
								  	   0.0, 0.0, 1.0, 0.0,
								  	   1.0, 1.0, 0.0, 1.0
								       ];
	   	this.scene.multMatrix(orange_triangle_transl);
		this.scene.multMatrix(z_axis_ccpi_rotation);
		this.triangleBig.updateTexCoords([
										1.0, 1.0,
										1.0, 0.0,
										0.5, 0.5
									]);

		this.texture.apply();
		this.triangleBig.display();
		// ----

		this.scene.popMatrix();
		this.scene.pushMatrix();

		// ---- Blue Triangle
		var blue_triangle_transl = [ 1.0, 0.0, 0.0, 0.0,
								  	   0.0, 1.0, 0.0, 0.0,
								  	   0.0, 0.0, 1.0, 0.0,
								  	   -1.0, -1.0, 0.0, 1.0
								       ];
		this.scene.multMatrix(blue_triangle_transl);
		this.scene.multMatrix(z_axis_cpi_rotation);
		this.triangleBig.updateTexCoords([
										1.0, 0.0,
										0.0, 0.0,
										0.5, 0.5
									]);

		this.texture.apply();
		this.triangleBig.display();
		// ----

		this.scene.popMatrix();
		this.scene.pushMatrix();

		// ---- Yellow Parallelogram
		var yellow_parallelogram_transl = [ 1.0, 0.0, 0.0, 0.0,
								  	   		0.0, 1.0, 0.0, 0.0,
								  	   		0.0, 0.0, 1.0, 0.0,
								  	   		-1.0, -1.0, 0.0, 1.0
								       		];
		this.scene.multMatrix(yellow_parallelogram_transl);
		this.scene.multMatrix(z_axis_ccpi_rotation);
		this.parallelogram.updateTexCoords([
										1.0, 1.0,
										0.75, 0.75,
										0.25, 0.75,
										0.5, 1.0
									]);

		this.texture.apply();
		this.parallelogram.display();
		// ----

		this.scene.popMatrix();
		this.scene.pushMatrix();

		// ----  Green Diamond
		var green_diamond_transl = [ 1.0, 0.0, 0.0, 0.0,
								  	 0.0, 1.0, 0.0, 0.0,
								  	 0.0, 0.0, 1.0, 0.0,
								  	 1.0, -2.0, 0.0, 1.0
								     ];
		this.scene.multMatrix(green_diamond_transl);
		this.diamond.updateTexCoords([
										0.0, 0.5,
										0.25, 0.75,
										0.5, 0.5,
										0.25, 0.25
									]);

		this.texture.apply();
		this.diamond.display();
		// ----

		this.scene.popMatrix();
		this.scene.pushMatrix();

		// ----  Purple Triangle
		var purple_triangle_transl = [ 1.0, 0.0, 0.0, 0.0,
									   0.0, 1.0, 0.0, 0.0,
									   0.0, 0.0, 1.0, 0.0,
									   2.0, -3.0, 0.0, 1.0
									   ];
		this.scene.multMatrix(purple_triangle_transl);
		this.scene.multMatrix(z_axis_ccpi_rotation);
		this.triangleSmall.updateTexCoords([
										0.0, 0.0,
										0.0, 0.5,
										0.25, 0.25
									]);

		this.texture.apply();
		this.triangleSmall.display();
		// ----
		this.scene.popMatrix();
	}

	enableNormalViz() {
		this.diamond.enableNormalViz();
		this.triangle.enableNormalViz();
		this.parallelogram.enableNormalViz();
		this.triangleBig.enableNormalViz();
		this.triangleSmall.enableNormalViz();
    }
}
