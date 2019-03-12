/**
 * @file Exercise2.cpp
 *
 * @brief Source code for exercise 2
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#include "Exercise2.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <ios>
#include <cmath>
#include <ctime>
#include <sstream>

 /**
  * PI CONSTANT
  */
#define PI acos(-1.0)

  /**
   * Runs exercise 2: Flow Control | Loops
   * Allows user to choose which exercise to run from the second exercise
   *
   * @brief execute exercise 2
   */
void runExercise2(void) {
	int choice = 0;
	while (true) {
		std::cout << "\nEnter a number between 1-15 to run exercises\nEnter 0 to exit\n";
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
			eqSolver2();
			break;
		case 2:
			builder();
			break;
		case 3:
			calculator();
			break;
		case 4:
			costCalculator();
			break;
		case 5:
			roots();
			break;
		case 6:
			primes();
			break;
		case 7:
			trigTable();
			break;
		case 8:
			compoundInterest();
			break;
		case 9:
			arrayInputReader();
			break;
		case 10:
			palindromeChecker();
			break;
		case 11:
			sumSeries();
			break;
		case 12:
			sumSeriesPrecision();
			break;
		case 13:
			factorize();
			break;
		case 14:
			sqrtApprox();
			break;
		case 15:
			multTest();
			break;
		default:
			std::cout << "Invalid number\n";
			break;
		}
	}
}

/**
 * User inputs 6 numbers (a, b, c, d, e, f) and the solution, if any, is calculated for
 * the equations a*x + b*y = c and d*x + e*y = f
 *
 * @brief solves the equations a*x + b*y = c and d*x + e*y = f in respect to x, y
 */
void eqSolver2(void) {
	/* 2.1 */
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
 * User inputs 3 numbers and outputs the numbers in decrescent order and
 * if it's possible to build a triangle with sides of length equal to input numbers
 *
 * @brief determinate if it's possible to build a triangle
 */
void builder(void) {
	/* 2.2 */
	double sides[3];
	int min, mid, max;
	std::cout << "\nExercise 2.2\n";
	std::cout << "Enter the first number: ";
	std::cin >> sides[0];
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the second number: ";
	std::cin >> sides[1];
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the third number: ";
	std::cin >> sides[2];
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	min = (sides[0] < sides[1]) ? ((sides[0] < sides[2]) ? 0 : 2) : ((sides[1] < sides[2]) ? 1 : 2);
	max = (sides[0] > sides[1]) ? ((sides[0] > sides[2]) ? 0 : 2) : ((sides[1] > sides[2]) ? 1 : 2);
	if (min == max)
		mid = min;
	else
		mid = 3 - min - max;

	std::cout << "The minimum is: " << sides[min] << "\nAnd the maximum is: " << sides[max] << "\n";
	std::cout << "The numbers in decrescent order: " << sides[max] << " -> " << sides[mid] << " -> "
		<< sides[min] << "\n";

	if (sides[min] > 0 && sides[mid] > 0 && sides[max] > 0
		&& sides[min] + sides[mid] > sides[max]) {
		std::cout << "It's possible to build a triangle with sides equal to numbers given\n";
	} else {
		std::cout << "It's not possible to build a triangle with the given numbers\n";
	}
}

/**
 * User inputs operation (+, -, *, /) and outputs the result
 *
 * @brief simple calculator via input
 */
void calculator(void) {
	/* 2.3 */
	double operands[2];
	double result;
	int flag;
	char op;
	std::cout << "\nExercise 2.3\n";

	do {
		flag = 0;
		std::cout << "Calculator for arithmetic operations\nOperands available: +, -, *, /\n";
		std::cout << "Enter the expression (operand operator operand): ";
		std::cin >> operands[0] >> op >> operands[1];
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			flag = 1;
		} else {
			switch (op) {
			case '+':
				result = *operands + *(operands + 1);
				break;
			case '-':
				result = *operands - *(operands + 1);
				break;
			case '*':
				result = *operands * *(operands + 1);
				break;
			case '/':
				result = *operands / *(operands + 1);
				break;
			default:
				flag = 1;
				std::cout << "Invalid operator\n";
			}
		}
	} while (flag);

	std::cout << "The result of " << *operands << " " << op << " " << *(operands + 1) << " = "
		<< result << "\n";
}

/**
 * User inputs merchandise mass and outputs the cost of the merchandise
 *
 * @brief calculates the cost of merchandise
 */
