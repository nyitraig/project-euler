/* Problem 41
 * We shall say that an n-digit number is pandigital
 * if it makes use of all the digits 1 to n exactly once.
 * For example, 2143 is a 4-digit pandigital and is also prime.
 * What is the largest n-digit pandigital prime that exists?
 * NOTE: We know that the prime must be at least 4 digits long.
 * If it's 5 digits long, 1+2+3+4+5 = 15 makes it a multiple of 3.
 * Adding a 6 won't change this. 7 digits (1+2+3+4+5+6+7 = 28) is fine.
 * Similarly, adding an 8 and 9 makes the number still divisible by 3.
 */

#include <iostream>
#include "../src/eulerlib.h"

bool isPandigital (unsigned int num) {
	bool result = true;
	int digits[10], length = 0;
	for (int i = 0; i < 10; i++)
		digits[i] = 0;
	while (num) {
		digits[num % 10]++;
		num /= 10;
		length++;
	}
	for (int i = 1; i <= length && result; i++)
		if (digits[i] != 1)
			result = false;
	return result;
}

int main () {
	unsigned int max = 0;
	for (int i = 1234567; i <= 7654321; i += 2)
		if (isPandigital(i) && EulerLib::isPrime(i))
			max = i;
	std::cout << max;
	return 0;
}
