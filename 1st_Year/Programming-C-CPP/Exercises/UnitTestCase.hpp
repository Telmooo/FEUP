/**
 * @file UnitTestCase.hpp
 *
 * @brief Declarations for Unit Test Case
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#pragma once
#include "Exercise4.hpp"
#include <string>
#include <vector>
#include <cstddef>

 /**
  * Runs Unit Case
  * Allows user to choose which unit case to execute
  *
  * @brief execute unit case
  */
void runUnitTestCase(void);

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
int unitTestCase3(void);

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
int unitTestCase4(void);

/**
 * Checks for equality between two integers
 *
 * @brief asserts equality
 * @param a actual value
 * @param b expected value
 * @param testInfo Information of the test
 * @return 1 if equal, otherwise 0
 */
bool assert_EQ(int a, int b, std::string testInfo);

/**
 * Checks for equality between two size_t
 *
 * @overload bool assert_EQ(size_t a, size_t b, std::string testInfo)
 */
bool assert_EQ(size_t a, size_t b, std::string testInfo);

/**
 * Checks for equality between two booleans
 *
 * @overload bool assert_EQ(bool a, bool b, std::string testInfo)
 */
bool assert_EQ(bool a, bool b, std::string testInfo);

/**
 * Checks for equality between two doubles (with maximum difference between them inferior to tolerance)
 * Tolerance is zero than it's absolute equality (not recommended)
 *
 * @overload bool assert_EQ(double a, double b, double tolerance, std::string testInfo)
 * @param tolerance Maximum difference between values
 */
bool assert_EQ(double a, double b, double tolerance, std::string testInfo);

/**
 * Checks for equality between two arrays of integers
 *
 * @overload bool assert_EQ(int a[], int aSize, int b[], int bSize, std::string testInfo)
 * @param aSize size of first array
 * @param bSize size of second array
 */
bool assert_EQ(int a[], int aSize, int b[], int bSize, std::string testInfo);

/**
 * Checks for equality between two fractions
 *
 * @overload bool assert_EQ(Fraction a, Fraction b, std::string testInfo)
 * @see Fraction
 */
bool assert_EQ(Fraction a, Fraction b, std::string testInfo);

/**
 * Checks for equality between two vectors of integers
 *
 * @overload bool assert_EQ(const std::vector<int> &a, const std::vector<int> &b, std::string testInfo)
 */
bool assert_EQ(const std::vector<int> &a, const std::vector<int> &b, std::string testInfo);

/**
 * Checks for equality between two vectors of strings
 *
 * @overload bool assert_EQ(const std::vector<std::string> &a, const std::vector<std::string> &b, std::string testInfo)
 */
bool assert_EQ(const std::vector<std::string> &a, const std::vector<std::string> &b,
	std::string testInfo);
