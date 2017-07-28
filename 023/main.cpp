/* Problem 23
 * A perfect number is a number for which the sum of its proper divisors
 * is exactly equal to the number.
 * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
 * which means that 28 is a perfect number.
 * A number n is called deficient if the sum of its proper divisors is less than n
 * and it is called abundant if this sum exceeds n.
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16,
 * the smallest number that can be written as the sum of two abundant numbers is 24.
 * By mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers.
 * However, this upper limit cannot be reduced any further by analysis
 * even though it is known that the greatest number that cannot be expressed
 * as the sum of two abundant numbers is less than this limit.
 * Find the sum of all the positive integers which cannot be written
 * as the sum of two abundant numbers.
 */

#include <iostream>
#include <vector>
#include <math.h>

unsigned int properDivSum (const unsigned int& num) {
	unsigned int s = 1;
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			s += (i == sqrt(num)) ? i : i + num / i;
	return s;
}


int main () {
	unsigned int result = 0;
	std::vector<unsigned int> abundantNums;
	std::vector<bool> abundantSums (28123 + 1, false);

	for (int i = 12; i <= 28123; i++)
		if (properDivSum(i) > i) {
			abundantNums.push_back(i);
			for (int j = 0; j < abundantNums.size(); j++) {
				unsigned int sum = i + abundantNums[j];
				if (sum <= 28123)
					abundantSums[sum] = true;
			}
		}

	for (int i = 1; i < abundantSums.size(); i++)
		if (!abundantSums[i])
			result += i;

	std::cout << result;

	return 0;
}
