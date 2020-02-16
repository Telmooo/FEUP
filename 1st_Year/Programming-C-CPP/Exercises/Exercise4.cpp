/**
 * @file Exercise4.cpp
 *
 * @brief Source Code for exercise 4
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#include "Exercise4.hpp"
#include <iostream>
#include <cstring>
#include <limits>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <fstream>

 /**
  * Runs exercise 4: Arrays | Vectors | Strings | Structs | Files
  * Allows user to choose which exercise to run from the fourth exercise
  *
  * @brief execute exercise 4
  */
void runExercise4(void) {
	int choice = 0;
	while (true) {
		std::cout << "\nEnter a number between 1-12 to run exercises (Exercise 8 & 9 have same key)\nEnter 0 to exit\n";
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
			runChem();
			break;
		case 2:
			runSeqSearch();
			break;
		case 3:
			runDecomposition();
			break;
		case 4:
			runNormName();
			break;
		case 5:
			runStructFraction();
			break;
		case 6:
			runArrays();
			break;
		case 7:
			runVectors();
			break;
		case 8:
			runAlgorithms();
			break;
		case 9:
			runRemDup();
			break;
		case 10:
			runVectUniInter();
			break;
		case 11:
			runOps();
			break;
		case 12:
			runFiles();
			break;
		default:
			std::cout << "Invalid number\n";
			break;
		}
	}
}

/**
 * User can input a chemical and outputs whether the chemical is a hydroxide or not
 *
 * @brief execute hydroxide checker for chemicals
 */
void runChem(void) {
	/* 4.1 */
	int mode = 0;
	std::cout << "\nExercise 4.1\n";
	std::cout << "Checking for hydroxides\nEnter mode:\n0 for C style\n1 for C++ style\n";
	std::cout << "Enter the mode: ";
	std::cin >> mode;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		mode = -1;
	}

	switch (mode) {
	case 0:
	{
		char chemical[36]; // longest chemical length possible
		std::cout << "Enter the chemical: ";
		std::cin >> chemical;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << isHydroxide(chemical);
		break;
	}
	case 1:
	{
		std::string chemical;
		std::cout << "Enter the chemical: ";
		std::cin >> chemical;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << chemical << (isHydroxide(chemical) ? " is " : " is not ") << "a hydroxide\n";
		break;
	}
	default:
		std::cout << "Invalid input\n";
		return;
	}
}

/**
 * Checks if chemical is a hydroxide
 * Input as C String
 *
 * @brief checks if chemical is a hydroxide
 * @param compound chemical
 * @return 1 if chemical is a hydroxide, otherwise 0
 */
bool isHydroxide(char compound[]) {
	return strstr(compound, "OH") != NULL;
}

/**
 * Checks if chemical is a hydroxide
 * Input as C++ String
 *
 * @overload bool isHydroxide(std::string compound)
 */
bool isHydroxide(std::string compound) {
	return compound.rfind("OH") != std::string::npos;
}

/**
 * User inputs text and searches for sequences of a character
 *
 * @brief executes searcher for sequences in string
 */
void runSeqSearch(void) {
	/* 4.2 */
	std::string str;
	char c;
	int consecutive;
	std::cout << "\nExercise 4.2\n";
	std::cout << "Enter some text: ";
	std::cin >> str;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Enter the character you want to find: ";
	std::cin >> c;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "How many consecutive character must have: ";
	std::cin >> consecutive;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	std::cout << "Found ? " << (sequenceSearch(str, consecutive, c) ? "Yes" : "No");
}

/**
 * Search for a sequence of N consecutive of a character
 * Short-cut implementation (exits on first occurrence of the sequence)
 *
 * @brief search for consecutive sequence of character
 * @param str text to search
 * @param nc number of consecutive characters of the sequence
 * @param c character to search in text
 * @return 1 if sequence found, otherwise 0
 */
bool sequenceSearch(std::string str, int nc, char c) {
	unsigned int counter = 0;
	for (size_t i = 0; i < str.length(); i++) {
		(str.at(i) == c) ? counter++ : counter = 0;
		if (counter == nc)
			return true;
	}
	return false;
}

/**
 * Takes a chemical given by the user and outputs its components
 * Separating each atom that composes the chemical
 *
 * @brief separate chemical into atoms
 */
void runDecomposition(void) {
	/* 4.3 */
	std::string chemical;
	std::cout << "\nExercise 4.3\n";
	std::cout << "Enter a chemical to decompose: ";
	std::cin >> chemical;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		return;
	}
	decompose(chemical);
}

/**
 * Takes a chemical decomposing it into atoms
 * Chemical must be a valid chemical, unexpected behaviour on non-valid chemicals
 *
 * @brief outputs all atoms that compose the chemical
 * @param compound chemical to decompose
 */
void decompose(std::string compound) {
	if (compound.empty())
		return;

	std::string elements = "", atom = "";
	char c;
	for (char &c : compound) {
		if (std::isupper(c)) {
			if (atom.empty())
				atom += c;
			else if (elements.empty()) {
				elements += atom;
				atom = std::string(1, c);
			} else if (elements.find(atom) == std::string::npos) {
				elements += " " + atom;
				atom = std::string(1, c);
			}

		} else if (std::islower(c) && !atom.empty())
			atom += std::string(1, c);
	}
	if (elements.empty() && !atom.empty())
		elements += atom;
	else if (elements.find(atom) == std::string::npos)
		elements += " " + atom;

	std::cout << "The elements of " << compound << ": " << elements << "\n";
}