void costCalculator(void) {
	/* 2.4 */
	double mass, cost;
	std::cout << "\nExercise 2.4\n";
	std::cout << "Enter the mass of the merchandise (grams): ";
	std::cin >> mass;
	if (std::cin.fail() || mass < 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	if (mass < 500) {
		cost = 5.0;
	} else if (mass <= 1000) {
		cost = 5.0 + ((mass - 500) * 1.5 / 100.0);
	} else {
		cost = 12.5 + ((mass - 1000) * 5.0 / 250.0);
	}

	std::streamsize defaultPrecision = std::cout.precision();
	std::cout << std::fixed << std::setprecision(2) << "The cost for transportation is: " << cost
		<< " euros\n";
	std::setprecision(defaultPrecision);
}

/**
 * Find all the roots, real or imaginary, of the quadratic equation ax^2 + bx + c = 0
 *
 * @brief find the root of quadratic equation
 */
void roots(void) {
	/* 2.5 */
	double a, b, c, delta;
	struct Complex {
		double real;
		double imaginary;
	};
	struct Complex roots[2];
	std::cout << "\nExercise 2.5\n";

	do {
		std::cout << "Find roots of quadratic equation ax^2 + bx + c = 0\nEnter a: ";
		std::cin >> a;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		std::cout << "Enter b: ";
		std::cin >> b;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		std::cout << "Enter c: ";
		std::cin >> c;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		if (a == 0) {
			std::cout << "Invalid quadratic equation\n";
		} else {
			delta = b * b - 4.0 * a * c;

			std::streamsize defaultPrecision = std::cout.precision();
			if (!delta) {
				roots->real = -b / (2 * a);
				std::cout << std::fixed << std::setprecision(3) << "The root is: " << roots->real << "\n";
			} else if (delta > 0) {
				roots->real = (-b + sqrt(delta)) / (2 * a);
				(roots + 1)->real = (-b - sqrt(delta)) / (2 * a);
				std::cout << std::fixed << std::setprecision(3) << "The roots are: " << roots->real
					<< " and " << (roots + 1)->real << "\n";
			} else if (delta < 0) {
				roots->real = -b / (2 * a);
				roots->imaginary = sqrt(-delta) / (2 * a);
				(roots + 1)->real = -b / (2 * a);
				(roots + 1)->imaginary = -sqrt(-delta) / (2 * a);
				std::cout << std::fixed << std::setprecision(3) << "The roots are: " << roots->real
					<< ((roots->imaginary >= 0) ? "+" : "") << roots->imaginary << "i"
					<< " and " << (roots + 1)->real << (((roots + 1)->imaginary >= 0) ? "+" : "") << (roots + 1)->imaginary << "\n";
			}
			std::setprecision(defaultPrecision);
		}
	} while (!a);
}

/**
 * Checks if number is prime | Outputs all primes below limit | Outputs first N primes
 *
 * @brief prime checker, prime lister
 */
void primes(void) {
	/* 2.6 */
	int choice = 0, n = 0;
	std::cout << "\nExercise 6\n";
	std::cout
		<< "Modes:\nEnter 0 to check if number is prime\nEnter 1 to find the n first primes\nEnter 2 to find all primes inferior to n\n";
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

		std::cout << n << ((isPrime2(n)) ? " is " : " is not ") << "prime\n";
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
				std::cout << prime << " ";
				prime++;
				continue;
			}
			while (!isPrime2(prime))
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
			if (isPrime2(prime))
				std::cout << " " << prime;

			prime += 2;
		}
		std::cout << "\nCompleted\n";
		return;
	default:
		std::cout << "Invalid input\n";
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
int isPrime2(int n) {
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
 * Outputs all values for sine, cosine and tangent of the angles between the limits
 * user specifies with an incrementer also specified by user
 *
 * @brief outputs trigonometric table
 */
void trigTable(void) {
	/* 2.7 */
	double limit1 = 0, limit2 = 90, inc = 15;
	std::cout << "\nExercise 2.7\n";
	std::cout << "Enter the first limit for the trignometric table (degrees): ";
	std::cin >> limit1;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the second limit for the trignometric table (degrees): ";
	std::cin >> limit2;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the incrementer: ";
	std::cin >> inc;
	if (std::cin.fail() || inc == 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	if (limit1 > limit2 && inc > 0) {
		std::cout << "Invalid limits\n";
		return;
	} else if (limit1 < limit2 && inc > 0) {
		std::cout << "Invalid limits\n";
	}

	double sinval, cosval, tgval;
	std::cout << "Angle\t\tSin\t\t\tCos\t\t\tTan\n";
	for (double angle = limit1; angle <= limit2; angle += inc) {
		sinval = sin(toRad(angle));
		cosval = cos(toRad(angle));
		if (angle == (int)angle && (int)angle % 180 != 0 && (int)angle % 90 == 0) {
			std::cout << angle << "\t\t" << sinval << "\t\t" << cosval << "\t\tundefined\n";
		} else {
			tgval = tan(toRad(angle));
			std::cout << angle << "\t\t" << sinval << "\t\t" << cosval << "\t\t" << tgval << "\n";
		}
	}
}

/**
 * Converts an angle in degrees to radians
 *
 * @brief conversion from degrees to radians
 * @param angle angle in degrees
 * @return angle in radians
 */
inline double toRad(double angle) {
	return angle * PI / 180.0;
}

/**
 * User inputs an initial amount, the interest rate and the period of time, and
 * outputs the value that will be accumulated over that period of time
 *
 * @brief calculates the value accumulated over a period of time
 */
void compoundInterest(void) {
	/* 2.8 */
	double years = 0, deposit = 0, interest = 0, amount;
	std::cout << "\nExercise 2.8\n";
	std::cout << "Compound Interest\nEnter the inital deposit (euros): ";
	std::cin >> deposit;
	if (std::cin.fail() || deposit < 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the interest (in percentage): ";
	std::cin >> interest;
	if (std::cin.fail() || interest < 0 || interest > 100) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}
	std::cout << "Enter the wait time in years (minimum 1 year): ";
	std::cin >> years;
	if (std::cin.fail() || years < 1) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	interest /= 100.0;
	amount = deposit * pow(1.0 + interest, years);

	std::streamsize defaultPrecision = std::cout.precision();
	std::cout << std::fixed << std::setprecision(2) << "After " << years
		<< " years the amount available will be: " << amount << " euros\n";
	std::setprecision(defaultPrecision);
}

/**
 * @brief reads a int array from user
 */
void arrayInputReader(void) {
	/* 2.9 */
	unsigned int size = 0, mode = 0;
	double sum = 0, avg = 0, min = INT_MAX, max = INT_MIN, input = 0;
	std::cout << "\nExercise 2.9\n";
	std::cout << "Input array modes:\nEnter 1 for exit when 0 is entered\nEnter 2 to give specific size\nEnter 3 to end array input on CTRL-Z\n";
	std::cout << "Enter mode: ";
	std::cin >> mode;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	switch (mode) {
	case 1:
		while (1) {
			std::cout << "Enter next number (enter 0 to finish): ";
			std::cin >> input;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
				std::cout << "Invalid input\n";
			} else {

				if (input == 0)
					break;

				size++;
				if (input > max)
					max = input;
				if (input < min)
					min = input;
				sum += input;
			}
		}
		break;
	case 2:
		std::cout << "Enter the size of the array: ";
		std::cin >> size;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		for (unsigned int i = 0; i < size; i++) {
			std::cout << "Enter next number: ";
			std::cin >> input;
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
				std::cout << "Invalid input\n";
				std::cout << "Enter a number again: ";
				std::cin >> input;
			}

			if (input > max)
				max = input;
			if (input < min)
				min = input;
			sum += input;
		}
		break;
	case 3:
		while (mode) {
			std::cout << "Enter the next number (CTRL-Z to finish): ";
			std::cin >> input;
			while (std::cin.fail()) {

				if (std::cin.eof()) {
					std::cin.clear();
					mode = 0;
					break;
				}

				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
				std::cout << "Invalid input\n";
				std::cout << "Enter a number again (CTRL-Z to finish): ";
				std::cin >> input;
			}
			if (mode) {
				if (input > max)
					max = input;
				if (input < min)
					min = input;
				sum += input;
				size++;
			}
		}
		break;
	default:
		std::cout << "Invalid mode\n";
		return;
	}

	if (size == 0) {
		std::cout << "Empty array\n";
		return;
	}

	avg = sum / size;
	std::cout << "The size of the array is " << size << "\n";
	std::streamsize defaultPrecision = std::cout.precision();
	std::cout << std::fixed << std::setprecision(3) << "Sum: " << sum << "\nAverage: " << avg
		<< "\nMinimum: " << min << "\nMaximum: " << max << "\n";
	std::setprecision(defaultPrecision);
}

