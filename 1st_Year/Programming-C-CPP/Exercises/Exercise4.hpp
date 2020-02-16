/**
 * @file Exercise4.hpp
 *
 * @brief Declarations for exercise 4
 *
 * @author telmo
 * @version 1.0
 * @since 01-03-2019
 */

#pragma once
#include <string>
#include <vector>
#include <cstddef>

 /**
  * Runs exercise 4: Arrays | Vectors | Strings | Structs | Files
  * Allows user to choose which exercise to run from the fourth exercise
  *
  * @brief execute exercise 4
  */
void runExercise4(void);

/**
 * User can input a chemical and outputs whether the chemical is a hydroxide or not
 *
 * @brief execute hydroxide checker for chemicals
 */
void runChem(void);

/**
 * Checks if chemical is a hydroxide
 * Input as C String
 *
 * @brief checks if chemical is a hydroxide
 * @param compound chemical
 * @return 1 if chemical is a hydroxide, otherwise 0
 */
bool isHydroxide(char compound[]);

/**
 * Checks if chemical is a hydroxide
 * Input as C++ String
 *
 * @overload bool isHydroxide(std::string compound)
 */
bool isHydroxide(std::string compound);

/**
 * User inputs text and searches for sequences of a character
 *
 * @brief executes searcher for sequences in string
 */
void runSeqSearch(void);

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
bool sequenceSearch(std::string str, int nc, char c);

/**
 * Takes a chemical given by the user and outputs its components
 * Separating each atom that composes the chemical
 *
 * @brief separate chemical into atoms
 */
void runDecomposition(void);

/**
 * Takes a chemical decomposing it into atoms
 * Chemical must be a valid chemical, unexpected behaviour on non-valid chemicals
 *
 * @brief outputs all atoms that compose the chemical
 * @param compound chemical to decompose
 */
void decompose(std::string compound);

/**
 * User inputs name and outputs the normalised name
 * Normalise name: One space between names (every name capitalised)
 *
 * @brief normalises name
 */
void runNormName(void);

/**
 * Normalises name, deleting all repeated white spaces and capitalising the names
 *
 * @param name name to normalise
 * @return normalised name
 */
std::string normalizeName(std::string name);

/**
 * Checks if a value is in the array
 *
 * @brief checks if value is in the array
 * @param arr array to check for value
 * @param arrLength length of the array
 * @param element value to search for
 * @return 1 if value is found, otherwise 0
 */
bool arrayContains(const std::string arr[], int arrLength, const std::string element);

/**
 * Fraction containing two members:
 * 	- an integer numerator
 * 	- an integer denominator
 *
 *
 * @brief struct to store fractions
 */
typedef struct {
	int numerator;
	int denominator;
} Fraction;

/**
 * Allows user to input fractions and execute simple operations with fractions
 *
 * @brief executes fraction reader and operator
 */
void runStructFraction(void);

/**
 * Reads fraction from user
 * If user inputs invalid fraction, returns an undefined fraction (0 / 0)
 *
 * @brief reads fraction from user
 * @return fraction evaluated from input
 * @see Fraction
 */
Fraction readFraction(void);

/** Writes fraction into console following the format
 * {numerator} / {denominator}
 *
 * @brief outputs fraction
 * @param fracc fraction to write
 * @see Fraction
 */
void writeFraction(const Fraction &fracc);

/**
 * Creates a new fraction resulted from reducing to the smallest terms
 * the fraction passed to the function
 *
 * @brief reduces fraction to smallest terms
 * @param fracc fraction to reduce
 * @return fraction derived from fracc (fracc reduced to the lowest terms)
 * @see Fraction
 */
Fraction reduceFraction(const Fraction &fracc);

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
Fraction arithmeticFraction(const Fraction &fracc1, int op, const Fraction &fracc2);

/**
 * Calculates the greatest common divisor using euclidean algorithm (iterative)
 *
 * @brief calculates greatest common divisor
 * @param a first number
 * @param b second number
 * @return value of the greatest common divisor
 */
int gcd2(int a, int b);

/**
 * Allows user to input arrays, search for elements in arrays
 * All values entered must be whole numbers (integers)
 *
 * @brief executes function related to arrays
 */
void runArrays(void);

/**
 * Reads from user an array of integers of nElem number of elements
 *
 * @brief reads array of specified size from user
 * @param arr [out] deposit for the array
 * @param nElem [in] size of the array
 */
void readIntArray(int arr[], int nElem);

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
int searchValueInIntArray(const int arr[], int nElem, int value);

/**
 * Searches for value in the array, returning all the positions where it occurs, if any
 *
 * @overload int searchValueInIntArray(const int arr[], int nElem, int value, int index[])
 * @param index [out] indexes of the occurrences of the value if any
 * @return 1 if any found, else 0
 */
int searchValueInIntArray(const int arr[], int nElem, int value, int index[]);

/**
 * Reads from user an vector of integers
 *
 * @brief reads vector of specified size from user
 */
void runVectors(void);

/**
 * Reads from user a vector of integers with specified size
 *
 * @brief reads array of specified size from user
 * @param nElem size of the vector
 */
std::vector<int> readIntVector(size_t nElem);

/**
 * Checks if a value is in the vector, returning the index if found
 * (Short-cut implementation (returns on the first occurrence))
 *
 * @brief searches for value in vector
 * @param vect vector of integers
 * @param value integer to search for
 * @return index of element if found, else -1
 */
size_t searchValueInVector(const std::vector<int> &vect, int value);

/**
 * Searches for value in the vector, returning all the positions where it occurs, if any
 *
 * @brief searches for value in vector
 * @param vect vector of integers
 * @param value integer to search for
 * @return vector containing the indexes of the occurrences (empty vector if not found any)
 */
