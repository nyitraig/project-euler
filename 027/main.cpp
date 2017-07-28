/* Problem 27
 * Euler discovered the remarkable quadratic formula: n^2 + n + 41
 * It turns out that the formula will produce 40 primes for
 * the consecutive integer values 0 ≤ n ≤ 39. However, when n = 40,
 * 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly
 * when n = 41 , 41^2 + 41 + 41 is clearly divisible by 41.
 *
 * The incredible formula n^2 − 79n + 1601 was discovered, which
 * produces 80 primes for the consecutive values 0 ≤ n ≤ 79.
 * The product of the coefficients, −79 and 1601, is −126479.
 *
 * Considering quadratics of the form:
 * n^2 + an + b, where |a| < 1000 and |b| ≤ 1000
 * where |n| is the modulus/absolute value of n
 * e.g. |11| = 11 and |−4| = 4
 * Find the product of the coefficients, a and b, for the quadratic expression
 * that produces the maximum number of primes
 * for consecutive values of n, starting with n = 0.
 *
 * NOTE: in the formula n^2 + an + b (or n(n + a) + b)
 * b has to be prime (since n = 0 leaves only b)
 * a has to be odd (because if a is even n(n + a) would
 * alternate between odd and even, depending on n)
 */

#include <iostream>
#include <vector>
#include "../src/eulerlib.h"

int main () {
	int a, b, max = 0;
	std::vector<unsigned int> primes;
	primes.push_back(2);
	for (int i = 1; i < 1000; i += 2)
		if (EulerLib::isPrime(i))
			primes.push_back(i);

	for (int i = -999; i < 1000; i += 2)
		for (int j = 0; j < primes.size(); j++) {
			unsigned int n = 0;
			while (EulerLib::isPrime(n * (n + i) + primes[j]))
				n++;
			if (n > max) {
				a = i;
				b = primes[j];
				max = n;
			}
		}

	std::cout << a * b;

	return 0;
}
