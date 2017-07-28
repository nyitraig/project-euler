/* Problem 25
 * The Fibonacci sequence is defined by the recurrence relation:
 *   F_n = F_n−1 + F_n−2, where F_1 = 1 and F_2 = 1.
 * Hence the first 12 terms will be:
 *   F_1 = 1
 *   F_2 = 1
 *   F_3 = 2
 *   F_4 = 3
 *   F_5 = 5
 *   F_6 = 8
 *   F_7 = 13
 *   F_8 = 21
 *   F_9 = 34
 *   F_10 = 55
 *   F_11 = 89
 *   F_12 = 144
 * The 12th term, F_12, is the first term to contain three digits.
 * What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <iostream>
#include "../src/bignum.h"

int main () {
	BigNum a(1);
	BigNum b(1);
	int index = 2;

	while (a.num_of_digits() != 1000 && b.num_of_digits() != 1000) {
		BigNum temp(a);
		a = b;
		b = temp + b;
		index++;
	}

	std::cout << index;

	return 0;
}
