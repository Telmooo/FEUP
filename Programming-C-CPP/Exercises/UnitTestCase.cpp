/**
 * @file UnitTestCase.hpp
 *
 * @brief Source Code for Unit Test Case
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#include "UnitTestCase.hpp"
#include "Exercise3.hpp"
#include <iostream>
#include <limits>

 /**
  * Runs Unit Case
  * Allows user to choose which unit case to execute
  *
  * @brief execute unit case
  */
void runUnitTestCase(void) {
	int unit = 0, errors = 0;

	while (true) {
		std::cout << "\nRunning Unit Testing\nEnter the unit test to run:\n0 to exit\n1 to run Unit Test 3\n2 to run Unit Test 4\n3 to run both Unit Tests\n";
		std::cout << "Enter your choice: ";
		std::cin >> unit;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			unit = -1;
		}

		switch (unit) {
		case 0:
			std::cout << "Exiting...\n";
			return;
		case 1:
			std::cout << "\nRunning Unit Test Case 3...\n";
			errors = unitTestCase3();
			std::cout << "Unit Test Case 3 finished with " << errors << " errors\n";
			break;
		case 2:
			std::cout << "\nRunning Unit Test Case 4...\n";
			errors = unitTestCase4();
			std::cout << "Unit Test Case 4 finished with " << errors << " errors\n";
			break;
		case 3:
			std::cout << "\nRunning Unit Test Case 3...\n";
			errors = unitTestCase3();
			std::cout << "Unit Test Case 3 finished with " << errors << " errors\n";
			std::cout << "\nRunning Unit Test Case 4...\n";
			errors = unitTestCase4();
			std::cout << "Unit Test Case 4 finished with " << errors << " errors\n";
			break;
		default:
			std::cout << "Invalid mode\n\n";
		}
	}
}

/**
 * Runs unit case for exercise 3
 * Contains tests for functions:
 *  - round
 *  - reduceFracc
 *  - arithmeticFracc
 *  - gcd_rec
 *
 * @brief unit case for exercise 3
 * @return number of erros during trial
 */