/**
 * User inputs name and outputs the normalised name
 * Normalise name: One space between names (every name capitalised)
 *
 * @brief normalises name
 */
void runNormName(void) {
	/* 4.4 */
	std::string name;
	std::cout << "\nExercise 4.4\n";
	std::cout << "Enter your name: ";
	std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
	std::getline(std::cin, name);

	std::string normalized = normalizeName(name);

	std::cout << "Normalised name: " << normalized << "\n";
}

/**
 * Normalises name, deleting all repeated white spaces and capitalising the names
 *
 * @param name name to normalise
 * @return normalised name
 */
std::string normalizeName(std::string name) {
	const std::string PARTICLES[] = { "DE", "DO", "DA", "DAS", "DOS", "E" };
	std::string normName = "", aux = "";
	char c;
	bool skip = false;
	for (size_t i = 0; i < name.length(); i++) {
		c = name.at(i);
		if (aux.empty() && (c == ' ' || c == '\n' || c == '\t'))
			continue;

		if (c == ' ' || c == '\n' || c == '\t') {
		label:
			if (aux.empty() || arrayContains(PARTICLES, 6, aux))
				aux = "";
			else if (normName.empty())
				normName += aux;
			else
				normName += " " + aux;
			aux = "";
			continue;
		}

		aux.push_back(toupper(c));
		if (i == name.length() - 1)
			goto label;
	}
	return normName;
}

/**
 * Checks if a value is in the array
 *
 * @brief checks if value is in the array
 * @param arr array to check for value
 * @param arrLength length of the array
 * @param element value to search for
 * @return 1 if value is found, otherwise 0
 */
bool arrayContains(const std::string arr[], int arrLength, const std::string element) {
	for (int i = 0; i < arrLength; i++)
		if (arr[i].compare(element) == 0)
			return true;

	return false;
}

/**
 * Allows user to input fractions and execute simple operations with fractions
 *
 * @brief executes fraction reader and operator
 */
void runStructFraction(void) {
	/* 4.5 */
	int choice = 0;
	std::cout << "\nExercise 4.5\n";
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
			std::cout << "Reading fraction, numerator and denominator must be both integers\n";
			std::cout << "Enter a fraction (numerator / denominator ): ";
			Fraction fracc = readFraction();
			std::cout << "Fraction entered: ";
			writeFraction(fracc);
			fracc = reduceFraction(fracc);
			std::cout << "The reduced fraction is: ";
			writeFraction(fracc);
			break;
		case 2:
			Fraction fracc1, fracc2;
			char op;
			std::cout << "Arithmetic operations with fraction, numerator and denominator must be both integers\n";
			std::cout << "Valid operators: +, -, *, /\n";
			std::cout << "Enter an operation (numerator1 / denominator1 <operator> numerator2 / denominator2): ";
			fracc1 = readFraction();
			std::cin >> op;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
				op = 'I'; // invalid operator
			}
			fracc2 = readFraction();
			Fraction result;
			switch (op) {
			case '+':
				result = arithmeticFraction(fracc1, 0, fracc2);
				break;
			case '-':
				result = arithmeticFraction(fracc1, 1, fracc2);
				break;
			case '*':
				result = arithmeticFraction(fracc1, 2, fracc2);
				break;
			case '/':
				result = arithmeticFraction(fracc1, 3, fracc2);
				break;
			default:
				std::cout << "Invalid operator\n";
				continue;
			}
			std::cout << "The result is: ";
			writeFraction(result);
			break;
		default:
			std::cout << "Invalid mode\n";
			break;
		}
	}
}

/**
 * Reads fraction from user
 * If user inputs invalid fraction, returns an undefined fraction (0 / 0)
 *
 * @brief reads fraction from user
 * @return fraction evaluated from input
 * @see Fraction
 */
Fraction readFraction(void) {
	char sep;
	Fraction fracc;
	std::cin >> fracc.numerator >> sep >> fracc.denominator;
	if (std::cin.fail() || sep != '/') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		fracc.numerator = 0;
		fracc.denominator = 0;
	}
	return fracc;
}

/** Writes fraction into console following the format
 * {numerator} / {denominator}
 *
 * @brief outputs fraction
 * @param fracc fraction to write
 * @see Fraction
 */
void writeFraction(const Fraction &fracc) {
	if (fracc.numerator == 0 && fracc.denominator == 0) {
		std::cout << "undefined\n";
	} else if (fracc.denominator == 0) {
		std::cout << ((fracc.numerator > 0) ? "" : "-") << "infinity\n";
	} else {
		std::cout << fracc.numerator << "/" << fracc.denominator << "\n";
	}
}

/**
 * Creates a new fraction resulted from reducing to the smallest terms
 * the fraction passed to the function
 *
 * @brief reduces fraction to smallest terms
 * @param fracc fraction to reduce
 * @return fraction derived from fracc (fracc reduced to the lowest terms)
 * @see Fraction
 */
