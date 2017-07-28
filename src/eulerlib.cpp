#include "eulerlib.h"

bool EulerLib::isPrime (const unsigned int& num) {
	if (num == 2)
		return true;
	if (num < 2 || num % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(num); i += 2)
		if (num % i == 0)
			return false;
	return true;
}

unsigned int EulerLib::gcd (const unsigned int& a, const unsigned int& b) {
	return b == 0 ? a : gcd(b, a % b);
}
