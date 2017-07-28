/* Problem 36
 * The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 */

#include <iostream>

bool isPalindrome (const unsigned int& num, const unsigned int& base) {
	int reverse = 0, original = num;
	while (original) {
		reverse = reverse * base + original % base;
		original /= base;
	}
	return reverse == num;
}

int main () {
	int sum = 0;
	for (int i = 1; i < 1000000; i += 2)
		if (isPalindrome(i, 10) && isPalindrome(i, 2))
			sum += i;
	std::cout << sum;
	return 0;
}
