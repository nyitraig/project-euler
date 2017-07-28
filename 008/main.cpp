/* Problem 8
 *
 * The four adjacent digits in the 1000-digit number that have the greatest product are
 * 9 × 9 × 8 × 9 = 5832.
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest product.
 * What is the value of this product?
 */

#include <iostream>
#include <fstream>

int main () {
	int number[1000], index = 0;
	unsigned long long product = 1, maxProduct = 1;

	std::ifstream ifs("./008/input.txt", std::ifstream::binary);
	if (!ifs.is_open()) {
		std::cout << "Can't open file";
		return 1;
	}
	while (ifs.good()) {
		int c = ifs.get();
		if (c != '\r' && c != '\n' && c != -1) // ignore newline and eof
			number[index++] = c - '0';
	}
	ifs.close();

	for (int i = 0; i < 1000 - 13; i++) {
		for (int j = 0; j < 13; j++) {
			product *= number[i + j];
		}
		if (product > maxProduct)
			maxProduct = product;
		product = 1;
	}

	std::cout << maxProduct;

	return 0;
}
