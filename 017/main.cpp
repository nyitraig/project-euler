/* Problem 17
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
 * how many letters would be used?
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two)
 * contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
 * The use of "and" when writing out numbers is in compliance with British usage.
 */

#include <iostream>

int main () {
	int result = 0;
	// one, two, three, four, five, six, seven, eight, nine
	const int ones[9] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
	// ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
	const int teens[10] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	// twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
	const int tens[9] = {6, 6, 5, 5, 5, 7, 6, 6};
	// onehundred, twohundred, threehundred, fourhundred, fivehundred, sixhundred, sevenhundred, eighthundred, ninehundred
	const int hundreds[10] = {10, 10, 12, 11, 11, 10, 12, 12, 11};

	for (int i = 1; i <= 1000; i++) {
		if (i % 10 > 0 && (i % 100 < 10 || i % 100 > 19))
			result += ones[(i % 10) - 1];
		if (i % 100 >= 10 && i % 100 <= 19)
			result += teens[i % 10];
		if (i % 100 >= 20)
			result += tens[(i % 100) / 10 - 2];
		if (i % 1000 >= 100)
			result += hundreds[(i % 1000) / 100 - 1];
		if (i > 100 && i % 100 > 0)
			result += 3; // and
		if (i == 1000)
			result += 11; // onethousand
	}

	std::cout << result;

	return 0;
}
