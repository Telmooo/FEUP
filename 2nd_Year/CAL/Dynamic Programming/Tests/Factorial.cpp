/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n) {
	return (n > 1)  ? n * factorialRecurs(n-1) : 1;
}

int factorialDinam(int n) {
	int fact = 1;
	for (int i = 2; i <= n; i++) fact *= i;
	return fact;
}