int unitTestCase3(void) {
	int errors = 0;

	{
		std::cout << "Testing function round\n";
		errors += !assert_EQ(round(125.023414, 3), 125.023, 0.00001, "Positive Double Test");
		errors += !assert_EQ(round(16, 4), 16.0000, 0.00001, "Positive Integer Test");
		errors += !assert_EQ(round(0, 0), 0.0, 0.00001, "Zero Value Test");
		errors += !assert_EQ(round(-12.512375, 4), -12.5124, 0.00001, "Negative Double Test");
		errors += !assert_EQ(round(-4, 1), -4.0, 0.00001, "Negative Integer Test");
	}

	{
		std::cout << "Testing fraction functions\n";
		int *fracc1 = new int[2], *fracc2 = new int[2];
		std::cout << "Testing reduce fraction\n";
		*fracc1 = 4;
		*(fracc1 + 1) = 20;
		*fracc2 = 1;
		*(fracc2 + 1) = 5;
		reduceFracc(fracc1[0], fracc1[1]);
		errors += !assert_EQ(fracc1, 2, fracc2, 2, "Normal Fraction Test");
		*fracc1 = 1;
		*(fracc1 + 1) = 0;
		*fracc2 = 1;
		*(fracc2 + 1) = 0;
		reduceFracc(fracc1[0], fracc1[1]);
		errors += !assert_EQ(fracc1, 2, fracc2, 2, "Infinite Fraction Test");
		*fracc1 = -1;
		*(fracc1 + 1) = 0;
		*fracc2 = -1;
		*(fracc2 + 1) = 0;
		reduceFracc(fracc1[0], fracc1[1]);
		errors += !assert_EQ(fracc1, 2, fracc2, 2, "Negative Infinite Fraction Test");
		*fracc1 = 0;
		*(fracc1 + 1) = 0;
		*fracc2 = 0;
		*(fracc2 + 1) = 0;
		reduceFracc(fracc1[0], fracc1[1]);
		errors += !assert_EQ(fracc1, 2, fracc2, 2, "Undefined Fraction Test");

		std::cout << "Testing arithmetic operations\n";
		int *expected = new int[2], *actual;
		*fracc1 = 3;
		*(fracc1 + 1) = 20;
		*fracc2 = 7;
		*(fracc2 + 1) = 20;
		*expected = 1;
		*(expected + 1) = 2;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 0, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Equal Denominator Adding Test");
		free(actual);

		*fracc1 = 4;
		*(fracc1 + 1) = 5;
		*fracc2 = 9;
		*(fracc2 + 1) = 13;
		*expected = 97;
		*(expected + 1) = 65;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 0, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Different Denominator Adding Test");
		free(actual);

		*fracc1 = -5;
		*(fracc1 + 1) = 6;
		*fracc2 = 10;
		*(fracc2 + 1) = 12;
		*expected = 0;
		*(expected + 1) = 1;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 0, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Zero Adding Test");
		free(actual);

		*fracc1 = -1;
		*(fracc1 + 1) = 0;
		*fracc2 = 7;
		*(fracc2 + 1) = 6;
		*expected = -1;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 0, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Infinite Adding Test");
		free(actual);

		*fracc1 = 1;
		*(fracc1 + 1) = 0;
		*fracc2 = -6;
		*(fracc2 + 1) = 0;
		*expected = 0;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 0, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Undefined Adding Test");
		free(actual);

		*fracc1 = 8;
		*(fracc1 + 1) = 5;
		*fracc2 = 2;
		*(fracc2 + 1) = 13;
		*expected = 94;
		*(expected + 1) = 65;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 1, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Different Denominator Subtracting Test");
		free(actual);

		*fracc1 = 5;
		*(fracc1 + 1) = 3;
		*fracc2 = 1;
		*(fracc2 + 1) = 0;
		*expected = -1;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 1, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Infinite Subtracting Test");
		free(actual);

		*fracc1 = 5;
		*(fracc1 + 1) = 0;
		*fracc2 = 1;
		*(fracc2 + 1) = 0;
		*expected = 0;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 1, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Undefined Subtracting Test");
		free(actual);

		*fracc1 = 3;
		*(fracc1 + 1) = 7;
		*fracc2 = 6;
		*(fracc2 + 1) = 5;
		*expected = 18;
		*(expected + 1) = 35;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 2, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Normal Multiplication Test");
		free(actual);

		*fracc1 = 3;
		*(fracc1 + 1) = 7;
		*fracc2 = -6;
		*(fracc2 + 1) = 5;
		*expected = -18;
		*(expected + 1) = 35;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 2, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Normal Multiplication Test");
		free(actual);

		*fracc1 = -3;
		*(fracc1 + 1) = 2;
		*fracc2 = 5;
		*(fracc2 + 1) = -8;
		*expected = 15;
		*(expected + 1) = 16;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 2, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Negative Multiplication Test");
		free(actual);

		*fracc1 = -1;
		*(fracc1 + 1) = 0;
		*fracc2 = -6;
		*(fracc2 + 1) = 177;
		*expected = 1;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 2, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Infinite Multiplication Test");
		free(actual);

		*fracc1 = 3;
		*(fracc1 + 1) = 0;
		*fracc2 = -6;
		*(fracc2 + 1) = 5;
		*expected = -1;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 2, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Negative Infinite Multiplication Test");
		free(actual);

		*fracc1 = 5;
		*(fracc1 + 1) = 0;
		*fracc2 = -3;
		*(fracc2 + 1) = 0;
		*expected = -1;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 2, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "InfxInf Multiplication Test");
		free(actual);

		*fracc1 = 0;
		*(fracc1 + 1) = 154;
		*fracc2 = 3281;
		*(fracc2 + 1) = 0;
		*expected = 0;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 2, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Undefined Multiplication Test");
		free(actual);

		*fracc1 = -9;
		*(fracc1 + 1) = 7;
		*fracc2 = 2;
		*(fracc2 + 1) = -5;
		*expected = 45;
		*(expected + 1) = 14;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 3, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Normal Division Test");
		free(actual);

		*fracc1 = -3;
		*(fracc1 + 1) = 7;
		*fracc2 = 6;
		*(fracc2 + 1) = 5;
		*expected = -5;
		*(expected + 1) = 14;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 3, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Normal Division Test");
		free(actual);

		*fracc1 = 5;
		*(fracc1 + 1) = 3;
		*fracc2 = 2;
		*(fracc2 + 1) = 0;
		*expected = 0;
		*(expected + 1) = 1;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 3, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Infinite Division Test");
		free(actual);

		*fracc1 = 3;
		*(fracc1 + 1) = -7;
		*fracc2 = 0;
		*(fracc2 + 1) = 5;
		*expected = 1;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 3, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Zero Division Test");
		free(actual);

		*fracc1 = 5;
		*(fracc1 + 1) = 0;
		*fracc2 = -2;
		*(fracc2 + 1) = 0;
		*expected = 0;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 3, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Undefined Inf/Inf Division Test");
		free(actual);

		*fracc1 = 0;
		*(fracc1 + 1) = 2;
		*fracc2 = 0;
		*(fracc2 + 1) = 5;
		*expected = 0;
		*(expected + 1) = 0;
		actual = arithmeticFracc(fracc1[0], fracc1[1], 3, fracc2[0], fracc2[1]);
		errors += !assert_EQ(actual, 2, expected, 2, "Undefined 0/0 Division Test");
		free(actual);

		delete[] fracc1;
		delete[] fracc2;
		delete[] expected;
	}

	{
		std::cout << "Testing Euclidean Algorithm for Greatest Common Divisor\n";
		errors += !assert_EQ(gcd_rec(15, 5), 5, "Basic GCD Test");
		errors += !assert_EQ(gcd_rec(-1247524, 3161336), 4, "Negative GCD Test");
		errors += !assert_EQ(gcd_rec(0, -7), 7, "0-n GCD Test");
		errors += !assert_EQ(gcd_rec(-3, 0), 3, "n-0 GCD Test");
		errors += !assert_EQ(gcd_rec(0, 0), 0, "0-0 GCD Test");
	}
	return errors;
}

