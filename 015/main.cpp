/* Problem 15
 * Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
 * there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20×20 grid?
 *
 * NOTE: you can calculate this on paper by finding the combination of 20 down and right moves:
 * '40 choose 20' (or	40! / (20! * 20!))
 */

#include <iostream>

int main () {
	unsigned long long grid[21][21];

	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++) {
			if (i == 0 || j == 0)
				grid[i][j] = 1;
			else
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}

	std::cout << grid[20][20];

	return 0;
}
