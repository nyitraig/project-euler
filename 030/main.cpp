/* Problem 30
 * Surprisingly there are only three numbers that can be written
 * as the sum of fourth powers of their digits:
 *    1634 = 1^4 + 6^4 + 3^4 + 4^4
 *    8208 = 8^4 + 2^4 + 0^4 + 8^4
 *    9474 = 9^4 + 4^4 + 7^4 + 4^4
 * As 1 = 1^4 is not a sum it is not included.
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 * Find the sum of all the numbers that can be written
 * as the sum of fifth powers of their digits.
 * NOTE:
 * First, lets find the upper bound!
 *    1 * 9^5 = 59049  // 5 digit number
 *    5 * 9^5 = 295245 // 6 digit number
 *    6 * 9^5 = 354294 // 6 digit number
 *    7 * 9^5 = 413343 // 6 digit number
 * since the largest 7 digit number results in a 6 digit number, there is no need
 * to check any number greater than 6 * 9^5 = 354294.
 */

#include <iostream>

int main () {
	unsigned int result = 0, fifthPow[10];
		for (int i = 0; i < 10; i++)
			fifthPow[i] = i * i * i * i * i;

	for (int i = 10; i <= 354294; i++) {
		int num = i, sum = 0;
		while (num != 0) {
			sum += fifthPow[num % 10];
			num /= 10;
		}
		if (i == sum)
			result += i;
	}

	std::cout << result;

	return 0;
}
