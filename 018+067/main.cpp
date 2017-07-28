/* Problem 18
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below,
 * the maximum total from top to bottom is 23.
 *     3
 *    7 4
 *   2 4 6
 *  8 5 9 3
 * That is, 3 + 7 + 4 + 9 = 23.
 * Find the maximum total from top to bottom of the triangle below:
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route.
 * However, Problem 67, is the same challenge with a triangle containing one-hundred rows;
 * it cannot be solved by brute force, and requires a clever method! ;o)
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

unsigned int index (const unsigned int& i, const unsigned int& j) {
	return (i + 1) * i / 2 + j;
}

unsigned int pathSum (const char* filename) {
	// lets think of our triangle of numbers as a lower triangular matrix,
	// and store it in a one-dimensional array instead of a two-dimensional one (why not?)
	std::vector<unsigned int> triangle;
	std::ifstream ifs(filename, std::ifstream::binary);
	if (!ifs.is_open()) {
		std::cout << "Can't open file";
		return 1;
	}
	while (ifs.good()) {
		int tmp;
		ifs >> tmp;
		triangle.push_back(tmp);
	}
	ifs.close();

	// got this from nth triangle number formula: (n*(n+1))/2
	int height = 0.5 * (-1 + sqrt(1 + 8 * (triangle.size() - 1)));

	for (int i = height - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			triangle[index(i, j)] += (triangle[index(i + 1, j)] > triangle[index(i + 1, j + 1)]) ?
				triangle[index(i + 1, j)] : triangle[index(i + 1, j + 1)];

	return triangle[0];
}

int main () {
	std::cout << pathSum("./018+067/p018_triangle.txt") << std::endl;
	std::cout << pathSum("./018+067/p067_triangle.txt");

	return 0;
}
