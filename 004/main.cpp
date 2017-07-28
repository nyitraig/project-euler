/* Problem 4
 *
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>

bool isPalindrome (const unsigned int& num) {
	int reverse = 0, original = num;

	while (original) {
		reverse = reverse * 10 + original % 10;
		original /= 10;
	}

	return reverse == num;
}

int main () {
	int max = 0;

	for (int i = 100; i < 1000; i++)
		for (int j = 100; j < 1000; j++) {
			int prod = i * j;
			if (isPalindrome(prod) && prod > max)
				max = prod;
		}

	std::cout << max;

	return 0;
}