/**
 * User inputs number and outputs whether the number is a palindrome or not
 * (same number if reversed)
 *
 * @brief checks if a number is a palindrome
 */
void palindromeChecker(void) {
	/* 2.10 */
	unsigned int num = 0, noDigits = 0, leftDigit, rightDigit, palindrome = 1;
	std::cout << "\nExercise 2.10\n";
	std::cout << "Palindrome Checker\nEnter a whole number (greater than 0): ";
	std::cin >> num;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	noDigits = (unsigned int)(log(num) / log(10)) + 1;
	for (unsigned int i = 0; i < noDigits / 2; i++) {
		rightDigit = (num / (int)pow(10, i)) % 10;
		leftDigit = (num / (int)pow(10, noDigits - 1 - i)) % 10;
		if (rightDigit != leftDigit) {
			palindrome = 0;
			break;
		}
	}
	std::cout << "The number " << num << (palindrome ? " is " : " is not ") << "a palindrome\n";
}

/**
 * Approximates the value of the sum of special sum series:
 * 	- Sum series that approximates the value of euler number
 * 	- Sum series that approximates the value of PI
 * 	- Sum series that approximates the value of exponential
 *
 * @brief approximates the value of special sum series
 */
void sumSeries(void) {
	/* 2.11 */
	unsigned int choice = 0;
	std::cout << "\nExercise 2.11\n";
	std::cout
		<< "Select Series\nEnter 1 for series that generates PI\nEnter 2 for series that generates e\nEnter 3 for series that generates e^x\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	unsigned int n = 0;
	unsigned long long factorial = 1;
	double x = 0;
	double sum = 0;

	std::cout << "Enter n (number of terms): ";
	std::cin >> n;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	switch (choice) {
	case 1:
		for (unsigned int i = 0; i < n; i++) {
			sum += ((i % 2 == 0) ? 1.0 : -1.0) * 4.0 / (2 * i + 1);
		}
		break;
	case 2:
		for (unsigned int i = 0; i < n; i++) {
			factorial *= ((i == 0) ? 1 : i) % (1ULL << 63);
			sum += factorial ? (1.0 / factorial) : 0.0;
		}
		break;
	case 3:
		std::cout << "Enter x: ";
		std::cin >> x;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		for (unsigned int i = 0; i < n; i++) {
			factorial *= ((i == 0) ? 1 : i) % (1ULL << 63);
			x *= (i <= 1) ? 1 : x;
			sum += factorial ? (pow(-1, i) * ((i == 0) ? 1 : x) / factorial) : 0.0;
		}
		break;
	default:
		std::cout << "Invalid mode\n";
		return;
	}
	std::cout << ((choice == 1) ? "PI" : ((choice == 2) ? "e" : "e^x")) << " ~= " << sum << "\n";
}

