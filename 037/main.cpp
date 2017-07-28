/* Problem 37
 * The number 3797 has an interesting property. Being prime itself,
 * it is possible to continuously remove digits from left to right,
 * and remain prime at each stage: 3797, 797, 97, and 7.
 * Similarly we can work from right to left: 3797, 379, 37, and 3.
 * Find the sum of the only eleven primes that are
 * both truncatable from left to right and right to left.
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <iostream>
#include "../src/eulerlib.h"

bool isTrunkPrime (const unsigned int& num) {
	bool prime = EulerLib::isPrime(num);
	unsigned int temp = num, size = 1;
	while (temp && prime) {
		prime = EulerLib::isPrime(temp);
		temp /= 10;
		size *= 10;
	}
	temp = num;
	while (temp && prime) {
		prime = EulerLib::isPrime(temp);
		size /= 10;
		temp %= size;
	}
	return prime;
}

int main () {
	unsigned int sum = 0, n = 0, i = 23;
	while (n != 11) {
		if (isTrunkPrime(i)) {
			sum += i;
			n++;
		}
		i += 2;
	}
	std::cout << sum;
	return 0;
}