Fraction reduceFraction(const Fraction &fracc) {
	int div = gcd2(fracc.numerator, fracc.denominator);
	Fraction reduced;
	if (div == 0) {
		reduced.numerator = fracc.numerator;
		reduced.denominator = fracc.numerator;
	} else {
		reduced.numerator = fracc.numerator / div;
		reduced.denominator = fracc.denominator / div;
	}

	if (reduced.denominator < 0) {
		reduced.numerator = -reduced.numerator;
		reduced.denominator = -reduced.denominator;
	}

	return reduced;
}

/**
 * Executes simple operations between two fractions
 * Operations allowed are sums, differences, multiplication and division of fractions
 *
 * @brief executes operation between fractions
 * @param first fraction
 * @param op specifier to which operation to execute (0-> sum; 1-> subtraction; 2-> multiplication; 3-> division)
 * @param second fraction
 * @return fraction result of the operation
 * @see Fraction
 */
Fraction arithmeticFraction(const Fraction &fracc1, int op, const Fraction &fracc2) {
	Fraction result;

	switch (op) {
	case 0: // sum
		if (fracc1.denominator == fracc2.denominator) {
			if (fracc1.denominator == 0) {
				result.numerator = 0;
				result.denominator = 0;
			} else {
				result.numerator = fracc1.numerator + fracc2.numerator;
				result.denominator = fracc1.denominator;
				result = reduceFraction(result);
			}
		} else {
			if (fracc1.denominator == 0) {
				result.numerator = fracc1.numerator;
				result.denominator = fracc1.denominator;
			} else if (fracc2.denominator == 0) {
				result.numerator = fracc2.numerator;
				result.denominator = fracc2.denominator;
			} else {
				result.numerator = fracc1.numerator * fracc2.denominator
					+ fracc2.numerator * fracc1.denominator;
				result.denominator = fracc1.denominator * fracc2.denominator;
				result = reduceFraction(result);
			}
		}
		break;
	case 1: // subtraction
		if (fracc1.denominator == fracc2.denominator) {
			if (fracc1.denominator == 0) { // generate undefined result
				result.numerator = 0;
				result.denominator = 0;
			} else {
				result.numerator = fracc1.numerator - fracc2.numerator;
				result.denominator = fracc1.denominator;
				result = reduceFraction(result);
			}
		} else {
			if (fracc1.denominator == 0) {
				result.numerator = fracc1.numerator;
				result.denominator = fracc1.denominator;
			} else if (fracc2.denominator == 0) {
				result.numerator = -fracc2.numerator;
				result.denominator = fracc2.denominator;
			} else {
				result.numerator = fracc1.numerator * fracc2.denominator
					- fracc2.numerator * fracc1.denominator;
				result.denominator = fracc1.denominator * fracc2.denominator;
				result = reduceFraction(result);
			}
		}
		break;
	case 2: // multiplication
		result.numerator = fracc1.numerator * fracc2.numerator;
		result.denominator = fracc1.denominator * fracc2.denominator;
		result = reduceFraction(result);
		break;
	case 3: // division
		result.numerator = fracc1.numerator * fracc2.denominator;
		result.denominator = fracc1.denominator * fracc2.numerator;
		result = reduceFraction(result);
		break;
	}
	return result;
}

/**
 * Calculates the greatest common divisor using euclidean algorithm (iterative)
 *
 * @brief calculates greatest common divisor
 * @param a first number
 * @param b second number
 * @return value of the greatest common divisor
 */
int gcd2(int a, int b) {
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
 * Allows user to input arrays, search for elements in arrays
 * All values entered must be whole numbers (integers)
 *
 * @brief executes function related to arrays
 */
void runArrays(void) {
	/* 4.6 */
	std::cout << "\nExercise 4.6\n";
	int size = 0;
	std::cout << "Reading an array of integers\nEnter the number of elements of the array: ";
	std::cin >> size;
	if (std::cin.fail() || size <= 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}
	int *arr = new int[size];
	readIntArray(arr, size);
	int mode = -1;
	std::cout << "Array built successfully\nModes available:\n";
	std::cout << "0 for searching value\n1 for searching multiple values\n";
	std::cin >> mode;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		mode = -1;
	}

	int value = 0, found;
	int *indexes = new int[size];
	switch (mode) {
	case 0:
		std::cout << "Enter a value to search: ";
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			value = 0;
		}

		found = searchValueInIntArray(arr, size, value);
		if (found == -1)
			std::cout << "Value " << value << " was not found in the array\n";
		else
			std::cout << "Value " << value << " found at position " << found << " of the array\n";
		break;
	case 1:
		std::cout << "Enter a value to search: ";
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			value = 0;
		}

		found = searchValueInIntArray(arr, size, value, indexes);
		if (found == 0)
			std::cout << "Value " << value << " was not found in the array\n";
		else {
			std::cout << "Value " << value << " was found at the positions:";
			for (int i = 0; i < found; i++)
				std::cout << " " << i;
			std::cout << " in the array\n";
		}
		break;
	default:
		std::cout << "Invalid input\n";
		break;
	}

	delete[] arr;
	delete[] indexes;
}

/**
 * Reads from user an array of integers of nElem number of elements
 *
 * @brief reads array of specified size from user
 * @param arr [out] deposit for the array
 * @param nElem [in] size of the array
 */
void readIntArray(int arr[], int nElem) {

	int index = 0, elem;

	while (index < nElem) {

		std::cout << "Write element index " << index << ": ";
		std::cin >> elem;

		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid integer\nWrite element index " << index << ": ";
			std::cin >> elem;
		}
		*(arr + index) = elem;
		index++;
	}
}

