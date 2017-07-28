/* Problem 31
 * In England the currency is made up of pound, £, and pence, p,
 * *and there are eight coins in general circulation:
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 * It is possible to make £2 in the following way:
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins?
 * NOTE:
 * solution based on the video by Tushar Roy
 * https://youtu.be/_fgjrs570YE
 */

#include <iostream>

int main () {
	const unsigned int total = 200, coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
	int temp[9][201];
	for (int i = 0; i <= 8; i++)
		temp[i][0] = 1;

	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 200; j++)
			if (coins[i - 1] > j)
				temp[i][j] = temp[i - 1][j];
			else
				temp[i][j] = temp[i][j - coins[i - 1]] + temp[i - 1][j];

	std::cout << temp[8][total];

	return 0;
}
