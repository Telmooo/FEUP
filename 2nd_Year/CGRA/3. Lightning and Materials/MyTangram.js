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
        // Red Color
        var red_color = hexToRgbA("#ff1414");
        this.red = new CGFappearance(this.scene);
		this.red.setAmbient(red_color[0], red_color[1], red_color[2], 1.0);
		this.red.setDiffuse(red_color[0], red_color[1], red_color[2], 1.0);
		this.red.setSpecular(1.0, 1.0, 1.0, 1.0);
		this.red.setShininess(10.0);

		// Pink Color
        var pink_color = hexToRgbA("#ff9cd2");
        this.pink = new CGFappearance(this.scene);
		this.pink.setAmbient(pink_color[0], pink_color[1], pink_color[2], 1.0);
		this.pink.setDiffuse(pink_color[0], pink_color[1], pink_color[2], 1.0);
		this.pink.setSpecular(1.0, 1.0, 1.0, 1.0);
		this.pink.setShininess(10.0);

		// Orange Color
        var orange_color = hexToRgbA("#ff9c00");
        this.orange = new CGFappearance(this.scene);
		this.orange.setAmbient(orange_color[0], orange_color[1], orange_color[2], 1.0);
		this.orange.setDiffuse(orange_color[0], orange_color[1], orange_color[2], 1.0);
		this.orange.setSpecular(1.0, 1.0, 1.0, 1.0);
		this.orange.setShininess(10.0);

		// Blue Color
        var blue_color = hexToRgbA("#009cff");
        this.blue = new CGFappearance(this.scene);
		this.blue.setAmbient(blue_color[0], blue_color[1], blue_color[2], 1.0);
		this.blue.setDiffuse(blue_color[0], blue_color[1], blue_color[2], 1.0);
		this.blue.setSpecular(1.0, 1.0, 1.0, 1.0);
		this.blue.setShininess(10.0);

		// Yellow Color
        var yellow_color = hexToRgbA("#ffff00");
        this.yellow = new CGFappearance(this.scene);
		this.yellow.setAmbient(yellow_color[0], yellow_color[1], yellow_color[2], 1.0);
		this.yellow.setDiffuse(yellow_color[0], yellow_color[1], yellow_color[2], 1.0);
		this.yellow.setSpecular(1.0, 1.0, 1.0, 1.0);
		this.yellow.setShininess(10.0);

		// Green Color
        var green_color = hexToRgbA("#00ff00");
        this.green = new CGFappearance(this.scene);
		this.green.setAmbient(green_color[0], green_color[1], green_color[2], 1.0);
		this.green.setDiffuse(green_color[0], green_color[1], green_color[2], 1.0);
		this.green.setSpecular(1.0, 1.0, 1.0, 1.0);
		this.green.setShininess(10.0);

		// Purple Color
        var purple_color = hexToRgbA("#aa4fc2");
        this.purple = new CGFappearance(this.scene);
		this.purple.setAmbient(purple_color[0], purple_color[1], purple_color[2], 1.0);
		this.purple.setDiffuse(purple_color[0], purple_color[1], purple_color[2], 1.0);
		this.purple.setSpecular(1.0, 1.0, 1.0, 1.0);
		this.purple.setShininess(10.0);
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
		this.red.apply();
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
		this.pink.apply();
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
		this.orange.apply();
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
		this.blue.apply();
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
		this.yellow.apply();
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
		this.green.apply();
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
		this.purple.apply();
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

	disableNormalViz() {
		this.diamond.disableNormalViz();
		this.triangle.disableNormalViz();
		this.parallelogram.disableNormalViz();
		this.triangleBig.disableNormalViz();
		this.triangleSmall.disableNormalViz();
	}
}