/**
 * Checks if a value is in the array, returning the index if found
 * (Short-cut implementation (returns on the first occurrence))
 *
 * @brief searches for value in array
 * @param arr array of integers
 * @param nElem size of the array
 * @param value integer to search for
 * @return index of element if found, else -1
 */
int searchValueInIntArray(const int arr[], int nElem, int value) {
	for (int i = 0; i < nElem; i++)
		if (*(arr + i) == value)
			return i;

	return -1;
}

/**
 * Searches for value in the array, returning all the positions where it occurs, if any
 *
 * @overload int searchValueInIntArray(const int arr[], int nElem, int value, int index[])
 * @param index [out] indexes of the occurrences of the value if any
 * @return 1 if any found, else 0
 */
int searchValueInIntArray(const int arr[], int nElem, int value, int index[]) {
	int counter = 0;
	for (int i = 0; i < nElem; i++) {
		if (*(arr + i) == value) {
			*(index + counter) = i;
			counter++;
		}
	}
	return counter;
}

/**
 * Reads from user an vector of integers
 *
 * @brief reads vector of specified size from user
 */
void runVectors(void) {
	/* 4.7 */
	std::cout << "\nExercise 4.7\n";
	int mode = -1;
	std::cout << "Reading a vector of integers\nChoose a mode\n";
	std::cout << "Enter 0 for reading N elements\nEnter 1 to read till CTRL-Z: ";
	std::cin >> mode;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	size_t size = 0;
	std::vector<int> v;
	switch (mode) {
	case 0:
		std::cout << "Enter the size of the vector: ";
		std::cin >> size;
		if (std::cin.fail() || size <= 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid input\n";
			return;
		}

		v = readIntVector(size);
		break;
	case 1:
		std::cout << "Starting the vector writing\n";
		v = readIntVector();
		size = v.size();
		break;
	default:
		std::cout << "Invalid input\n";
		return;
	}

	mode = -1;
	std::cout << "Vector built sucessfully\nModes available:\n";
	std::cout << "0 for searching value\n1 for searching multiple values\n";
	std::cin >> mode;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		mode = -1;
	}

	int value = 0;
	size_t found;
	std::vector<int> indexes;
	switch (mode) {
	case 0:
		std::cout << "Enter a value to search: ";
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			value = 0;
		}

		found = searchValueInVector(v, value);
		if (found == -1)
			std::cout << "Value " << value << " was not found in the array\n";
		else
			std::cout << "Value " << value << " found at position " << found << " of the array\n";
		break;
	case 1:
		std::cout << "Enter a value to search: ";
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			value = 0;
		}

		indexes = searchMultValuesInVector(v, value);
		if (indexes.size() == 0)
			std::cout << "Value " << value << " was not found in the array\n";
		else {
			std::cout << "Value " << value << " was found at the positions:";
			for (int i = 0; i < indexes.size(); i++)
				std::cout << " " << i;
			std::cout << " in the array\n";
		}
		break;
	default:
		std::cout << "Invalid input\n";
		break;
	}
}

/**
 * Reads from user a vector of integers with specified size
 *
 * @brief reads array of specified size from user
 * @param nElem size of the vector
 */
std::vector<int> readIntVector(size_t nElem) {

	size_t index = 0;
	int elem;
	std::vector<int> vect;

	while (vect.size() < nElem) {

		std::cout << "Write element index " << index << ": ";
		std::cin >> elem;

		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			std::cout << "Invalid integer\nWrite element index " << index << ": ";
			std::cin >> elem;
		}
		vect.push_back(elem);
		index++;
	}
	return vect;
}

/**
 * Checks if a value is in the vector, returning the index if found
 * (Short-cut implementation (returns on the first occurrence))
 *
 * @brief searches for value in vector
 * @param vect vector of integers
 * @param value integer to search for
 * @return index of element if found, else -1
 */
size_t searchValueInVector(const std::vector<int> &vect, int value) {
	for (size_t i = 0; i < vect.size(); i++)
		if (vect.at(i) == value)
			return i;

	return -1;
}

/**
 * Searches for value in the vector, returning all the positions where it occurs, if any
 *
 * @brief searches for value in vector
 * @param vect vector of integers
 * @param value integer to search for
 * @return vector containing the indexes of the occurrences (empty vector if not found any)
 */
std::vector<int> searchMultValuesInVector(const std::vector<int> &vect, int value) {
	std::vector<int> index;
	for (size_t i = 0; i < vect.size(); i++)
		if (vect.at(i) == value)
			index.push_back((int)i);

	return index;
}

/**
 * Reads from user a vector of integers
 * Size is not specified, vector is finished when CTRL-Z is entered
 *
 * @overload std::vector<int> readIntVector()
 */
