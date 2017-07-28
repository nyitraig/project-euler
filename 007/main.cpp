/* Problem 7
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
 * we can see that the 6th prime is 13.
 * What is the 10001st prime number?
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
	int c = 1, num = 1; // let's say we found 2 so we only need to check odd numbers

	while (c < 10001) {
		num += 2;
		if (isPrime(num))
			c++;
	}

	std::cout << num;

	return 0;
}