/**
 * Runs unit case for exercise 4
 * Contains tests for functions:
 *  - isHydroxide
 *  - reduceFraction
 *  - arithmeticFraction
 *  - array functions
 *  - vector functions
 *  - algorithms
 *  - remove duplicates
 *  - union/intersection of vectors
 *  - operation parser
 *
 * @brief unit case for exercise 4
 * @return number of erros during trial
 */
int unitTestCase4(void) {
	int errors = 0;

	{
		std::cout << "Testing Hydroxide Classifier Function\n";
		std::cout << "Testing C style function\n";
		char chem[36] = "NaOH";
		errors += !assert_EQ(isHydroxide(chem), true, "NaOH Test");
		strcpy_s(chem, "KOH");
		errors += !assert_EQ(isHydroxide(chem), true, "KOH Test");
		strcpy_s(chem, "H202");
		errors += !assert_EQ(isHydroxide(chem), false, "H202 Test");
		strcpy_s(chem, "NaCl");
		errors += !assert_EQ(isHydroxide(chem), false, "NaCl Test");
		strcpy_s(chem, "C9H8O4");
		errors += !assert_EQ(isHydroxide(chem), false, "C9H8O4 Test");
		strcpy_s(chem, "MgOH");
		errors += !assert_EQ(isHydroxide(chem), true, "MgOH Test");
		strcpy_s(chem, "Ba(OH)2.8H2O");
		errors += !assert_EQ(isHydroxide(chem), true, "Ba(OH)2.8H2O Test");
		strcpy_s(chem, "yes");
		errors += !assert_EQ(isHydroxide(chem), false, "Random Test");
		strcpy_s(chem, "Hg2(OH)2");
		errors += !assert_EQ(isHydroxide(chem), true, "Hg2(OH)2 Test");
		strcpy_s(chem, "C169,719H270,464N45,688O52,237S911");
		errors += !assert_EQ(isHydroxide(chem), false, "Tintin Test");

		std::cout << "Testing C++ style function\n";
		std::string chemical = "NaOH";
		errors += !assert_EQ(isHydroxide(chemical), true, "NaOH Test");
		chemical = "KOH";
		errors += !assert_EQ(isHydroxide(chemical), true, "KOH Test");
		chemical = "H202";
		errors += !assert_EQ(isHydroxide(chemical), false, "H202 Test");
		chemical = "NaCl";
		errors += !assert_EQ(isHydroxide(chemical), false, "NaCl Test");
		chemical = "C9H8O4";
		errors += !assert_EQ(isHydroxide(chemical), false, "C9H8O4 Test");
		chemical = "MgOH";
		errors += !assert_EQ(isHydroxide(chemical), true, "MgOH Test");
		chemical = "Ba(OH)2.8H2O";
		errors += !assert_EQ(isHydroxide(chemical), true, "Ba(OH)2.8H2O Test");
		chemical = "yes";
		errors += !assert_EQ(isHydroxide(chemical), false, "Random Test");
		chemical = "Hg2(OH)2";
		errors += !assert_EQ(isHydroxide(chemical), true, "Hg2(OH)2 Test");
		chemical = "C169,719H270,464N45,688O52,237S911";
		errors += !assert_EQ(isHydroxide(chemical), false, "Tintin Test");
	}

	{
		std::cout << "Testing Sequence Searcher Function\n";
		errors += !assert_EQ(sequenceSearch("I do Fedora Tricks", 3, 'e'), false,
			"Basic Sequence Search");
		errors += !assert_EQ(sequenceSearch("Yasss", 3, 's'), true, "Basic Sequence Search");
		errors += !assert_EQ(sequenceSearch("ooookkkkaaaayyyiyyyyy", 5, 'y'), true,
			"Basic Sequence Search");
	}

	{
		std::cout << "Testing struct fraction functions\n";
		Fraction fracc1, fracc2;
		std::cout << "Testing reduce fraction\n";
		fracc1.numerator = 4;
		fracc1.denominator = 20;
		fracc2.numerator = 1;
		fracc2.denominator = 5;
		fracc1 = reduceFraction(fracc1);
		errors += !assert_EQ(fracc1, fracc2, "Normal Fraction Test");
		fracc1.numerator = 1;
		fracc1.denominator = 0;
		fracc2.numerator = 1;
		fracc2.denominator = 0;
		fracc1 = reduceFraction(fracc1);
		errors += !assert_EQ(fracc1, fracc2, "Infinite Fraction Test");
		fracc1.numerator = -1;
		fracc1.denominator = 0;
		fracc2.numerator = -1;
		fracc2.denominator = 0;
		fracc1 = reduceFraction(fracc1);
		errors += !assert_EQ(fracc1, fracc2, "Negative Infinite Fraction Test");
		fracc1.numerator = 0;
		fracc1.denominator = 0;
		fracc2.numerator = 0;
		fracc2.denominator = 0;
		fracc1 = reduceFraction(fracc1);
		errors += !assert_EQ(fracc1, fracc2, "Undefined Fraction Test");

		std::cout << "Testing arithmetic operations\n";
		Fraction expected, actual;
		fracc1.numerator = 3;
		fracc1.denominator = 20;
		fracc2.numerator = 7;
		fracc2.denominator = 20;
		expected.numerator = 1;
		expected.denominator = 2;
		actual = arithmeticFraction(fracc1, 0, fracc2);
		errors += !assert_EQ(actual, expected, "Equal Denominator Adding Test");

		fracc1.numerator = 4;
		fracc1.denominator = 5;
		fracc2.numerator = 9;
		fracc2.denominator = 13;
		expected.numerator = 97;
		expected.denominator = 65;
		actual = arithmeticFraction(fracc1, 0, fracc2);
		errors += !assert_EQ(actual, expected, "Different Denominator Adding Test");

		fracc1.numerator = -5;
		fracc1.denominator = 6;
		fracc2.numerator = 10;
		fracc2.denominator = 12;
		expected.numerator = 0;
		expected.denominator = 1;
		actual = arithmeticFraction(fracc1, 0, fracc2);
		errors += !assert_EQ(actual, expected, "Zero Adding Test");

		fracc1.numerator = -1;
		fracc1.denominator = 0;
		fracc2.numerator = 7;
		fracc2.denominator = 6;
		expected.numerator = -1;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 0, fracc2);
		errors += !assert_EQ(actual, expected, "Infinite Adding Test");

		fracc1.numerator = 1;
		fracc1.denominator = 0;
		fracc2.numerator = -6;
		fracc2.denominator = 0;
		expected.numerator = 0;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 0, fracc2);
		errors += !assert_EQ(actual, expected, "Undefined Adding Test");

		fracc1.numerator = 8;
		fracc1.denominator = 5;
		fracc2.numerator = 2;
		fracc2.denominator = 13;
		expected.numerator = 94;
		expected.denominator = 65;
		actual = arithmeticFraction(fracc1, 1, fracc2);
		errors += !assert_EQ(actual, expected, "Different Denominator Subtracting Test");

		fracc1.numerator = 5;
		fracc1.denominator = 3;
		fracc2.numerator = 1;
		fracc2.denominator = 0;
		expected.numerator = -1;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 1, fracc2);
		errors += !assert_EQ(actual, expected, "Infinite Subtracting Test");

		fracc1.numerator = 5;
		fracc1.denominator = 0;
		fracc2.numerator = 1;
		fracc2.denominator = 0;
		expected.numerator = 0;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 1, fracc2);
		errors += !assert_EQ(actual, expected, "Undefined Subtracting Test");

		fracc1.numerator = 3;
		fracc1.denominator = 7;
		fracc2.numerator = 6;
		fracc2.denominator = 5;
		expected.numerator = 18;
		expected.denominator = 35;
		actual = arithmeticFraction(fracc1, 2, fracc2);
		errors += !assert_EQ(actual, expected, "Normal Multiplication Test");

		fracc1.numerator = 3;
		fracc1.denominator = 7;
		fracc2.numerator = -6;
		fracc2.denominator = 5;
		expected.numerator = -18;
		expected.denominator = 35;
		actual = arithmeticFraction(fracc1, 2, fracc2);
		errors += !assert_EQ(actual, expected, "Normal Multiplication Test");

		fracc1.numerator = -3;
		fracc1.denominator = 2;
		fracc2.numerator = 5;
		fracc2.denominator = -8;
		expected.numerator = 15;
		expected.denominator = 16;
		actual = arithmeticFraction(fracc1, 2, fracc2);
		errors += !assert_EQ(actual, expected, "Negative Multiplication Test");

		fracc1.numerator = -1;
		fracc1.denominator = 0;
		fracc2.numerator = -6;
		fracc2.denominator = 177;
		expected.numerator = 1;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 2, fracc2);
		errors += !assert_EQ(actual, expected, "Infinite Multiplication Test");

		fracc1.numerator = 3;
		fracc1.denominator = 0;
		fracc2.numerator = -6;
		fracc2.denominator = 5;
		expected.numerator = -1;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 2, fracc2);
		errors += !assert_EQ(actual, expected, "Negative Infinite Multiplication Test");

		fracc1.numerator = 5;
		fracc1.denominator = 0;
		fracc2.numerator = -3;
		fracc2.denominator = 0;
		expected.numerator = -1;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 2, fracc2);
		errors += !assert_EQ(actual, expected, "InfxInf Multiplication Test");

		fracc1.numerator = 0;
		fracc1.denominator = 154;
		fracc2.numerator = 3281;
		fracc2.denominator = 0;
		expected.numerator = 0;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 2, fracc2);
		errors += !assert_EQ(actual, expected, "Undefined Multiplication Test");

		fracc1.numerator = -9;
		fracc1.denominator = 7;
		fracc2.numerator = 2;
		fracc2.denominator = -5;
		expected.numerator = 45;
		expected.denominator = 14;
		actual = arithmeticFraction(fracc1, 3, fracc2);
		errors += !assert_EQ(actual, expected, "Normal Division Test");

		fracc1.numerator = -3;
		fracc1.denominator = 7;
		fracc2.numerator = 6;
		fracc2.denominator = 5;
		expected.numerator = -5;
		expected.denominator = 14;
		actual = arithmeticFraction(fracc1, 3, fracc2);
		errors += !assert_EQ(actual, expected, "Normal Division Test");

		fracc1.numerator = 5;
		fracc1.denominator = 3;
		fracc2.numerator = 2;
		fracc2.denominator = 0;
		expected.numerator = 0;
		expected.denominator = 1;
		actual = arithmeticFraction(fracc1, 3, fracc2);
		errors += !assert_EQ(actual, expected, "Infinite Division Test");

		fracc1.numerator = 3;
		fracc1.denominator = -7;
		fracc2.numerator = 0;
		fracc2.denominator = 5;
		expected.numerator = 1;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 3, fracc2);
		errors += !assert_EQ(actual, expected, "Zero Division Test");

		fracc1.numerator = 5;
		fracc1.denominator = 0;
		fracc2.numerator = -2;
		fracc2.denominator = 0;
		expected.numerator = 0;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 3, fracc2);
		errors += !assert_EQ(actual, expected, "Undefined Inf/Inf Division Test");

		fracc1.numerator = 0;
		fracc1.denominator = 2;
		fracc2.numerator = 0;
		fracc2.denominator = 5;
		expected.numerator = 0;
		expected.denominator = 0;
		actual = arithmeticFraction(fracc1, 3, fracc2);
		errors += !assert_EQ(actual, expected, "Undefined 0/0 Division Test");
	}

	{
		std::cout << "Testing Array Functions\n";
		int arr[10] = { 150, -355, -51, 5, 23, 8, -3, 0, 5, 3 };
		errors += !assert_EQ(searchValueInIntArray(arr, 10, -3), 6,
			"Search First Occurrence Array");
		errors += !assert_EQ(searchValueInIntArray(arr, 10, 5), 3, "Search First Occurrence Array");
		errors += !assert_EQ(searchValueInIntArray(arr, 10, 1), -1,
			"Search First Occurrence Array");
		int expected[10] = { 3, 8 };
		int actual[10];
		searchValueInIntArray(arr, 10, 5, actual);
		errors += !assert_EQ(actual, 10, expected, 10, "Search Multiples Values Array");

		std::cout << "Testing Vector Functions\n";
		std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
		errors += !assert_EQ(searchValueInVector(v, -3), (size_t)6,
			"Search First Occurrence Vector");
		errors += !assert_EQ(searchValueInVector(v, 5), (size_t)3,
			"Search First Occurrence Vector");
		errors += !assert_EQ(searchValueInVector(v, 1), (size_t)-1,
			"Search First Occurrence Vector");
		std::vector<int> vExpected{ 3, 8 };
		std::vector<int> vActual = searchMultValuesInVector(v, 5);
		errors += !assert_EQ(vActual, vExpected, "Search Multiple Values Vector");
	}

	{
		std::cout << "Testing Sorting Algorithms\n";
		std::vector<int> actual{ -61, -23, -21, 0, 2, 6, 7, 41, 56 };
		std::vector<int> expected{ -61, -23, -21, 0, 2, 6, 7, 41, 56 };
		shuffle(actual);
		bubbleSort(actual);
		errors += !assert_EQ(actual, expected, "Bubble Sort Integer Test");
		shuffle(actual);
		quickSort(actual, 0, actual.size() - 1);
		errors += !assert_EQ(actual, expected, "Quick Sort Integer Test");
		std::vector < std::string > actualS{ "D6", "Random", "dxs", "txt", "yo" };
		std::vector < std::string > expectedS{ "D6", "Random", "dxs", "txt", "yo" };
		shuffle(actualS);
		bubbleSort(actualS);
		errors += !assert_EQ(actualS, expectedS, "Bubble Sort String Test");
		shuffle(actualS);
		quickSort(actualS, 0, actualS.size() - 1);
		errors += !assert_EQ(actualS, expectedS, "Quick Sort String Test");
	}

	{
		std::cout << "Testing Binary Search Algorithm (String)\n";
		std::vector < std::string > v{ "3213", "D6", "FilLing", "Gas", "Random", "SP", "beep",
				"bop", "dxs", "txt", "yo" };
		errors += !assert_EQ((int)binarySearch(v, "yo"), 10, "Binary Search Test");
		errors += !assert_EQ((int)binarySearch(v, "Random"), 4, "Binary Search Test");
		errors += !assert_EQ((int)binarySearch(v, "D6"), 1, "Binary Search Test");
		errors += !assert_EQ((int)binarySearch(v, "good luck"), -1, "Binary Search Test");
	}

	{
		std::cout << "Testing Duplicates Removal\n";
		std::vector<int> actual{ 0, 1, 6, 8, 4, 8, 1, 3, 5, 6, 4, 2 };
		std::vector<int> expected{ 0, 1, 6, 8, 4, 3, 5, 2 };
		removeDuplicates(actual);
		errors += !assert_EQ(actual, expected, "Duplicates Removal Test");
		std::vector<int> actual_eq{ 0, 1, 2, 3, 4, 5, 6, 7 };
		std::vector<int> expected_eq{ 0, 1, 2, 3, 4, 5, 6, 7 };
		removeDuplicates(actual_eq);
		errors += !assert_EQ(actual_eq, expected_eq, "Equal Vector Test");
	}

	{
		std::cout << "Testing Union and Intersection of Vectors\n";
		std::vector<int> v1{ -5, 3, -6, 8, 2, 7, 1, 7, 4, 15 };
		std::vector<int> v2{ -12, 6, 3, 4, 6, 4, 3, -5, 3, 7 };
		std::vector<int> unionExpected1{ -12, -6, -5, 1, 2, 3, 4, 6, 7, 8, 15 };
		std::vector<int> intersectionExpected1{ -5, 3, 4, 7 };
		std::vector<int> actualUnion1 = vectorUnion(v1, v2);
		std::vector<int> actualIntersection1 = vectorIntersection(v1, v2);
		errors += !assert_EQ(actualUnion1, unionExpected1, "Normal Union Test");
		errors += !assert_EQ(actualIntersection1, intersectionExpected1,
			"Normal Intersection Test");
		std::vector<int> v3{ -4, -8, -2, 6, 3, 1, -4, 1 };
		std::vector<int> v4{ 0, -5, 4, 8, 2, -6, -3, 10, -3 };
		std::vector<int> unionExpected2{ -8, -6, -5, -4, -3, -2, 0, 1, 2, 3, 4, 6, 8, 10 };
		std::vector<int> intersectionExpected2{ };
		std::vector<int> actualUnion2 = vectorUnion(v3, v4);
		std::vector<int> actualIntersection2 = vectorIntersection(v3, v4);
		errors += !assert_EQ(actualUnion2, unionExpected2, "Normal Union Test");
		errors += !assert_EQ(actualIntersection2, intersectionExpected2, "Null Intersection Test");
	}

	{
		std::cout << "Testing simple operation parser\n";
		errors += !assert_EQ(executeOperation("12.3 + 5"), 17.3, 0.00001, "Simple adding Test");
		errors += !assert_EQ(executeOperation("10.2+ 2.4"), 12.6, 0.00001, "Simple adding Test");
		errors += !assert_EQ(executeOperation("1.3+0.3"), 1.6, 0.00001, "Simple adding Test");
		errors += !assert_EQ(executeOperation("12.3 - 5"), 7.3, 0.00001, "Simple subtracting Test");
		errors += !assert_EQ(executeOperation("12.3 * 5"), 61.5, 0.00001,
			"Simple multiplying Test");
		errors += !assert_EQ(executeOperation("12.3 / 5"), 2.46, 0.00001, "Simple division Test");
	}
	return errors;
}

