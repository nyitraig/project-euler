/* Problem 5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible (divisible with no remainder)
 * by all of the numbers from 1 to 20?
 */

#include <iostream>

bool isEvenlyDiv (const unsigned int& num) {
	for (int i = 2; i <= 20; i++)
		if (num % i != 0)
			return false;

	return true;
}

int main () {
	int result = 20;

	while (!isEvenlyDiv(result)) {
		result += 20;
	}

	std::cout << result;

	return 0;
}
