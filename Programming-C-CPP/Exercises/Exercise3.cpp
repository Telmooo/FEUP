/**
 * @file Exercise3.cpp
 *
 * @brief Source code for exercise 3
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#include "Exercise3.hpp"
#include <iostream>
#include <limits>
#include <ios>
#include <iomanip>
#include <cmath>
#include <string>

 /**
  * Runs exercise 3: Functions
  * Allows user to choose which exercise to run from the third exercise
  *
  * @brief execute exercise 3
  */
void runExercise3(void) {
	int choice = 0;
	while (true) {
		std::cout << "\nEnter a number between 1-9 to run exercises\nEnter 0 to exit\n";
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
			runArea();
			break;
		case 2:
			runPrimes();
			break;
		case 3:
			runSqrt();
			break;
		case 4:
			runRounder();
			break;
		case 5:
			runFraccs();
			break;
		case 6:
			runCalendar();
			break;
		case 7:
			runFactorial();
			break;
		case 8:
			runGCD();
			break;
		case 9:
			runIntegration();
			break;
		default:
			std::cout << "Invalid number\n";
			break;
		}
	}
}

/**
 * User inputs three points (2D points) and calculates the area of the triangle
 * defined by those vertexes
 *
 * @brief calculates the area of a triangle
 */
void runArea(void) {
	/* 3.1 */
	double triangleArea;
	double vertex1[2], vertex2[2], vertex3[2];
	std::cout << "\nExercise 3.1\n";
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

	std::streamsize defaultPrecision = std::cout.precision();
	triangleArea = area(vertex1[0], vertex1[1], vertex2[0], vertex2[1], vertex3[0], vertex3[1]);
	std::cout << std::fixed << std::setprecision(3) << "The area of the triangle is "
		<< triangleArea << "\n";
	std::setprecision(defaultPrecision);
}

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
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double side1, side2, side3, semiPerimeter, area;
	side1 = distance2(x1, y1, x2, y2);
	side2 = distance2(x1, y1, x3, y3);
	side3 = distance2(x2, y2, x3, y3);
	semiPerimeter = (side1 + side2 + side3) / 2.0;
	area = sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2)
		* (semiPerimeter - side3));
	return area;
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
double distance2(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

/**
 * Checks if number is prime | Outputs all primes below limit | Outputs first N primes
 *
 * @brief prime checker, prime lister
 */
void runPrimes(void) {
	/* 3.2 */
	int choice = 0, n = 0;
	std::cout << "\nExercise 3.2\n";
	std::cout << "Modes:\nEnter 0 to check if number is prime\nEnter 1 to find the n first primes\nEnter 2 to find all primes inferior to n\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid mode\n";
		return;
	}

	int prime;
	switch (choice) {
	case 0:
		std::cout << "Enter a number: ";
		std::cin >> n;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		std::cout << n << ((isPrime(n)) ? " is " : " is not ") << "prime\n";
		return;
	case 1:
		std::cout << "Enter the number of primes to display (greater than zero): ";
		std::cin >> n;
		if (std::cin.fail() || n <= 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		prime = 2;
		std::cout << "The first " << n << " primes are:\n";
		while (n--) {
			if (prime == 2) {
				std::cout << prime;
				prime++;
				continue;
			}
			while (!isPrime(prime))
				prime += 2;

			std::cout << " " << prime;
			prime += 2;
		}
		std::cout << "\nCompleted\n";
		return;
	case 2:
		std::cout << "Enter the limit (greater than zero): ";
		std::cin >> n;
		if (std::cin.fail() || n <= 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid Input\n";
			return;
		}

		prime = 2;
		std::cout << "The primes inferior to " << n << " are:\n";
		while (prime < n) {
			if (prime == 2) {
				std::cout << prime << " ";
				prime++;
				continue;
			}
			if (isPrime(prime))
				std::cout << " " << prime;

			prime += 2;
		}
		std::cout << "\nCompleted\n";
		return;
	}
}

/**
 * Checks if a number is prime
 *
 * @brief checks if number is prime
 * @param n whole number
 * @return 1 if number is prime, else 0
 */
int isPrime(int n) {
	if (n == 2)
		return 1;

	if (n < 2 || n % 2 == 0)
		return 0;

	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

/**
 * Approximates the square root of a number using Newton's method of approximation
 * User can input the precision or the max iterations used to estimate the square root
 *
 * @brief approximates the square root of a number
 */
void runSqrt(void) {
	/* 3.3 */
	double num = 0, delta = 0;
	unsigned int maxIter = 0;
	std::cout << "\nExercise 3.3\n";
	std::cout << "Approximate square root of a number\nEnter a number: ";
	std::cin >> num;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the delta (limit error between approximation and number): ";
	std::cin >> delta;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the maximum iterations: ";
	std::cin >> maxIter;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}
	double estimatedSqrt = getSqrt((num < 0) ? -num : num, fabs(delta), maxIter);
	std::cout << "The square root estimated for " << num << " is: " << estimatedSqrt
		<< ((num < 0) ? "i" : "") << "\n";
	std::cout << "The square root in C/C++ library for " << num << " is "
		<< sqrt((num < 0) ? -num : num) << ((num < 0) ? "i" : "") << "\n";
}

/**
 * Approximates the square root of a number using Newton's method of approximation
 *
 * @brief approximates the square root of a number
 * @param x number whose square root is being calculated
 * @param precision max difference between two approximations
 * @param maxIter max iterations allowed to execute in order to estimate the square root
 * @return the value of the estimation for the square root of number x
 */
double getSqrt(double x, double precision, unsigned int maxIter) {
	double approx = 1, newApprox, diff;
	for (unsigned int i = 0; i < maxIter && (i == 0 || fabs(diff) > precision); i++) {
		newApprox = (approx + x / approx) / 2.0;
		diff = x - newApprox * newApprox;
		approx = newApprox;
	}
	return approx;
}

/**
 * User inputs a number and specifies the number of decimals places to be rounded to
 *
 * @brief user inputs a number to be rounded to n decimals places chosen by the user
 */
void runRounder(void) {
	/* 3.4 */
	double num = 0;
	unsigned int decimalPlaces = 0;

	std::cout << "\nExercise 3.4\n";
	std::cout << "Round a number to n decimal places\n";
	std::cout << "Enter a number: ";
	std::cin >> num;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the decimal places to round to: ";
	std::cin >> decimalPlaces;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	double rounded = round(num, decimalPlaces);

	std::streamsize defaultPrecision = std::cout.precision();
	std::cout << std::fixed << std::setprecision(decimalPlaces) << "The number rounded is: "
		<< rounded << "\n";
	std::setprecision(defaultPrecision);
}

/**
 * @brief rounds a number to n decimal places
 * @param x number to be rounded
 * @param decimalPlaces number of decimal places (precision)
 * @return the number rounded to the number of decimal places specified
 */
inline double round(double x, unsigned int decimalPlaces) {
	return floor(x * pow(10, decimalPlaces) + 0.5) / pow(10, decimalPlaces);
}

/**
 * Allows user to input fractions and execute simple operations with fractions
 *
 * @brief executes fraction reader and operator
 */
void runFraccs(void) {
	/* 3.5 */
	int choice = 0;
	std::cout << "\nExercise 3.5\n";
	while (true) {
		std::cout << "Modes:\nEnter 0 to exit\nEnter 1 for reading fractions\nEnter 2 for operations with fractions\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			choice = -1;
		}

		switch (choice) {
		case 0:
			return;
		case 1:
			int numerator, denominator;
			std::cout << "Reading fraction, numerator and denominator must be both integers\n";
			std::cout << "Enter a fraction (numerator / denominator ): ";
			if (readFracc(numerator, denominator)) {
				std::cout << "Fraction entered: ";
				writeFracc(numerator, denominator);
				reduceFracc(numerator, denominator);
				std::cout << "The reduced fraction is: ";
				writeFracc(numerator, denominator);
			} else {
				std::cout << "Invalid fraction\n";
			}
			break;
		case 2:
			int numerator1, denominator1, numerator2, denominator2;
			char op;
			std::cout << "Arithmetic operations with fraction, numerator and denominator must be both integers\n";
			std::cout << "Valid operators: +, -, *, /\n";
			std::cout << "Enter an operation (numerator1 / denominator1 <operator> numerator2 / denominator2): ";
			readFracc(numerator1, denominator1);
			std::cin >> op;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
				op = 'I'; // invalid operator
			}
			readFracc(numerator2, denominator2);
			int* result;
			switch (op) {
			case '+':
				result = arithmeticFracc(numerator1, denominator1, 0, numerator2, denominator2);
				break;
			case '-':
				result = arithmeticFracc(numerator1, denominator1, 1, numerator2, denominator2);
				break;
			case '*':
				result = arithmeticFracc(numerator1, denominator1, 2, numerator2, denominator2);
				break;
			case '/':
				result = arithmeticFracc(numerator1, denominator1, 3, numerator2, denominator2);
				break;
			default:
				std::cout << "Invalid operator\n";
				continue;
			}
			std::cout << "The result is: ";
			writeFracc(*result, *(result + 1));
			free(result);
			break;
		default:
			std::cout << "Invalid mode\n";
			break;
		}
	}
}