/**
 * Checks for equality between two integers
 *
 * @brief asserts equality
 * @param a actual value
 * @param b expected value
 * @param testInfo Information of the test
 * @return 1 if equal, otherwise 0
 */
bool assert_EQ(int a, int b, std::string testInfo) {
	if (a == b) {
		std::cout << testInfo << ": OK\n";
		return true;
	} else {
		std::cout << testInfo << ": FAILED -> " << a << " should equal " << b << "\n";
		return false;
	}
}

/**
 * Checks for equality between two size_t
 *
 * @overload bool assert_EQ(size_t a, size_t b, std::string testInfo)
 */
bool assert_EQ(size_t a, size_t b, std::string testInfo) {
	if (a == b) {
		std::cout << testInfo << ": OK\n";
		return true;
	} else {
		std::cout << testInfo << ": FAILED -> " << a << " should equal " << b << "\n";
		return false;
	}
}

/**
 * Checks for equality between two booleans
 *
 * @overload bool assert_EQ(bool a, bool b, std::string testInfo)
 */
bool assert_EQ(bool a, bool b, std::string testInfo) {
	if (a == b) {
		std::cout << testInfo << ": OK\n";
		return true;
	} else {
		std::cout << testInfo << ": FAILED -> " << a << " should equal " << b << "\n";
		return false;
	}
}

