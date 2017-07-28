/* Problem 32
 * We shall say that an n-digit number is pandigital if it makes use
 * of all the digits 1 to n exactly once; for example,
 * the 5-digit number, 15234, is 1 through 5 pandigital.
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254,
 * containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 * Find the sum of all products whose multiplicand/multiplier/product identity
 * can be written as a 1 through 9 pandigital.
 * HINT: Some products can be obtained in more than one way
 * so be sure to only include it once in your sum.
 * NOTE:
 * in the following formula: a * b = c
 * c will always be a four digit number and its either the product of
 *  - a one digit number and a four digit number
 *  - a two digit number and a three digit number
 * thus 1 <= a <= 98 and 123 <= b <= 9876
 */

#include <iostream>
#include <string>
#include <sstream>
#include <set>

bool isPandigital (const unsigned int& a, const unsigned int& b, const unsigned int& c) {
	std::stringstream ss;
	ss << a << b << c;
	std::string number = ss.str();
	if (number.size() != 9)
		return false;
	for (int i = 1; i <= 9; i++)
		if (number.find(i + '0') == std::string::npos)
			return false;
	return true;
}

int main () {
	unsigned int sum = 0;
	std::set<unsigned int> s;

	for (unsigned int i = 1; i <= 98; i++)
		for (unsigned int j = 123; j <= 9876; j++)
			if (isPandigital(i, j, i * j))
				s.insert(i * j);

	for (std::set<unsigned int>::iterator it = s.begin(); it != s.end(); it++)
		sum += *it;

	std::cout << sum;

	return 0;
}