std::vector<int> readIntVector(void) {

	std::vector<int> vect;
	int elem;
	size_t index = 0;
	while (true) {

		std::cout << "Write element index " << index << " (CTRL-Z to finish): ";
		std::cin >> elem;

		if (std::cin.fail()) {

			if (std::cin.eof()) {
				std::cin.clear();
				std::cout << "Array finished\n";
				return vect;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			continue;
		}
		vect.push_back(elem);
		index++;
	}
	return vect;
}

/**
 * Reads from user a vector of integers
 * Size is not specified, vector is finished when CTRL-Z is entered
 *
 * @param MAX_STRING_SIZE Maximum character per string
 * @return vector user entered
 */
std::vector<std::string> readStringVector(const size_t MAX_STRING_SIZE) {

	std::vector < std::string > vect;
	std::string elem;
	size_t index = 0;
	while (true) {

		std::cout << "Write element index " << index << " (CTRL-Z to finish): ";
		std::cin.ignore(MAX_STRING_SIZE, '\n');
		std::getline(std::cin, elem, '\n');

		if (std::cin.fail()) {

			if (std::cin.eof()) {
				std::cout << "Array finished\n";
				std::cin.clear();
				return vect;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			continue;
		}

		if (elem.size() > MAX_STRING_SIZE)
			elem = elem.substr(0, MAX_STRING_SIZE);
		vect.push_back(elem);
		index++;
	}
	return vect;
}

/**
 * Allows user to execute algorithms on vectors
 * Algorithms: Bubble Sort, Quick Sort, Binary Search
 *
 * @brief executes function related to algorithms
 */
void runAlgorithms(void) {
	/* 4.8 & 4.9 */
	std::cout << "\nExercise 4.8 & 4.9\n";
	std::cout << "Reading a vector of strings (strings up to 50 characters) (CTRL-Z to finish)\n";
	std::vector < std::string > v;
	const size_t MAX_STRING_SIZE = 50;
	v = readStringVector(MAX_STRING_SIZE);
	int mode = 0;
	std::string value;

	while (true) {
		std::cout
			<< "Enter a mode:\n0 for exit\n1 for shuffling the vector\n2 for sorting via BubbleSort\n3 for sorting via QuickSort\n4 for searching value via BinarySearch(requires sorting first)\n";
		std::cout << "Enter the mode: ";
		std::cin >> mode;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			mode = -1;
		}
		switch (mode) {
		case 0:
			std::cout << "Exiting...\n";
			return;
		case 1:
			std::cout << "Shuffling...\n";
			shuffle(v);
			std::cout << "Done\n";
			break;
		case 2:
			std::cout << "Bubble Sort: Sorting...\n";
			bubbleSort(v);
			std::cout << "Done\n";
			break;
		case 3:
			std::cout << "Quick Sort: Sorting...\n";
			quickSort(v, 0, v.size() - 1);
			std::cout << "Done\n";
			break;
		case 4:
			std::cout << "Binary Search\nWhat string you want to search for: ";
			std::cin >> value;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
				std::cout << "Invalid input\n";
				break;
			}

			if (value.size() > MAX_STRING_SIZE)
				value = value.substr(0, MAX_STRING_SIZE);

			binarySearch(v, value);
			std::cout << "Done\n";
			break;
		default:
			std::cout << "Invalid input\n";
			break;
		}
	}
}

/**
 * Sorts a vector of strings in ascending order
 * Class: Sorting Algorithm
 * Comparison sorting algorithm
 * Array Accesses: Yes
 * Writes: Yes
 * Comparisons: Yes
 * Stable: Yes
 * Best-Case Performance: O(n) comparisons, O(1) swaps
 * Worst-Case Performance: O(n²) comparisons, O(n²) swaps
 * Average Performance: O(n²) comparisons, O(n²) swaps
 * Worst-Case Space Complexity: O(1) auxiliary
 *
 * @brief sorts vector in ascending order
 * @param v [in] [out] vector of strings to sort
 */
void bubbleSort(std::vector<std::string> &v) {

	bool changes;
	size_t n = v.size();

	do {
		changes = false;
		n--;

		for (size_t i = 0; i < n; i++) {
			if (v.at(i).compare(v.at(i + 1)) == 1) {
				swap(v, i, i + 1);
				changes = true;
			}
		}
	} while (changes);
}

/**
 * Sorts a vector of strings in ascending order
 *
 * @overload void bubbleSort(std::vector<int> &v)
 */
void bubbleSort(std::vector<int> &v) {

	bool changes;
	size_t n = v.size();

	do {
		changes = false;
		n--;

		for (size_t i = 0; i < n; i++) {
			if (v.at(i) > v.at(i + 1)) {
				swap(v, i, i + 1);
				changes = true;
			}
		}
	} while (changes);
}

/**
 * Sorts an vector of strings in ascending order
 * Class: Sorting Algorithm
 * Comparison sorting algorithm
 * Array Accesses: Yes
 * Writes: Yes
 * Comparisons: Yes
 * Stable: No
 * Best-Case Performance: O(n log(n))
 * Worst-Case Performance: O(n²)
 * Average Performance: O(n log(n))
 * Worst-Case Space Complexity: O(n)
 *
 * @param v [in] [out] vector of strings to sort
 * @param start position where sorting starts
 * @param end position where sorting stops
 */
void quickSort(std::vector<std::string> &v, size_t start, size_t end) {
	if (start < end) {
		size_t pivot = partition(v, start, end);
		quickSort(v, start, pivot);
		quickSort(v, pivot + 1, end);
	}
}

/**
 * Sorts an vector of strings in ascending order
 *
 * @overload void quickSort(std::vector<int> &v, size_t start, size_t end)
 */
void quickSort(std::vector<int> &v, size_t start, size_t end) {
	if (start < end) {
		size_t pivot = partition(v, start, end);
		quickSort(v, start, pivot);
		quickSort(v, pivot + 1, end);
	}
}

