/* Problem 26
 * A unit fraction contains 1 in the numerator. The decimal representation
 * of the unit fractions with denominators 2 to 10 are given:
 *   1/2	= 	0.5
 *   1/3	= 	0.(3)
 *   1/4	= 	0.25
 *   1/5	= 	0.2
 *   1/6	= 	0.1(6)
 *   1/7	= 	0.(142857)
 *   1/8	= 	0.125
 *   1/9	= 	0.(1)
 *   1/10	= 	0.1
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
 * It can be seen that 1/7 has a 6-digit recurring cycle.
 * Find the value of d < 1000 for which 1/d contains the longest
 * recurring cycle in its decimal fraction part.
 */

#include <iostream>
#include <vector>
#include <algorithm>

unsigned int cycleLength (const unsigned int& num) {
	unsigned int carry = 10;
	std::vector<unsigned int> fraction;
	bool hasCycle = false;

	while (carry != 0 && !hasCycle) {
		carry = (carry % num) * 10;
		hasCycle = std::find(fraction.begin(), fraction.end(), carry) != fraction.end();
		fraction.push_back(carry);
	}

	return hasCycle ? (fraction.end() - std::find(fraction.begin(), fraction.end(), carry)) - 1 : 0;
}

int main () {
	int maxLength = 0, result = 0;

	for (int i = 2; i < 1000; i++) {
		const unsigned int length = cycleLength(i);
		if (length > maxLength) {
			maxLength = length;
			result = i;
		}
	}

	std::cout << result;

	return 0;
}