/**
 * Approximates the value of the sum of special sum series:
 * 	- Sum series that approximates the value of euler number
 * 	- Sum series that approximates the value of PI
 * 	- Sum series that approximates the value of exponential
 * Approximation stops when difference between the terms is lower than the precision
 *
 * @brief approximates the value of special sum series
 */
void sumSeriesPrecision(void) {
	/* 2.12 */
	unsigned int choice = 0;
	std::cout << "\nExercise 2.12\n";
	std::cout << "Select Series\nEnter 1 for series that generates PI\nEnter 2 for series that generates e\nEnter 3 for series that generates e^x\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	unsigned int n = 0;
	unsigned long long factorial = 1;
	double x = 0, precision = 0;
	double sum = 0, term = 0;
	std::cout << "Enter the precision (maximum variance between terms) (0 to disable): ";
	std::cin >> precision;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter n (number of terms): ";
	std::cin >> n;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	precision = fabs(precision);
	switch (choice) {
	case 1:
		for (unsigned int i = 0; i < n; i++) {
			if (precision == 0) {
				sum += ((i % 2 == 0) ? 1.0 : -1.0) * 4.0 / (2 * i + 1);
			} else {
				term = ((i % 2 == 0) ? 1.0 : -1.0) * 4.0 / (2 * i + 1);
				sum += (fabs(term - sum) <= precision) ? term : 0.0;
			}
		}
		break;
	case 2:
		for (unsigned int i = 0; i < n; i++) {
			factorial *= ((i == 0) ? 1 : i) % (1ULL << 63);
			if (precision == 0) {
				sum += factorial ? (1.0 / factorial) : 0;
			} else {
				term = factorial ? (1.0 / factorial) : 0;
				sum += (fabs(term - sum) <= precision) ? term : 0.0;
			}
		}
		break;
	case 3:
		std::cout << "Enter x: ";
		std::cin >> x;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		for (unsigned int i = 0; i < n; i++) {
			factorial *= ((i == 0) ? 1 : i) % (1ULL << 63);
			x *= (i <= 1) ? 1 : x;
			if (precision == 0) {
				sum += factorial ? (pow(-1, i) * ((i == 0) ? 1 : x) / factorial) : 0;
			} else {
				term = factorial ? (pow(-1, i) * ((i == 0) ? 1 : x) / factorial) : 0;
				sum += (fabs(term - sum) <= precision) ? term : 0.0;
			}
		}
		break;
	default:
		std::cout << "Invalid mode\n";
		return;
	}
	std::cout << ((choice == 1) ? "PI" : ((choice == 2) ? "e" : "e^x")) << " ~= " << sum << "\n";
}

