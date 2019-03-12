/**
 * @file main.cpp
 *
 * @brief Main file
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#include "Exercise1.hpp"
#include "Exercise2.hpp"
#include "Exercise3.hpp"
#include "Exercise4.hpp"
#include "UnitTestCase.hpp"
#include <ios>
#include <iostream>
#include <limits>

 /**
  * Introduction to C/C++
  *
  * Main file, basic input system for user to choose exercises
  *
  * @brief input exercise choice
  *
  * @return 0 on successful run, not 0 if any error occurs
  */

int main(void) {
	int choice = 0;
	bool control = true;
	while (control) {
		std::cout << "Keys:\n1 for exercise 1\n2 for exercise 2\n3 for exercise "
			"3\n4 for exercise 4\n5 for Unit Test Case\n0 to exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			choice = -1;
		}

		switch (choice) {
		case 0:
			control = 0;
			break;
		case 1:
			runExercise1();
			break;
		case 2:
			runExercise2();
			break;
		case 3:
			runExercise3();
			break;
		case 4:
			runExercise4();
			break;
		case 5:
			runUnitTestCase();
			break;
		default:
			std::cout << "Invalid entry\n";
			break;
		}
	}
	return 0;
}
