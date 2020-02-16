/**
 * @file Exercise3.hpp
 *
 * @brief Declarations for exercise 3
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#pragma once

 /**
  * Runs exercise 3: Functions
  * Allows user to choose which exercise to run from the third exercise
  *
  * @brief execute exercise 3
  */
void runExercise3(void);

/**
 * User inputs three points (2D points) and calculates the area of the triangle
 * defined by those vertexes
 *
 * @brief calculates the area of a triangle
 */
void runArea(void);

/**
 * Calculates the area of the triangle using Heron's formula
 *
 * @brief calculates area of a triangle
 * @param x1 X-coordinate of the first vertex
 * @param y1 Y-coordinate of the first vertex
 * @param x2 X-coordinate of the second vertex
 * @param y2 Y-coordinate of the second vertex
 * @param x3 X-coordinate of the third vertex
 * @param y3 Y-coordinate of the third vertex
 * @return the value of the area of the triangle
 */
double area(double x1, double y1, double x2, double y2, double x3, double y3);

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
double distance2(double x1, double y1, double x2, double y2);

/**
 * Checks if number is prime | Outputs all primes below limit | Outputs first N primes
 *
 * @brief prime checker, prime lister
 */
void runPrimes(void);

/**
 * Checks if a number is prime
 *
 * @brief checks if number is prime
 * @param n whole number
 * @return 1 if number is prime, else 0
 */
int isPrime(int n);

/**
 * Approximates the square root of a number using Newton's method of approximation
 * User can input the precision or the max iterations used to estimate the square root
 *
 * @brief approximates the square root of a number
 */
void runSqrt(void);

/**
 * Approximates the square root of a number using Newton's method of approximation
 *
 * @brief approximates the square root of a number
 * @param x number whose square root is being calculated
 * @param precision max difference between two approximations
 * @param maxIter max iterations allowed to execute in order to estimate the square root
 * @return the value of the estimation for the square root of number x
 */
double getSqrt(double x, double precision, unsigned int maxIter);

/**
 * User inputs a number and specifies the number of decimals places to be rounded to
 *
 * @brief user inputs a number to be rounded to n decimals places chosen by the user
 */
void runRounder(void);

/**
 * @brief rounds a number to n decimal places
 * @param x number to be rounded
 * @param decimalPlaces number of decimal places (precision)
 * @return the number rounded to the number of decimal places specified
 */
inline double round(double x, unsigned int decimalPlaces);

/**
 * Allows user to input fractions and execute simple operations with fractions
 *
 * @brief executes fraction reader and operator
 */
void runFraccs(void);

/**
 * Reads fraction from user, if any error occurs during the process, fraction is evaluated as an indertermination
 * (0 / 0)
 *
 * @brief reads fractions from input of the user
 * @param numerator reference to value of numerator
 * @param denominator reference to value of denominator
 * @return 1 if valid fraction was entered, else 0
 */
bool readFracc(int &numerator, int &denominator);

/**
 * Writes a fraction to the screen
 * If fraction is evaluated as infinity it writes as "Infinity", if has undefined value it writes as "Undefined"
 *
 * @brief writes fraction to console
 * @param numerator the value of numerator of the fraction
 * @param denominator the value of denominator of the fraction
 */
void writeFracc(int numerator, int denominator);

/**
 * Reduces fraction to the lowest terms
 *
 * @brief reduces fraction
 * @param numerator [in] [out] reference to the numerator of the fraction
 * @param denominator [in] [out] reference to the denominator of the fraction
 */
void reduceFracc(int &numerator, int &denominator);

/**
 * Executes simple operations between two fractions
 * Operations allowed are sums, differences, multiplication and division of fractions
 *
 * @brief executes operation between fractions
 * @param numerator1 the value of the numerator of the first fraction
 * @param denominator1 the value of the denominator of the first fraction
 * @param op specifier to which operation to execute (0-> sum; 1-> subtraction; 2-> multiplication; 3-> division)
 * @param numerator2 the value of the numerator of the second fraction
 * @param denominator2 the value of the denominator of the second fraction
 * @return a pointer to the location of an array with 2 elements [numerator, denominator] of the result
 */
int* arithmeticFracc(int numerator1, int denominator1, int op, int numerator2, int denominator2);