/**
 * Creates two partitions, rightmost has the small values, rightmost high values
 * Pivot is chosen randomly
 *
 * @brief splits interval into two partitions
 * @param v vector of strings
 * @param start start position of the interval to split
 * @param end stop position of the interval to split
 * @return the index of the separator of partitions
 */
size_t partition(std::vector<std::string> &v, size_t start, size_t end) {

	size_t pivotIndex = (int)(start + ((double)rand() / RAND_MAX) * (end + 1 - start));
	std::string pivot = v.at(pivotIndex);
	size_t i = start - 1;
	size_t j = end + 1;

	while (true) {

		i++;
		while (i < end && v.at(i).compare(pivot) == -1)
			i++;

		j--;
		while (j > start && v.at(j).compare(pivot) == 1)
			j--;

		if (i < j)
			swap(v, i, j);
		else
			return j;
	}
}

/**
 * Creates two partitions, rightmost has the small values, rightmost high values
 * Pivot is chosen randomly
 *
 * @overload size_t partition(std::vector<int> &v, size_t start, size_t end)
 */
size_t partition(std::vector<int> &v, size_t start, size_t end) {

	size_t pivotIndex = (int)(start + ((double)rand() / RAND_MAX) * (end + 1 - start));
	int pivot = v.at(pivotIndex);
	size_t i = start - 1;
	size_t j = end + 1;

	while (true) {

		i++;
		while (i < end && v.at(i) < pivot)
			i++;

		j--;
		while (j > start && v.at(j) > pivot)
			j--;

		if (i < j)
			swap(v, i, j);
		else
			return j;
	}
}

/**
 * Swaps two elements on the vector
 *
 * @brief swaps elements on the vector
 * @param v [in] [out] vector of integers
 * @param i first position of element to swap
 * @param j second position of element to swap
 */
void swap(std::vector<int> &v, size_t i, size_t j) {
	int aux = v.at(i);
	v.at(i) = v.at(j);
	v.at(j) = aux;
}

/**
 * Swaps two elements on the vector
 *
 * @overload void swap(std::vector<std::string> &v, size_t i, size_t j)
 */
void swap(std::vector<std::string> &v, size_t i, size_t j) {
	std::string aux = v.at(i);
	v.at(i) = v.at(j);
	v.at(j) = aux;
}

/**
 * Randomises the order of the elements of a vector randomly
 *
 * @brief shuffles the vector
 * @param v [in] [out] vector of string to shuffle
 */
void shuffle(std::vector<std::string> &v) {
	for (size_t i = 0; i < v.size(); i++)
		swap(v, i, rand() % v.size());
}

/**
 * Randomises the order of the elements of a vector randomly
 *
 * @overload void shuffle(std::vector<int> &v)
 */
void shuffle(std::vector<int> &v) {
	for (size_t i = 0; i < v.size(); i++)
		swap(v, i, rand() % v.size());
}

/**
 * Searches for value using Binary Search
 * Returns position of value if found else -1
 * Vector must be sorted, unexpected behaviour if not sorted
 *
 * @brief searches for value in vector
 * @param v vector of strings
 * @param value string to search for
 */
size_t binarySearch(const std::vector<std::string> &v, std::string value) {

	size_t i = 0;
	size_t j = v.size() - 1;
	size_t k;
	std::string aux;

	while (i <= j) {
		k = (i + j) / 2;
		aux = v.at(k);
		if (aux.compare(value) == 1)
			j = k - 1;
		else if (aux.compare(value) == -1)
			i = k + 1;
		else
			return k;
	}
	return -1;
}

/**
 * User inputs a vector of integers and removes duplicated elements from the vector
 * Order of elements is maintained
 *
 * @brief removes duplicates elements from vector user entered
 * @see readIntVector()
 */
void runRemDup(void) {
	/* 4.10 */
	std::cout << "\nExercise 4.10\n";
	std::cout << "Removing duplicates from a vector of integers\nEnter a vector of integers (CTRL-Z to finish vector): ";
	std::vector<int> v;
	v = readIntVector();
	if (v.size() == 0) {
		std::cout << "Empty vector\n";
		return;
	}

	std::cout << "The vector you entered:";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << " " << v.at(i);
	std::cout << "\n";
	removeDuplicates(v);
	std::cout << "The vector without duplicates: ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << " " << v.at(i);
	std::cout << "\n";
}

/**
 * Removes duplicates from vector, maintaining order
 *
 * @brief removes duplicates from vector
 * @param v [in] [out] vector of integers
 */
void removeDuplicates(std::vector<int> &v) {
	std::vector<int> seen;
	int aux;
	for (size_t i = 0; i < v.size(); i++) {
		aux = v.at(i);
		if (duplicated(seen, aux)) {
			v.erase(v.begin() + i);
			i--;
		} else {
			seen.push_back(aux);
		}
	}
}

/**
 * Checks if value is already in the vector (is duplicated)
 * Vector v is a vector containing all the values already seen
 *
 * @param v vector of integers containing all seen elements from other vector
 * @param value integer to check if duplicated
 * @return 1 if duplicated, else 0
 */
bool duplicated(const std::vector<int> &v, int value) {
	for (size_t i = 0; i < v.size(); i++)
		if (value == v.at(i))
			return true;

	return false;
}

/**
 * User inputs two vectors and outputs the intersection and the union of the vectors
 *
 * @brief executes function that creates intersection/union of vectors
 */