/**
 * Reads fraction from user, if any error occurs during the process, fraction is evaluated as an indertermination
 * (0 / 0)
 *
 * @brief reads fractions from input of the user
 * @param numerator reference to value of numerator
 * @param denominator reference to value of denominator
 * @return 1 if valid fraction was entered, else 0
 */
bool readFracc(int &numerator, int &denominator) {
	char sep;
	std::cin >> numerator >> sep >> denominator;
	if (std::cin.fail() || sep != '/') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		numerator = 0;
		denominator = 0;
		return false;
	}
	return true;
}

/**
 * Writes a fraction to the screen
 * If fraction is evaluated as infinity it writes as "Infinity", if has undefined value it writes as "Undefined"
 *
 * @brief writes fraction to console
 * @param numerator the value of numerator of the fraction
 * @param denominator the value of denominator of the fraction
 */
void writeFracc(int numerator, int denominator) {
	if (numerator == 0 && denominator == 0) {
		std::cout << "undefined\n";
	} else if (denominator == 0) {
		std::cout << ((numerator > 0) ? "" : "-") << "infinity\n";
	} else {
		std::cout << numerator << "/" << denominator << "\n";
	}
}

/**
 * Reduces fraction to the lowest terms
 *
 * @brief reduces fraction
 * @param numerator reference to the numerator of the fraction
 * @param denominator reference to the denominator of the fraction
 */
