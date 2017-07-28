/* Problem 34
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 * NOTE: as 1! = 1 and 2! = 2 are not sums they are not included.
 * Lets find an upper bound first!
 *    9! = 362880
 *    6 * 9! = 2177280 (a 7 digit number)
 *    7 * 9! = 2540160 (also a 7 digit number)
 * so as the number 9999999 would produce the above sum, that can be our upper bound
 */

#include <iostream>

unsigned int factorial (const unsigned int& num) {
	return (num == 0) ? 1 : num * factorial(num - 1);
}

int main () {
	unsigned int fact[10], result = 0;
	for (int i = 0; i < 10; i++)
		fact[i] = factorial(i);

	for (int i = 10; i < 7 * fact[9]; i++) {
		int sum = 0, num = i, digit;
		while (num) {
			digit = num % 10;
			num /= 10;
			sum += fact[digit];
		}
		if (sum == i)
			result += i;
	}

	std::cout << result;

	return 0;
}
