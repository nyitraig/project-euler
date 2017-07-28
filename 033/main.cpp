/* Problem 33
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician
 * in attempting to simplify it may incorrectly believe that 49/98 = 4/8,
 * which is correct, is obtained by cancelling the 9s.
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 * There are exactly four non-trivial examples of this type of fraction,
 * less than one in value, and containing two digits in the numerator and denominator.
 * If the product of these four fractions is given in its lowest common terms,
 * find the value of the denominator.
 */

#include <iostream>

int gcd (const int& a, const int& b) { // Greatest common divisor
    return b == 0 ? a : gcd(b, a % b);
}

int main () {
	int numerator = 1, denominator = 1;

	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			for (int k = 1; k <= 9; k++) {
				const float a = 10 * i + j, b = 10 * j + k;
				if (i != j && a / b == (float)i / (float)k) {
					numerator *= i;
					denominator *= k;
				}
			}

	std::cout << denominator / gcd(numerator, denominator);

	return 0;
}