void reduceFracc(int &numerator, int &denominator) {
	int div = gcd(numerator, denominator);
	if (div == 0)
		return;
	numerator /= div;
	denominator /= div;

	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}

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
int* arithmeticFracc(int numerator1, int denominator1, int op, int numerator2, int denominator2) {
	int *fracc = (int*)malloc(2 * sizeof(int));

	switch (op) {
	case 0: // sum
		if (denominator1 == denominator2) {
			if (denominator1 == 0) {
				*fracc = 0;
				*(fracc + 1) = 0;
			} else {
				*fracc = numerator1 + numerator2;
				*(fracc + 1) = denominator1;
				reduceFracc(*fracc, *(fracc + 1));
			}
		} else {
			if (denominator1 == 0) {
				*fracc = numerator1;
				*(fracc + 1) = denominator1;
			} else if (denominator2 == 0) {
				*fracc = numerator2;
				*(fracc + 1) = denominator2;
			} else {
				*fracc = numerator1 * denominator2 + numerator2 * denominator1;
				*(fracc + 1) = denominator1 * denominator2;
				reduceFracc(*fracc, *(fracc + 1));
			}
		}
		break;
	case 1: // subtraction
		if (denominator1 == denominator2) {
			if (denominator1 == 0) { // generate undefined result
				*fracc = 0;
				*(fracc + 1) = 0;
			} else {
				*fracc = numerator1 - numerator2;
				*(fracc + 1) = denominator1;
				reduceFracc(*fracc, *(fracc + 1));
			}
		} else {
			if (denominator1 == 0) {
				*fracc = numerator1;
				*(fracc + 1) = denominator1;
			} else if (denominator2 == 0) {
				*fracc = -numerator2;
				*(fracc + 1) = denominator2;
			} else {
				*fracc = numerator1 * denominator2 - numerator2 * denominator1;
				*(fracc + 1) = denominator1 * denominator2;
				reduceFracc(*fracc, *(fracc + 1));
			}
		}
		break;
	case 2: // multiplication
		*fracc = numerator1 * numerator2;
		*(fracc + 1) = denominator1 * denominator2;
		reduceFracc(*fracc, *(fracc + 1));
		break;
	case 3: // division
		*fracc = numerator1 * denominator2;
		*(fracc + 1) = denominator1 * numerator2;
		reduceFracc(*fracc, *(fracc + 1));
		break;
	}
	return fracc;
}

