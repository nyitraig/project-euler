/* Problem 24
 * A permutation is an ordered arrangement of objects.
 * For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 * If all of the permutations are listed numerically or alphabetically,
 * we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 * 012   021   102   120   201   210
 * What is the millionth lexicographic permutation
 * of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 * NOTE:
 * We can construct the next permutation in lexicographic order
 * by following these simple steps (as explained by Michal Forišek https://bit.ly/2toGEas):
 * 1. Find the largest x such that P[x]<P[x+1].
 *    (If there is no such x, P is the last permutation.)
 * 2. Find the largest y such that P[x]<P[y].
 * 3. Swap P[x] and P[y].
 * 4. Reverse P[x+1 .. n].
 */

#include <iostream>

int main () {
	unsigned int x = 0, y = 0, arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 1; i < 1000000; i++) {
		for (int j = 0; j < 9; j++)
			if (arr[j] < arr[j + 1])
				x = j;
		for (int j = x + 1; j < 10; j++)
			if (arr[x] < arr[j])
				y = j;
		int temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
		for (int j = x + 1; j < 9 - ((9 - (x + 1)) / 2); j++) {
			int temp = arr[j];
			arr[j] = arr[9 - (j - (x + 1))];
			arr[9 - (j - (x + 1))] = temp;
		}
	}

	for (int i = 0; i < 10; i++)
		std::cout << arr[i];

	return 0;
}
