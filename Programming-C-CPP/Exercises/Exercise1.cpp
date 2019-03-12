/**
 * @file Exercise1.cpp
 *
 * @brief Source code for exercise 1
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#include "Exercise1.hpp"
#include <iostream>
#include <ios>
#include <limits>
#include <iomanip>
#include <cmath>
#include <sstream>

 /**
  * Runs exercise 1: Data Types | Arithmetic Expressions | Input & Output
  * Allows user to choose which exercise to run from the first exercise
  *
  * @brief execute exercise 1
  */
void runExercise1(void) {
	int choice = 0;
	while (true) {
		std::cout << "\nEnter a number between 1-6 to run exercises\nEnter 0 to exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			choice = -1;
		}

		switch (choice) {
		case 0:
			std::cout << "Finished\n";
			return;
		case 1:
			asciiConverter();
			break;
		case 2:
			average();
			break;
		case 3:
			massSphere();
			break;
		case 4:
			eqSolver();
			break;
		case 5:
			timeAdder();
			break;
		case 6:
			areaTriangle();
			break;
		default:
			std::cout << "Invalid entry\n";
			break;
		}
	}
}

/**
 * User inputs a character and outputs the character ASCII Code
 *
 * @brief represents a character in its ASCII Code form
 */
void asciiConverter(void) {
	/* 1.1 */
	char asciiChar;
	std::cout << "\nExercise 1.1\n";
	std::cout << "Character to ASCII Code Converter\nEnter a caracther: ";
	std::cin >> asciiChar;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}
	std::cout << "The ASCII code for the character " << asciiChar << " is " << (int)asciiChar << "\n";
}

/**
 * User inputs 3 numbers and it's calculated the average and deviations
 *
 * @brief calculates average of three numbers
 */
void average(void) {
	/* 1.2 */
	double x1, x2, x3, avg, x1dev, x2dev, x3dev;
	std::cout << "\nExercise 1.2\n";
	std::cout << "Enter three numbers\nNumber 1: ";
	std::cin >> x1;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	std::cout << "Number 2: ";
	std::cin >> x2;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	std::cout << "Number 3: ";
	std::cin >> x3;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	avg = (x1 + x2 + x3) / 3.0;
	x1dev = x1 - avg;
	x2dev = x2 - avg;
	x3dev = x3 - avg;
	std::streamsize defaultPrecision = std::cout.precision();
	std::cout << std::fixed << std::setprecision(3) << "Average: " << avg
		<< "\nNumber 1 deviation: " << x1dev << "\nNumber 2 deviation: " << x2dev
		<< "\nNumber 3 deviation: " << x3dev << "\n";
	std::setprecision(defaultPrecision);
}

/**
 * User inputs the sphere density and radius and outputs its mass
 *
 * @brief calculates the mass of a sphere
 */
void massSphere(void) {
	/* 1.3 */
	double mass, density, radius;
	const double PI = acos(-1.0);
	std::cout << "\nExercise 1.3\n";
	std::cout << "Enter the sphere material density (kg/m^3): ";
	std::cin >> density;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Enter the sphere radius (m): ";
	std::cin >> radius;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	mass = (4 / 3.0) * (PI * density * pow(radius, 3));
	std::streamsize defaultPrecision = std::cout.precision();
	std::setprecision(defaultPrecision);
	std::cout << std::fixed << std::setprecision(2) << "The sphere mass is " << mass << " kg\n";
	std::setprecision(defaultPrecision);
}

/**
 * User inputs 6 numbers (a, b, c, d, e, f) and the solution, if any, is calculated for
 * the equations a*x + b*y = c and d*x + e*y = f
 *
 * @brief solves the equations a*x + b*y = c and d*x + e*y = f in respect to x, y
 */