/**
 * Checks for equality between two doubles (with maximum difference between them inferior to tolerance)
 * Tolerance is zero than it's absolute equality (not recommended)
 *
 * @overload bool assert_EQ(double a, double b, double tolerance, std::string testInfo)
 * @param tolerance Maximum difference between values
 */
bool assert_EQ(double a, double b, double tolerance, std::string testInfo) {
	if (a == b || fabs(a - b) <= tolerance) {
		std::cout << testInfo << ": OK\n";
		return true;
	} else {
		std::cout << testInfo << ": FAILED -> " << a << " should equal " << b << "\n";
		return false;
	}
}

/**
 * Checks for equality between two arrays of integers
 *
 * @overload bool assert_EQ(int a[], int aSize, int b[], int bSize, std::string testInfo)
 * @param aSize size of first array
 * @param bSize size of second array
 */
bool assert_EQ(int a[], int aSize, int b[], int bSize, std::string testInfo) {
	bool equal = true;
	if (aSize == bSize) {
		for (int i = 0; i < aSize; i++) {
			if (a[i] != b[i]) {
				equal = false;
				break;
			}
		}
		if (equal)
			std::cout << testInfo << ": OK\n";
		return true;
	}
	std::cout << testInfo << ": FAILED -> [";
	for (int i = 0; i < aSize; i++)
		std::cout << " " << a[i];
	std::cout << " ] should equal [";
	for (int i = 0; i < bSize; i++)
		std::cout << " " << b[i];
	std::cout << " ]\n";
	return false;
}

