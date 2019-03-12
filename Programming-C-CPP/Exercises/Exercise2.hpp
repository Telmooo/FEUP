/**
 * @file Exercise2.hpp
 *
 * @brief Declarations for exercise 2
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#pragma once

 /**
  * Runs exercise 2: Flow Control | Loops
  * Allows user to choose which exercise to run from the second exercise
  *
  * @brief execute exercise 2
  */
void runExercise2(void);

/**
 * User inputs 6 numbers (a, b, c, d, e, f) and the solution, if any, is calculated for
 * the equations a*x + b*y = c and d*x + e*y = f
 *
 * @brief solves the equations a*x + b*y = c and d*x + e*y = f in respect to x, y
 */
void eqSolver2(void);

/**
 * User inputs 3 numbers and outputs the numbers in decrescent order and
 * if it's possible to build a triangle with sides of length equal to input numbers
 *
 * @brief determinate if it's possible to build a triangle
 */
void builder(void);

/**
 * User inputs operation (+, -, *, /) and outputs the result
 *
 * @brief simple calculator via input
 */
void calculator(void);

/**
 * User inputs merchandise mass and outputs the cost of the merchandise
 *
 * @brief calculates the cost of merchandise
 */
void costCalculator(void);

/**
 * Find all the roots, real or imaginary, of the quadratic equation ax^2 + bx + c = 0
 *
 * @brief find the root of quadratic equation
 */
void roots(void);

/**
 * Checks if number is prime | Outputs all primes below limit | Outputs first N primes
 *
 * @brief prime checker, prime lister
 */
void primes(void);

/**
 * Checks if a number is prime
 *
 * @brief checks if number is prime
 * @param n whole number
 * @return 1 if number is prime, else 0
 */
int isPrime2(int n);

/**
 * Outputs all values for sine, cosine and tangent of the angles between the limits
 * user specifies with an incrementer also specified by user
 *
 * @brief outputs trigonometric table
 */
void trigTable(void);

/**
 * Converts an angle in degrees to radians
 *
 * @brief conversion from degrees to radians
 * @param angle angle in degrees
 * @return angle in radians
 */
inline double toRad(double angle);

/**
 * User inputs an initial amount, the interest rate and the period of time, and
 * outputs the value that will be accumulated over that period of time
 *
 * @brief calculates the value accumulated over a period of time
 */
void compoundInterest(void);

/**
 * @brief reads a int array from user
 */
void arrayInputReader(void);

/**
 * User inputs number and outputs whether the number is a palindrome or not
 * (same number if reversed)
 *
 * @brief checks if a number is a palindrome
 */
void palindromeChecker(void);

/**
 * Approximates the value of the sum of special sum series:
 * 	- Sum series that approximates the value of euler number
 * 	- Sum series that approximates the value of PI
 * 	- Sum series that approximates the value of exponential
 *
 * @brief approximates the value of special sum series
 */
void sumSeries(void);

/**
 * Approximates the value of the sum of special sum series:
 * 	- Sum series that approximates the value of euler number
 * 	- Sum series that approximates the value of PI
 * 	- Sum series that approximates the value of exponential
 * Approximation stops when difference between the terms is lower than the precision
 *
 * @brief approximates the value of special sum series
 */
void sumSeriesPrecision(void);

/**
 * Factorise a number in its prime factors
 *
 * @brief prime factorisation of a number
 */
void factorize(void);

/**
 * Approximates the square root of a number using Newton's method of approximation
 *
 * @brief approximates the square root of a number
 */
void sqrtApprox(void);

/**
 * Test multiplication table with user and evaluates the user performance
 *
 * @brief simple multiplication tester
 */
void multTest(void);