/**
 * Factorise a number in its prime factors
 *
 * @brief prime factorisation of a number
 */
void factorize(void) {
	/* 2.13 */
	int num = 0, negative = 0;
	int size = 1, index = 0;
	int* primes = (int*)malloc(size * sizeof(int));
	std::cout << "\nExercise 2.13\n";
	std::cout << "Factorise number\nEnter a whole number: ";
	std::cin >> num;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		free(primes);
		std::cout << "Invalid input\n";
		return;
	}

	if (num < 0) {
		negative = 1;
		num = -num;
	}

	int factorsSize = 1;
	int* factors = (int*)malloc(factorsSize * sizeof(int));
	if (isPrime2(num) || num < 2) {
		*factors = num;
	} else {
		for (int prime = 2; prime < num; prime += 2) {
			if (index >= size) {
				size *= 2;
				primes = (int*)realloc(primes, size * sizeof(int));
			}

			if (prime == 2) {
				*(primes + index) = prime;
				index++;
				prime--;
				continue;
			}
			if (isPrime2(prime)) {
				*(primes + index) = prime;
				index++;
			}
		}
		int copy = num;
		int finished = 0, factor;
		index = 0;
		while (copy > 1 && !finished) {
			finished = 1;
			for (int i = 0; i < size; i++) {
				factor = *(primes + i);
				if (copy % factor == 0) {
					if (index >= factorsSize) {
						factorsSize *= 2;
						factors = (int*)realloc(factors, factorsSize * sizeof(int));
					}
					*(factors + index) = factor;
					copy /= factor;
					index++;
					finished = 0;
					break;
				}
			}
		}
	}
	std::cout << "The factorisation is: ";
	std::cout << num << "=" << (negative ? "-" : "");
	for (int i = 0; i < factorsSize; i++) {
		std::cout << ((i == 0) ? "" : "x") << *(factors + i);
	}
	std::cout << "\n";
	free(primes);
	free(factors);
}

/**
 * Approximates the square root of a number using Newton's method of approximation
 *
 * @brief approximates the square root of a number
 */
void sqrtApprox(void) {
	/* 2.14 */
	double num = 0, delta = 0, approx = 1, diff = 0, newApprox, newApproxSqr;
	unsigned int maxIter = 0, negative = 0;
	std::cout << "\nExercise 2.14\n";
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

	std::cout << "Approximation table for square root of " << num << "\n";
	std::cout << "Root\t\tApprox\t\tSquared Approx\t\tDif = n - squaredApprox\n";

	if (num < 0) {
		negative = 1;
		num = -num;
	}
	for (unsigned int i = 0; i < maxIter && (fabs(diff) > delta || i == 0); i++) {
		newApprox = (approx + num / approx) / 2.0;
		newApproxSqr = newApprox * newApprox;
		diff = num - newApproxSqr;
		std::cout << approx << ((negative && i != 0) ? "i" : "") << "\t\t" << newApprox
			<< (negative ? "i" : "") << "\t\t" << (negative ? "-" : "") << newApproxSqr
			<< "\t\t\t" << diff << "\n";
		approx = newApprox;
	}
}

/**
 * Test multiplication table with user and evaluates the user performance
 *
 * @brief simple multiplication tester
 */
void multTest(void) {
	/* 2.15 */
	int *randoms = (int*)malloc(2 * sizeof(int));
	int expected = 0, actual = 0;
	clock_t timer;
	std::cout << "\nExercise 2.15\n";
	std::cout << "Test your multiplication:\n";

	srand((int)time(NULL));
	*randoms = rand() % 8 + 2;
	*(randoms + 1) = rand() % 8 + 2;
	expected = *randoms * *(randoms + 1);
	std::cout << "Answer what's " << *randoms << "x" << *(randoms + 1) << "= ";
	timer = clock();
	std::cin >> actual;
	timer = (clock() - timer) / (clock_t)CLOCKS_PER_SEC;

	if (actual != expected) {
		std::cout << "Horrible\n";
	} else {
		if (timer < 5)
			std::cout << "Great\n";
		else if (timer <= 10)
			std::cout << "Ok\n";
		else
			std::cout << "Bad, you took too long\n";
	}

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
	}
	free(randoms);
}
