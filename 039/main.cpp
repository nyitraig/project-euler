/* Problem 39
 * If p is the perimeter of a right angle triangle with integral length sides,
 * {a,b,c}, there are exactly three solutions for p = 120.
 * {20,48,52}, {24,45,51}, {30,40,50}
 * For which value of p ≤ 1000, is the number of solutions maximised?
 * NOTE: let's generate all pythagorean triples such that a + b + c is <= 1000
 * using Euclid's formula:
 * a = k * (m^2 - n^2), b = k2mn, c = k * (m^2 + n^2)
 *              (m, n, k > 0 && m > n && m and n are coprime and not both odd)
 */

#include <iostream>
#include <vector>
#include "../src/eulerlib.h"

int main () {
	std::vector<unsigned int> p(1001, 0);
	unsigned int max = 0;
	for (int n = 1; n <= 15; n++)
		for (int m = n + 1; m <= 21; m++)
			if (EulerLib::gcd(m, n) == 1 && (m % 2 == 0 || n % 2 == 0))
				for (int k = 1; 2 * k * m * (m + n) <= 1000; k++)
					p[2 * k * m * (m + n)]++;
	for (int i = 0; i <= 1000; i++)
		if (p[i] > p[max])
			max = i;
	std::cout << max;
	return 0;
}
