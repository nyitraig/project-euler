/* Problem 35
 * The number, 197, is called a circular prime because
 * all rotations of the digits: 197, 971, and 719, are themselves prime.
 * There are thirteen such primes below 100:
 * 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 * How many circular primes are there below one million?
 */

#include <iostream>
#include <math.h>
#include "../src/eulerlib.h"

int numLength (const unsigned int& num) {
	int length = 0, temp = num;
	while (temp) {
		temp /= 10;
		length++;
	}
	return length;
}

int main () {
	int result = 13;
	for (int i = 101; i < 1000000; i += 2) {
		if (EulerLib::isPrime(i)) {
			int num = i, length = numLength(i);
			do {
				num = (num + (pow(10, length) * (num % 10))) / 10;
			} while (num != i && EulerLib::isPrime(num));
			if (num == i)
				result++;
		}
	}
	std::cout << result;
	return 0;
}