/**
 * Checks for equality between two fractions
 *
 * @overload bool assert_EQ(Fraction a, Fraction b, std::string testInfo)
 * @see Fraction
 */
bool assert_EQ(Fraction a, Fraction b, std::string testInfo) {
	if (a.numerator == b.numerator && a.denominator == b.denominator) {
		std::cout << testInfo << ": OK\n";
		return true;
	} else {
		std::cout << testInfo << ": FAILED -> " << a.numerator << "/" << a.denominator
			<< " should equal " << b.numerator << "/" << b.denominator << "\n";
		return false;
	}
}

/**
 * Checks for equality between two vectors of integers
 *
 * @overload bool assert_EQ(const std::vector<int> &a, const std::vector<int> &b, std::string testInfo)
 */
bool assert_EQ(const std::vector<int> &a, const std::vector<int> &b, std::string testInfo) {
	if (a == b) {
		std::cout << testInfo << ": OK\n";
		return true;
	} else {
		std::cout << testInfo << ": FAILED -> [";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << " " << a.at(i);
		std::cout << " ] should equal [";
		for (size_t i = 0; i < b.size(); i++)
			std::cout << " " << b.at(i);
		std::cout << " ]\n";
		return false;
	}
}

/**
 * Checks for equality between two vectors of strings
 *
 * @overload bool assert_EQ(const std::vector<std::string> &a, const std::vector<std::string> &b, std::string testInfo)
 */
bool assert_EQ(const std::vector<std::string> &a, const std::vector<std::string> &b,
	std::string testInfo) {
	if (a == b) {
		std::cout << testInfo << ": OK\n";
		return true;
	} else {
		std::cout << testInfo << ": FAILED -> [";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << " " << a.at(i);
		std::cout << " ] should equal [";
		for (size_t i = 0; i < b.size(); i++)
			std::cout << " " << b.at(i);
		std::cout << " ]\n";
		return false;
	}
}