/**
 * Calculates the greatest common divisor using euclidean algorithm (iterative)
 *
 * @brief calculates greatest common divisor
 * @param a first number
 * @param b second number
 * @return value of the greatest common divisor
 */
int gcd(int a, int b);

/**
 * User inputs year and/or month and its shown the calendar of the specified year and/or month
 * Week starts at Monday and ends in Sunday in formatted calendar
 *
 * @brief user inputs year and/or month to show the calendar of the specified year and/or month
 */
void runCalendar(void);

/**
 * Writes the calendar of the specified month of the specified year as a table
 *
 * @brief outputs calendar of specified month of the specified year
 * @param month a whole number between 1-12
 * @param year value of year (can be negative or positive (must be whole number))
 */
void writeMonthCalendar(unsigned int month, int year);

/**
 * Writes the calendar of all the months of the specified year as a table
 *
 * @brief outputs calendar of the specified year
 * @param year value of year (can be negative or positive (must be whole number))
 */
void writeYearCalendar(int year);

/**
 * Evaluates if the year specified is a leap year
 *
 * @brief evaluates year as leap year or common year
 * @param year value of year (can be negative or positive (must be whole number))
 * @return if year is a leap year (1-> is leap; 0-> is common)
 */
bool leapYear(int year);

/**
 * Get the number of days of specified month of the specified year, number of days varies depending
 * if the year is leap or common (this variance only applies to one month)
 *
 * @brief number of days in a month
 * @param month a number between 1-12 representing the month
 * @param year value of year (can be negative or positive (must be whole number))
 * @return number of days
 */
unsigned int days(unsigned int month, int year);

/**
 * Determines the day of the week of a specified date (day, month, year) using Babwani's Formula
 *
 * @brief calculates day of the week
 * @param day a number between 1-(28/29/30/31)
 * @param month a number between 1-12 representing the month
 * @param year value of year (can be negative or positive (must be whole number))
 * @return week day represented as positive number
 */
unsigned int weekDay(unsigned int day, unsigned int month, int year);

/**
 * Gets code of the specified month used for calculated the week day for the Babwani's formula
 *
 * @brief gets the code of the month
 * @param month a number between 1-12 representing the month
 * @param year value of year (can be negative or positive (must be whole number))
 * @return code of the month
 */
unsigned int getMonthCode(unsigned int month, int year);

/**
 * Calculates the factorial iteratively/recursively of a number user inpunts
 *
 * @brief user can calculate factorial of a number iteratively/recursively
 */
void runFactorial(void);

/**
 * Calculates the factorial of n iteratively
 * If any overflow or invalid factorial occurs the value of the factorial returned is 0
 *
 * @brief calculates factorial
 * @param n any whole number (must be greater or equal to 0)
 * @return value of factorial of n
 */
unsigned long long factorial_iter(unsigned int n);

/**
 * Calculates the factorial of n recursively
 * If any overflow or invalid factorial occurs the value of the factorial returned is 0
 *
 * @brief calculates factorial
 * @param n any whole number (must be greater or equal to 0)
 * @return value of factorial of n
 */
unsigned long long factorial_rec(int n);

/**
 * User inputs two numbers and outputs the greatest common divisor of the numbers
 *
 * @brief executes the greatest common divisor of two numbers
 */
void runGCD(void);

/**
 * Calculates the greatest common divisor recursively
 *
 * @brief calculates greatest common divisor
 * @param a first number
 * @param b second number
 * @return the value of the greatest common divisor
 */
int gcd_rec(int a, int b);

/**
 * Calculates the definite integral of a function chosen by user using Trapezoidal Rule
 *
 * @brief executes integration of functions
 */
void runIntegration(void);

/**
 * Integrates function f using Trapezoidal Rule (Approximation)
 * Integral between a and b, with n intervals
 *
 * @brief integrates function f between a and b
 * @param f function to integrate
 * @param a lower limit of integral
 * @param b upper limit of integral
 * @param n number of intervals the space between a and b is divided to
 * @return the value of the definite integral
 */
double integrateTR(double(*f)(double), double a, double b, unsigned int n);

/**
 * Function g: Square of a number
 *
 * @brief function g: power of 2 of number x
 * @param x any real number
 * @return x squared
 */
inline double g(double x);

/**
 * Function h: Square root of 4 - x squared
 *
 * @brief function g: Square root of 4 - x squared
 * @param x any real number
 * @return value of the function
 */
inline double h(double x);
