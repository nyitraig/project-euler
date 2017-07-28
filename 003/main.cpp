/* Problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <math.h>

bool isPrime (const unsigned int& num) {
	if (num == 2)
		return true;
	if (num < 2 || num % 2 == 0)
		return false;

	for (int i = 3; i <= sqrt(num); i+=2)
		if (num % i == 0)
			return false;

	return true;
}

int main () {
	int result;

	for (int i = 1; i <= sqrt(600851475143); i++)
		if (600851475143 % i == 0 && isPrime(i))
			result = i;

	std::cout << result;

	return 0;
}
