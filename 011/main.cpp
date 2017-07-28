/* Problem 11
 *
 * In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 */

#include <iostream>
#include <fstream>

int main () {
	int grid[20][20], max = 0;
	
	std::ifstream ifs("./011/input.txt", std::ifstream::binary);
	if (!ifs.is_open()) {
		std::cout << "Can't open file";
		return 1;
	}
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			ifs >> grid[i][j];
	ifs.close();

	// vertical
	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 20; j++) {
			int tmp = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
			if (tmp > max)
				max = tmp;
		}
	// horizontal
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 17; j++) {
			int tmp = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
			if (tmp > max)
				max = tmp;
		}
	// diagonal
	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 17; j++) {
			int tmp = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
			if (tmp > max)
				max = tmp;
		}
	for (int i = 0; i < 17; i++)
		for (int j = 3; j < 20; j++) {
			int tmp = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3];
			if (tmp > max)
				max = tmp;
		}

	std::cout << max;

	return 0;
}
