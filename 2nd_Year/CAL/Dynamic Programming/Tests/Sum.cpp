/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>

string calcSum(int* sequence, int size) {

    string result;

    for (int m = 1; m <= size; m++) {
        int i = 0, startIndex;
        int minSum, sum = 0;

        while (i < m)
            sum += sequence[i++];

        minSum = sum;
        startIndex = i-m;
        while (i < size) {
            sum += -sequence[i-m] + sequence[i];
            if (sum < minSum) {
                minSum = sum;
                startIndex = i - m + 1;
            }
            i++;
        }
        result += to_string(minSum) + "," + to_string(startIndex) + ";";
    }
	return result;
}
