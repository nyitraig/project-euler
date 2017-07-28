/* Problem 13
 *
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 */

#include <iostream>
#include <fstream>

int main () {
	char numbers[100][50];
	int result[52], carry = 0;
	for (int i = 0; i < 52; i++)
		result[i] = '0';

	std::ifstream ifs("./013/input.txt", std::ifstream::binary);
	if (!ifs.is_open()) {
		std::cout << "Can't open file";
		return 1;
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 50; j++)
			ifs >> numbers[i][j];
	ifs.close();

	for (int i = 49; i >= 0; i--) {
		int sum = 0;
		for (int j = 99; j >= 0; j--)
			sum += numbers[j][i] - '0';
		result[i + 2] = (sum + carry) % 10;
		carry = (sum + carry) / 10;
	}

	for (int i = 1; i >= 0; i--) {
		result[i] = carry % 10;
		carry =  carry / 10;
	}

	for (int i = 0; i < 10; i++)
		std::cout << result[i];

	return 0;
}
