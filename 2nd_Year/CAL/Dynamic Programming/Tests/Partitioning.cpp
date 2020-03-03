/*
 * Partioning.cpp
 */

#include "Partitioning.h"


int s_recursive(int n,int k) {
    if (k == 1 || n == k) return 1;
    return s_recursive(n-1, k-1) + k * s_recursive(n-1, k);
}

int s_dynamic(int n,int k) {
	return 1;
}


int b_recursive(int n) {
    if ()
	return s_recursive(n, 1)
}

int b_dynamic(int n) {
	return 0;
}


