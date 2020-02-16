/**
 * @file Exercise1.hpp
 *
 * @brief Declarations for exercise 1
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#pragma once

 /**
  * Runs exercise 1: Data Types | Arithmetic Expressions | Input & Output
  * Allows user to choose which exercise to run from the first exercise
  *
  * @brief execute exercise 1
  */
void runExercise1(void);

/**
 * User inputs a character and outputs the character ASCII Code
 *
 * @brief represents a character in its ASCII Code form
 */
void asciiConverter(void);

/**
 * User inputs 3 numbers and it's calculated the average and deviations
 *
 * @brief calculates average of three numbers
 */
void average(void);

/**
 * User inputs the sphere density and radius and outputs its mass
 *
 * @brief calculates the mass of a sphere
 */
void massSphere(void);

/**
 * User inputs 6 numbers (a, b, c, d, e, f) and the solution, if any, is calculated for
 * the equations a*x + b*y = c and d*x + e*y = f
 *
 * @brief solves the equations a*x + b*y = c and d*x + e*y = f in respect to x, y
 */
void eqSolver(void);

/**
 * User inputs two times (HH MM SS format) and shows the sum of those times
 * in (DD HH MM SS format)
 *
 * @brief sums two times
 */
void timeAdder(void);

/**
 * User inputs three points (2D points) and calculates the area of the triangle
 * defined by those vertexes
 *
 * @brief calculates the area of a triangle
 */
void areaTriangle(void);

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
double distance(double x1, double y1, double x2, double y2);