/**
 * Calculates the greatest common divisor using euclidean algorithm (iterative)
 *
 * @brief calculates greatest common divisor
 * @param a first number
 * @param b second number
 * @return value of the greatest common divisor
 */
int gcd(int a, int b) {
	int remainder;
	a = abs(a);
	b = abs(b);
	while (b) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

/**
 * User inputs year and/or month and its shown the calendar of the specified year and/or month
 * Week starts at Monday and ends in Sunday in formatted calendar
 *
 * @brief user inputs year and/or month to show the calendar of the specified year and/or month
 */
void runCalendar(void) {
	/* 3.6 */
	int mode = 0;
	std::cout << "\nExercise 3.6\n";
	std::cout << "Modes:\nEnter 1 to see month calendar\nEnter 2 to see year calendar\n";
	std::cout << "Enter your choice: ";
	std::cin >> mode;
	if (std::cin.fail() || (mode != 1 && mode != 2)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid mode\n";
		return;
	}
	int year;
	switch (mode) {
	case 1:
		int month;
		std::cout << "Enter a month and an year (month year): ";
		std::cin >> month >> year;
		if (std::cin.fail() || month < 0 || month > 12) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		writeMonthCalendar(month, year);
		break;
	case 2:
		std::cout << "Enter an year: ";
		std::cin >> year;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		writeYearCalendar(year);
		break;
	}
}

/**
 * Writes the calendar of the specified month of the specified year as a table
 *
 * @brief outputs calendar of specified month of the specified year
 * @param month a whole number between 1-12
 * @param year value of year (can be negative or positive (must be whole number))
 */
void writeMonthCalendar(unsigned int month, int year) {
	const char* MONTHS[12] = { "January", "February", "March", "April", "May", "June", "July",
			"August", "September", "October", "November", "December" };
	std::cout << MONTHS[month - 1] << "/" << year << "\n";
	std::cout << "Mon\tTue\tWed\tThu\tFri\tSat\tSun\n";
	unsigned int monthDays = days(month, year);
	unsigned int currentWeekDay;
	for (unsigned int day = 1; day <= monthDays; day++) {
		currentWeekDay = weekDay(day, month, year);
		if (day == 1)
			std::cout << std::string(currentWeekDay, '\t') << day
			<< ((currentWeekDay == 6) ? "\n" : "\t");
		else
			std::cout << day << ((currentWeekDay == 6) ? "\n" : "\t");
	}
	std::cout << "\n";
}

/**
 * Writes the calendar of all the months of the specified year as a table
 *
 * @brief outputs calendar of the specified year
 * @param year value of year (can be negative or positive (must be whole number))
 */
void writeYearCalendar(int year) {
	std::cout << year << " Calendar\n";
	for (unsigned int month = 1; month <= 12; month++) {
		writeMonthCalendar(month, year);
	}
}

/**
 * Evaluates if the year specified is a leap year
 *
 * @brief evaluates year as leap year or common year
 * @param year value of year (can be negative or positive (must be whole number))
 * @return if year is a leap year (1-> is leap; 0-> is common)
 */
bool leapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/**
 * Get the number of days of specified month of the specified year, number of days varies depending
 * if the year is leap or common (this variance only applies to one month)
 *
 * @brief number of days in a month
 * @param month a number between 1-12 representing the month
 * @param year value of year (can be negative or positive (must be whole number))
 * @return number of days
 */
unsigned int days(unsigned int month, int year) {
	if ((month < 8 && month % 2 == 1) || (month >= 8 && month % 2 == 0))
		return 31;
	else if (month == 2)
		return leapYear(year) ? 29 : 28;

	return 30;
}

/**
 * Determines the day of the week of a specified date (day, month, year) using Babwani's Formula
 *
 * @brief calculates day of the week
 * @param day a number between 1-(28/29/30/31)
 * @param month a number between 1-12 representing the month
 * @param year value of year (can be negative or positive (must be whole number))
 * @return week day represented as positive number
 */
unsigned int weekDay(unsigned int day, unsigned int month, int year) {
	return ((5 * (year % 100) / 4) + getMonthCode(month, year) + day - 2 * ((year / 100) % 4) + 5)
		% 7;
}

/**
 * Gets code of the specified month used for calculated the week day for the Babwani's formula
 *
 * @brief gets the code of the month
 * @param month a number between 1-12 representing the month
 * @param year value of year (can be negative or positive (must be whole number))
 * @return code of the month
 */
unsigned int getMonthCode(unsigned int month, int year) {
	switch (month) {
	case 1:
		return leapYear(year) ? 6 : 0;
	case 2:
		return leapYear(year) ? 2 : 3;
	case 3:
	case 11:
		return 3;
	case 4:
	case 7:
		return 6;
	case 5:
		return 1;
	case 6:
		return 4;
	case 8:
		return 2;
	case 9:
	case 12:
		return 5;
	case 10:
		return 0;
	default:
		return 0; // gotta make the compiler happy
	}
}

/**
 * Calculates the factorial iteratively/recursively of a number user inpunts
 *
 * @brief user can calculate factorial of a number iteratively/recursively
 */
void runFactorial(void) {
	/* 3.7 */
	std::cout << "\nExercise 3.7\n";
	unsigned int n;
	int mode;
	std::cout << "Factorial of an integer (must be greater or equal to 0)\n";
	std::cout << "Enter 0 to run iterative factorial\nEnter 1 to run recursive factorial\n";
	std::cout << "Enter your choice: ";
	std::cin >> mode;
	if (std::cin.fail() || (mode != 0 && mode != 1)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter a number: ";
	std::cin >> n;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}
	unsigned long long fact;
	switch (mode) {
	case 0:
		fact = factorial_iter(n);
		break;
	case 1:
		fact = factorial_rec(n);
		break;
	}

	std::cout << "Factorial: " << n << "! = " << (fact ? std::to_string(fact) : "OVERFLOW") << "\n";
}

/**
 * Calculates the factorial of n iteratively
 * If any overflow or invalid factorial occurs the value of the factorial returned is 0
 * Max factorial supported is factorial of 20
 *
 * @brief calculates factorial
 * @param n any whole number (must be greater or equal to 0)
 * @return value of factorial of n
 */
unsigned long long factorial_iter(unsigned int n) {
	if (n <= 1)
		return 1;
	unsigned long long factorial = 1;
	for (unsigned int i = 2; i <= n; i++) {
		std::cout << ULLONG_MAX / factorial << " " << n << "\n";
		if (ULLONG_MAX / factorial >= n)
			factorial *= i;
		else {
			return 0;
		}
	}
	return factorial;
}

/**
 * Calculates the factorial of n recursively
 * If any overflow or invalid factorial occurs the value of the factorial returned is 0
 * Max factorial supported is factorial of 20
 *
 * @brief calculates factorial
 * @param n any whole number (must be greater or equal to 0)
 * @return value of factorial of n
 */
unsigned long long factorial_rec(int n) {
	if (n <= 1)
		return 1;

	unsigned long long factorial = factorial_rec(n - 1);
	if (ULLONG_MAX / factorial < n)
		return 0;

	return n * factorial;
}

/**
 * User inputs two numbers and outputs the greatest common divisor of the numbers
 *
 * @brief executes the greatest common divisor of two numbers
 */
void runGCD(void) {
	/* 3.8 */
	int a, b;
	std::cout << "\nExercise 3.9\n";
	std::cout << "Find the greatest common divisor between two numbers\nEnter two numbers (a b): ";
	std::cin >> a >> b;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Greatest common divisor: " << gcd_rec(a, b) << "\n";
}

/**
 * Calculates the greatest common divisor recursively
 *
 * @brief calculates greatest common divisor
 * @param a first number
 * @param b second number
 * @return the value of the greatest common divisor
 */
int gcd_rec(int a, int b) {
	return (b == 0) ? abs(a) : gcd_rec(b, abs(a) % abs(b));
}

/**
 * Calculates the definite integral of a function chosen by user using Trapezoidal Rule
 *
 * @brief executes integration of functions
 */
void runIntegration(void) {
	/* 2.9 */
	int mode;
	std::cout << "\nExercise 2.9\n";
	std::cout << "Integrate:\nEnter 0 for f(x) = x^2\nEnter 1 for f(x) = sqrt(4 - x^2)\n";
	std::cout << "Enter your choice: ";
	std::cin >> mode;
	if (std::cin.fail() || (mode != 0 && mode != 1)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	double lowerLimit, upperLimit;
	unsigned int intervals;
	std::cout << "Enter the interval of integration and number of intervals\n";
	std::cout << "(<from> <to> <intervals>): ";
	std::cin >> lowerLimit >> upperLimit >> intervals;
	if (std::cin.fail() || intervals <= 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	switch (mode) {
	case 0:
		std::cout << "The definite integral of x^2 between " << lowerLimit << " and " << upperLimit
			<< " is approximately:\n";
		std::cout << integrateTR(g, lowerLimit, upperLimit, intervals) << "\n";
		return;
	case 1:
		std::cout << "The definite integral of sqrt(4 - x^2) between " << lowerLimit << " and "
			<< upperLimit << " is approximately:\n";
		std::cout << integrateTR(h, lowerLimit, upperLimit, intervals) << "\n";
		return;
	}
}

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
double integrateTR(double(*f)(double), double a, double b, unsigned int n) {
	double delta = (b - a) / n;
	double sum = 0;
	if (a < b)
		for (double x = a; x <= b - delta; x += delta)
			sum += (f(x) + f(x + delta)) * delta / 2.0;
	else
		for (double x = a; x >= b - delta; x += delta)
			sum += (f(x) + f(x + delta)) * delta / 2.0;
	return sum;
}

/**
 * Function g: Square of a number
 *
 * @brief function g: power of 2 of number x
 * @param x any real number
 * @return x squared
 */
inline double g(double x) {
	return x * x;
}

/**
 * Function h: Square root of 4 - x squared
 *
 * @brief function g: Square root of 4 - x squared
 * @param x any real number
 * @return value of the function
 */
inline double h(double x) {
	return sqrt(4 - x * x);
}
