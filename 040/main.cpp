/* Problem 40
 * An irrational decimal fraction is created by concatenating the positive integers:
 *    0.123456789101112131415161718192021...
 * It can be seen that the 12th digit of the fractional part is 1.
 * If d_n represents the nth digit of the fractional part,
 * find the value of the following expression.
 *    d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000
 */

#include <iostream>
#include <sstream>

int main () {
	std::ostringstream ss;
	unsigned int result = 1;
	for (int i = 1; i < 20000; i++)
		ss << i;
	for (int i = 1; i < 1000000; i *= 10)
		result *= ss.str()[i - 1] - '0';
	std::cout << result;
	return 0;
}
