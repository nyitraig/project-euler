/* Problem 43
 * The number, 1406357289, is a 0 to 9 pandigital number because
 * it is made up of each of the digits 0 to 9 in some order,
 * but it also has a rather interesting sub-string divisibility property.
 * Let d_1 be the 1st digit, d_2 be the 2nd digit, and so on.
 * In this way, we note the following:
 *     d_2 d_3 d_4  = 406 is divisible by 2
 *     d_3 d_4 d_5  = 063 is divisible by 3
 *     d_4 d_5 d_6  = 635 is divisible by 5
 *     d_5 d_6 d_7  = 357 is divisible by 7
 *     d_6 d_7 d_8  = 572 is divisible by 11
 *     d_7 d_8 d_9  = 728 is divisible by 13
 *     d_8 d_9 d_10 = 289 is divisible by 17
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <iostream>

void calc (unsigned long long int& res, unsigned int num = 0) {
	unsigned int digits[10], temp = num, size = 0, divisor;
	for (int i = 0; i < 10; i++)
		digits[i] = 0;
	while (temp) {
		digits[temp % 10]++;
		temp /= 10;
		size++;
	}
	if (size == 0)
		for (int i = 1; i <= 9; i++)
			calc(res, i);
	if (size >= 1 && size <= 9) {
		switch (size) {
			case  3 : divisor = 2;  break;
			case  4 : divisor = 3;  break;
			case  5 : divisor = 5;  break;
			case  6 : divisor = 7;  break;
			case  7 : divisor = 11; break;
			case  8 : divisor = 13; break;
			case  9 : divisor = 17; break;
			default : divisor = 1;  break;
		}
		for (int i = 0; i <= 9; i++)
			if (!digits[i] && ((num % 100) * 10 + i) % divisor == 0)
				calc(res, num * 10 + i);
	}
	if (size == 10)
		res += num;
}

int main () {
	unsigned long long int result = 0;
	calc(result);
	std::cout << result;
	return 0;
}