void eqSolver(void) {
	/* 1.4 */
	double a, b, c, d, e, f, x, y;
	std::cout << "\nExercise 1.4\n";
	std::cout << "Solving equations a*x + b*y = c and d*x + e*y = f\nEnter value for a: ";
	std::cin >> a;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Value for b: ";
	std::cin >> b;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Value for c: ";
	std::cin >> c;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Value for d: ";
	std::cin >> d;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Value for e: ";
	std::cin >> e;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Value for f: ";
	std::cin >> f;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	double denominator = a * e - b * d;
	if (denominator == 0) {
		if (a == 0 && b == 0 && c != 0) {
			std::cout << "Impossible system\n";
		} else if (d == 0 && e == 0 && f != 0) {
			std::cout << "Impossible system\n";
		} else {
			std::cout << "Undetermined system\n";
		}
	} else {
		x = (c * e - b * f) / denominator;
		y = (a * f - c * d) / denominator;
		std::streamsize defaultPrecision = std::cout.precision();
		std::cout << std::fixed << std::setprecision(2) << "The solution (x, y) is (" << x << ", "
			<< y << ")\n";
		std::setprecision(defaultPrecision);
	}
}

/**
 * User inputs two times (HH MM SS format) and shows the sum of those times
 * in (DD HH MM SS format)
 *
 * @brief sums two times
 */
void timeAdder(void) {
	/* 1.5 */
	int time1[3], time2[3];
	int days, hours, mins, secs;
	std::cout << "\nExercise 1.5\n";
	std::cout << "Enter the first time (hours minutes seconds): ";
	std::cin >> time1[0] >> time1[1] >> time1[2];
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Enter the second time (hours minutes seconds): ";
	std::cin >> time2[0] >> time2[1] >> time2[2];
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	// check for valid inputs
	if (time1[0] < 0 || time1[0] > 24 || time1[1] < 0 || time1[1] > 60 || time1[2] < 0
		|| time1[2] > 60 || time2[0] < 0 || time2[0] > 24 || time2[1] < 0 || time2[1] > 60
		|| time2[2] < 0 || time2[2] > 60) {

		std::cout << "Invalid time\nHours must be between 0-24 and minutes and seconds between 0-60\n";
		return;
	}

	secs = *(time1 + 2) + *(time2 + 2);
	mins = *(time1 + 1) + *(time2 + 1) + secs / 60;
	hours = *time1 + *time2 + mins / 60;
	days = hours / 24;
	secs %= 60;
	mins %= 60;
	hours %= 24;
	std::cout << "Added time: " << days << ((days != 1) ? " days, " : " day, ") << hours
		<< ((hours != 1) ? " hours, " : " hour, ") << mins
		<< ((mins != 1) ? " minutes and " : " minute and ") << secs
		<< ((secs != 1) ? " seconds" : " second") << "\n";
}

/**
 * User inputs three points (2D points) and calculates the area of the triangle
 * defined by those vertexes
 *
 * @brief calculates the area of a triangle
 */
void areaTriangle(void) {
	/* 1.6 */
	double semiPerimeter, side1, side2, side3, area;
	double vertex1[2], vertex2[2], vertex3[2];
	std::cout << "\nExercise 1.6\n";
	std::cout << "Enter the first vertex of the triangle (x, y): ";
	std::cin >> vertex1[0] >> vertex1[1];
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Enter the second vertex of the triangle (x, y): ";
	std::cin >> vertex2[0] >> vertex2[1];
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	std::cout << "Enter the third vertex of the triangle (x, y): ";
	std::cin >> vertex3[0] >> vertex3[1];
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}

	side1 = distance(vertex1[0], vertex1[1], vertex2[0], vertex2[1]);
	side2 = distance(vertex1[0], vertex1[1], vertex3[0], vertex3[1]);
	side3 = distance(vertex2[0], vertex2[1], vertex3[0], vertex3[1]);
	semiPerimeter = (side1 + side2 + side3) / 2.0;
	area = sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2)
		* (semiPerimeter - side3));
	std::streamsize defaultPrecision = std::cout.precision();
	std::cout << std::fixed << std::setprecision(3) << "The area of the triangle is " << area << "\n";
	std::setprecision(defaultPrecision);
}

/**
 * Given two points in 2D cartesian coordinates, calculates the distance between them
 *
 * @brief calculates the euclidean distance between two points
 * @param x1 first coordinate of first point
 * @param y1 second coordinate of first point
 * @param x2 first coordinate of second point
 * @param y2 second coordinate of first point
 * @return euclidean distance between two points
 */
double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
