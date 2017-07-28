/* Problem 21
 * Let d(n) be defined as the sum of proper divisors of n
 * (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair
 * and each of a and b are called amicable numbers.
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
 * therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142;
 * so d(284) = 220.
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
#include <math.h>

unsigned int d (const unsigned int& num) {
	unsigned int s = 1;
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			s += (i == sqrt(num)) ? i : i + num / i;
	return s;
}

int main () {
	unsigned int result = 0;

	for (int a = 1; a < 10000; a++) {
		const unsigned int b = d(a);
		if (d(b) == a && a != b)
			result += a;
	}

	std::cout << result;

	return 0;
}