void runVectUniInter(void) {
	/* 4.11 */
	std::cout << "\nExercise 4.11\n";
	std::cout << "Reading two vectors of integers (CTRL-Z to finish vector)\n";
	std::vector<int> v1, v2;
	std::cout << "Reading first vector: ";
	v1 = readIntVector();
	std::cout << "Reading second vector: ";
	v2 = readIntVector();

	if (v1.size() == 0 || v2.size() == 0) {
		std::cout << "Invalid vectors\n";
		return;
	}

	std::vector<int> uni, inter;
	uni = vectorUnion(v1, v2);
	inter = vectorIntersection(v1, v2);

	std::cout << "The vectors you entered are:\nVector 1:";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << " " << v1.at(i);
	std::cout << "\nVector 2:";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << " " << v2.at(i);
	std::cout << "\nThe union of those vectors is:\nUnion:";
	for (size_t i = 0; i < uni.size(); i++)
		std::cout << " " << uni.at(i);
	std::cout << "\nThe intersection of those vectors is:\nIntersection:";
	if (inter.size() == 0)
		std::cout << " NULL";
	else
		for (size_t i = 0; i < inter.size(); i++)
			std::cout << " " << inter.at(i);
	std::cout << "\n";
}

/**
 * Removes duplicated values from vector
 * Vector must be sorted, undefined behaviour if not sorted
 *
 * @brief remove duplicates from vector
 * @param v [in] [out]
 */
void removeAdjacents(std::vector<int> &v) {
	for (size_t i = 0; i < v.size(); i++)
		if (i != 0 && v.at(i) == v.at(i - 1))
			v.erase(v.begin() + i--);
}

/**
 * Makes a copy of vector
 *
 * @brief copies vector
 * @param v vector of integers to copy
 * @return copy of vector v
 */
std::vector<int> copyVector(const std::vector<int> &v) {
	std::vector<int> copy;
	for (size_t i = 0; i < v.size(); i++)
		copy.push_back(v.at(i));

	return copy;
}

/**
 * Creates the unique vector result of the union of two vectors
 * Vector contains all elements from both vectors (common and non-common)
 *
 * @brief union of two vectors
 * @param v1 first vector
 * @param v2 second vector
 * @return vector derived by the union of v1 and v2
 */
std::vector<int> vectorUnion(const std::vector<int> &v1, const std::vector<int> &v2) {
	std::vector<int> uVector = copyVector(v1);
	std::vector<int> aux = copyVector(v2);
	quickSort(uVector, 0, uVector.size() - 1);
	quickSort(aux, 0, aux.size() - 1);
	removeAdjacents(uVector);
	removeAdjacents(aux);
	size_t i = 0, j = 0;
	int temp;
	// merging vectors
	while (j < aux.size()) {
		temp = aux.at(j);

		while (i < uVector.size() && uVector.at(i) < temp)
			i++;

		if (i >= uVector.size() || temp != uVector.at(i)) {
			if (i < uVector.size())
				uVector.insert(uVector.begin() + i, temp);
			else
				uVector.push_back(temp);
		}
		j++;
	}
	return uVector;
}

/**
 * Creates the unique vector result of the intersection of two vectors
 * Vector contains common elements between two vectors
 *
 * @brief intersection of two vectors
 * @param v1 first vector
 * @param v2 second vector
 * @return vector derived by the intersection of v1 and v2
 */
std::vector<int> vectorIntersection(const std::vector<int> &v1, const std::vector<int> &v2) {
	std::vector<int> copy1 = copyVector(v1);
	std::vector<int> copy2 = copyVector(v2);
	quickSort(copy1, 0, copy1.size() - 1);
	quickSort(copy2, 0, copy2.size() - 1);
	removeAdjacents(copy1);
	removeAdjacents(copy2);
	size_t i = 0, j = 0;
	std::vector<int> intersection;
	int aux1, aux2;

	while (i < copy1.size() && j < copy2.size()) {
		aux1 = copy1.at(i);
		aux2 = copy2.at(j);

		if (aux1 == aux2) {
			i++;
			j++;
			intersection.push_back(aux1);
			continue;
		}

		if (aux1 > aux2) {
			j++;
			while (j < copy2.size() && aux1 > copy2.at(j))
				j++;
		} else {
			i++;
			while (i < copy1.size() && aux2 > copy1.at(i))
				i++;
		}
	}
	return intersection;
}

/**
 * Allow user to input basic math operations
 * Operations: Sum, Subtraction, Multiplication, Division
 * Respects rules of precedence (PEMDAS/BODMAS)
 *
 * @brief basic operation parser
 */
void runOps(void) {
	/* 4.12 */
	std::cout << "\nExercise 4.12\n";
	std::cout << "Executing an operation\nEnter your operation (only +, -, *, / available): ";
	std::string op;
	std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
	std::getline(std::cin, op, '\n');
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}
	double result = executeOperation(op);
	std::cout << "The result of " << op << " is " << result << "\n";
}


/**
 * Parses the operation and calculates the result
 * If invalid operation is evaluated as 0
 *
 * @brief parses operation
 * @param op string containing operation
 * @return result of the operation
 */
