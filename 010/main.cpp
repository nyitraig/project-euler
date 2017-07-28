/* Problem 10
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include <iostream>
#include "../src/eulerlib.h"

int main () {
	unsigned long long result = 2; // 2 is the first, and only even prime

	for (int i = 3; i < 2000000; i += 2) {
		if (EulerLib::isPrime(i)) {
			result += i;
		}
	}

	std::cout << result;

	return 0;
}