std::vector<int> searchMultValuesInVector(const std::vector<int> &vect, int value);

/**
 * Reads from user a vector of integers
 * Size is not specified, vector is finished when CTRL-Z is entered
 *
 * @overload std::vector<int> readIntVector()
 */
std::vector<int> readIntVector(void);

/**
 * Reads from user a vector of integers
 * Size is not specified, vector is finished when CTRL-Z is entered
 *
 * @param MAX_STRING_SIZE Maximum character per string
 * @return vector user entered
 */
std::vector<std::string> readStringVector(const size_t MAX_STRING_SIZE);

/**
 * Allows user to execute algorithms on vectors
 * Algorithms: Bubble Sort, Quick Sort, Binary Search
 *
 * @brief executes function related to algorithms
 */
void runAlgorithms(void);

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
void bubbleSort(std::vector<std::string> &v);

/**
 * Sorts a vector of strings in ascending order
 *
 * @overload void bubbleSort(std::vector<int> &v)
 */
void bubbleSort(std::vector<int> &v);

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
void quickSort(std::vector<std::string> &v, size_t start, size_t end);

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
size_t partition(std::vector<std::string> &v, size_t start, size_t end);

/**
 * Sorts an vector of strings in ascending order
 *
 * @overload void quickSort(std::vector<int> &v, size_t start, size_t end)
 */
void quickSort(std::vector<int> &v, size_t start, size_t end);

/**
 * Creates two partitions, rightmost has the small values, rightmost high values
 * Pivot is chosen randomly
 *
 * @overload size_t partition(std::vector<int> &v, size_t start, size_t end)
 */
size_t partition(std::vector<int> &v, size_t start, size_t end);

/**
 * Swaps two elements on the vector
 *
 * @brief swaps elements on the vector
 * @param v [in] [out] vector of integers
 * @param i first position of element to swap
 * @param j second position of element to swap
 */
void swap(std::vector<int> &v, size_t i, size_t j);

/**
 * Swaps two elements on the vector
 *
 * @overload void swap(std::vector<std::string> &v, size_t i, size_t j)
 */
void swap(std::vector<std::string> &v, size_t i, size_t j);

/**
 * Randomises the order of the elements of a vector randomly
 *
 * @brief shuffles the vector
 * @param v [in] [out] vector of string to shuffle
 */
void shuffle(std::vector<std::string> &v);

/**
 * Randomises the order of the elements of a vector randomly
 *
 * @overload void shuffle(std::vector<int> &v)
 */
void shuffle(std::vector<int> &v);

/**
 * Searches for value using Binary Search
 * Returns position of value if found else -1
 * Vector must be sorted, unexpected behaviour if not sorted
 *
 * @brief searches for value in vector
 * @param v vector of strings
 * @param value string to search for
 */
size_t binarySearch(const std::vector<std::string> &v, std::string value);

/**
 * User inputs a vector of integers and removes duplicated elements from the vector
 * Order of elements is maintained
 *
 * @brief removes duplicates elements from vector user entered
 * @see readIntVector()
 */
void runRemDup(void);

/**
 * Removes duplicates from vector, maintaining order
 *
 * @brief removes duplicates from vector
 * @param v [in] [out] vector of integers
 */
void removeDuplicates(std::vector<int> &v);

/**
 * Checks if value is already in the vector (is duplicated)
 * Vector v is a vector containing all the values already seen
 *
 * @param v vector of integers containing all seen elements from other vector
 * @param value integer to check if duplicated
 * @return 1 if duplicated, else 0
 */
bool duplicated(const std::vector<int> &v, int value);

/**
 * User inputs two vectors and outputs the intersection and the union of the vectors
 *
 * @brief executes function that creates intersection/union of vectors
 */
void runVectUniInter(void);

/**
 * Removes duplicated values from vector
 * Vector must be sorted, undefined behaviour if not sorted
 *
 * @brief remove duplicates from vector
 * @param v [in] [out]
 */
void removeAdjacents(std::vector<int> &v);

/**
 * Makes a copy of vector
 *
 * @brief copies vector
 * @param v vector of integers to copy
 * @return copy of vector v
 */
std::vector<int> copyVector(const std::vector<int> &v);

/**
 * Creates the unique vector result of the union of two vectors
 * Vector contains all elements from both vectors (common and non-common)
 *
 * @brief union of two vectors
 * @param v1 first vector
 * @param v2 second vector
 * @return vector derived by the union of v1 and v2
 */
std::vector<int> vectorUnion(const std::vector<int> &v1, const std::vector<int> &v2);

/**
 * Creates the unique vector result of the intersection of two vectors
 * Vector contains common elements between two vectors
 *
 * @brief intersection of two vectors
 * @param v1 first vector
 * @param v2 second vector
 * @return vector derived by the intersection of v1 and v2
 */
std::vector<int> vectorIntersection(const std::vector<int> &v1, const std::vector<int> &v2);

/**
 * Allow user to input basic math operations
 * Operations: Sum, Subtraction, Multiplication, Division
 * Respects rules of precedence (PEMDAS/BODMAS)
 *
 * @brief basic operation parser
 */
void runOps(void);

/**
 * Parses the operation and calculates the result
 * If invalid operation is evaluated as 0
 *
 * @brief parses operation
 * @param op string containing operation
 * @return result of the operation
 */
double executeOperation(std::string op);

/**
 * Allows user to input a file to sort it
 * Sorted files doesn't override original file
 *
 * @brief sorts file given by user
 */
void runFiles(void);

/**
 * Creates a new file derived from original file
 * New file is the content of original file sorted
 *
 * @brief sorts file in lexicographically order
 * @param filename path to the file to sort
 * @return 0 if successful process, otherwise -1
 */
int sortFile(std::string filename);