double executeOperation(std::string operation) {
	operation.erase(std::remove_if(operation.begin(), operation.end(), std::isspace), operation.end());

	std::vector<std::string> ops;
	bool control = true;
	size_t start, end;

	while (control) {

		start = operation.find_first_of("({[");
		end = operation.find_last_of(")}]");

		if (start == std::string::npos || end == std::string::npos) {
			if (start != end) // invalid operation
				return 0;

			control = false;
			ops.push_back(operation);
		} else {
			ops.push_back(operation.substr(0, start) + "x" + operation.substr(end + 1));
			operation = operation.substr(start + 1, end - start - 1);
		}
	}

	double result = 0, x = 0, y = 0;
	char op;
	std::stringstream ss;
	size_t pivot;

	for (size_t i = ops.size() - 1; i < ops.size(); i--) {

		pivot = ops.at(i).find_first_of("*/");
		while (pivot != std::string::npos) {
			start = ops.at(i).find_last_of("+-*/", pivot - 1);
			end = ops.at(i).find_first_of("+-*/", pivot + 1);

			if (start == std::string::npos)
				start = 0;
			else
				start++;
			if (end == std::string::npos)
				end = ops.at(i).size();

			ss << ops.at(i).substr(start, end - start);
			ss >> x >> op >> y;
			if (ss.fail())
				return 0;

			switch (op) {
			case '*':
				result = x * y;
				break;
			case '/':
				result = x / y;
				break;
			default:
				return 0;
			}

			ops.at(i).replace(start, end - start, std::to_string(result));
			std::stringstream().swap(ss);
			pivot = ops.at(i).find_first_of("*/");
		}

		pivot = ops.at(i).find_first_of("+-");
		while (pivot != std::string::npos) {

			if (pivot == 0) {
				start = 0;
				switch (ops.at(i).at(pivot)) {
				case '+':
					ops.at(i) = ops.at(i).substr(1);
					break;
				case '-':
					end = ops.at(i).find_first_of("+-", pivot + 1);
					if (end == std::string::npos)
						end = ops.at(i).size();

					std::cout << ops.at(i).substr(start, end - start) << "\n";
					ss << ops.at(i).substr(start, end - start);
					ss >> x >> op >> y;
					if (ss.fail())
						return 0;

					switch (op) {
					case '+':
						result = x + y;
						break;
					case '-':
						result = x - y;
						break;
					default:
						return 0;
					}
					break;
				default:
					return 0;
				}
			} else {

				start = ops.at(i).find_last_of("+-", pivot - 1);
				end = ops.at(i).find_first_of("+-", pivot + 1);

				if (start == std::string::npos)
					start = 0;
				else
					start++;
				if (end == std::string::npos)
					end = ops.at(i).size();

				ss << ops.at(i).substr(start, end - start);
				ss >> x >> op >> y;
				if (ss.fail())
					return 0;

				switch (op) {
				case '+':
					result = x + y;
					break;
				case '-':
					result = x - y;
					break;
				default:
					return 0;
				}
			}

			ops.at(i).replace(start, end - start, std::to_string(result));
			std::stringstream().swap(ss);
			pivot = ops.at(i).find_first_of("+-");
		}

		if (i == 0) {
			try {
				result = std::stod(ops.at(i));
			} catch (std::invalid_argument e) {
				return 0;
			} catch (std::out_of_range e) {
				return 0;
			}
		} else {
			ops.at(i - 1).replace(ops.at(i - 1).find('x'), 1, std::to_string(result));
		}
	}
	return result;
}

/**
 * Allows user to input a file to sort it
 * Sorted files doesn't override original file
 *
 * @brief sorts file given by user
 */
void runFiles(void) {
	/* 4.13 */
	std::cout << "\nExercise 4.13\n";
	std::cout << "Sorting file\nEnter the filename(or path to file): ";
	std::string path;
	std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
	std::getline(std::cin, path, '\n');
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "Invalid input\n";
		return;
	}

	if (sortFile(path)) {
		std::cout << "Invalid file\n";
		return;
	}

	std::cout << "Finished\n";
}

/**
 * Creates a new file derived from original file
 * New file is the content of original file sorted
 *
 * @brief sorts file in lexicographically order
 * @param filename path to the file to sort
 * @return 0 if successful process, otherwise -1
 */
int sortFile(std::string file) {

	std::ifstream inFile;
	inFile.open(file, std::ios::in);

	if (!inFile.is_open() || inFile.fail() || inFile.eof())
		return -1;

	size_t sep = file.find_last_of("\\/");
	std::string filename;
	std::string path;
	if (sep == std::string::npos) {
		filename = file;
		path = "";
		sep = filename.find_last_of(".");
		if (sep != std::string::npos) {
			filename = filename.substr(0, sep);
		}
	} else {
		path = file.substr(0, sep);
		filename = file.substr(sep + 1);
		sep = filename.find_last_of(".");
		if (sep != std::string::npos) {
			filename = filename.substr(0, sep);
		}
	}

	std::vector < std::string > lines;
	std::string line;
	while (!inFile.eof()) {
		std::getline(inFile, line, '\n');
		lines.push_back(line);
	}
	inFile.close();
	quickSort(lines, 0, lines.size() - 1);
	filename += "_sorted.txt";

	std::ofstream outfile;
	outfile.open(path + filename, std::ios::out);
	for (size_t i = 0; i < lines.size(); i++)
		outfile << lines.at(i) << "\n";

	outfile.close();

	return 0;
}
