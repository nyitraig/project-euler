#include "bignum.h"

BigNum::BigNum () {
	negative = false;
}

BigNum::BigNum (const int& num) {
	int temp = num;

	if (temp < 0) {
		negative = true;
		temp *= -1;
	} else {
		negative = false;
	}

	if (temp == 0) {
		number.push_back(0);
	} else {
		while (temp != 0) {
			int digit = temp % 10;
			temp = (temp - digit) / 10;
			number.push_back(digit);
		}
	}
}

BigNum::BigNum (const std::string& str) {
	negative = (str[0] == '-') ? true : false;

	for (int i = str.size() - 1; i >= negative ? 1 : 0; i--) {
		number.push_back(str[i] - 48);
	}
}

BigNum::BigNum (const BigNum& other) : number(other.number), negative(other.negative) {}

BigNum::BigNum (const std::vector<int>& num, const bool& neg) : number(num), negative(neg) {}


unsigned int BigNum::num_of_digits () const {
	return number.size();
}

unsigned int BigNum::digit_sum () const {
	unsigned int result = 0;

	for (int i = 0; i < number.size(); i++) {
		result += number[i];
	}

	return result;
}


BigNum BigNum::fact () const {
	// TODO
}

BigNum BigNum::pow (const BigNum& p) const {
	if (p < BigNum(0)) {
		// TODO
	} else if (p == BigNum(0)) {
		return BigNum(1);
	} else if (p == BigNum(1)) {
		return *this;
	} else {
		BigNum result(1);
		for (BigNum i = 0; i < p; i += 1) {
			result *= *this;
		}
		return result;
	}
}


BigNum& BigNum::operator= (const BigNum& other) {
	if (this != &other) {
		negative = other.negative;
		number.clear();

		for (int i = 0; i < other.number.size(); i++) {
			number.push_back(other.number[i]);
		}
	}
	return *this;
}


BigNum BigNum::operator+ (const BigNum& other) const {
	BigNum temp = *this;
	temp += other;

	return temp;
}

BigNum& BigNum::operator+= (const BigNum& other) {
	if ((negative && other.negative) || (!negative && !other.negative)) {
		int i = 0;
		int j = 0;
		int carry = 0;

		while (i < number.size() && j < other.number.size()) {
			int sum = number[i] + other.number[j] + carry;
			number[i] = sum % 10;
			carry = sum / 10;

			i++; j++;
		}

		if (i < number.size()) {
			while (i < number.size()) {
				int sum = number[i] + carry;
				number[i] = sum % 10;
				carry = sum / 10;

				i++;
			}
		} else {
			while (j < other.number.size()) {
				int sum = other.number[j] + carry;
				number.push_back(sum % 10);
				carry = sum / 10;

				j++;
			}
		}

		if (carry) {
			number.push_back(1);
		}

		return *this;
	} else {
		return (other.negative) ? *this -= -other : BigNum(other) -= -*this;
	}
}

BigNum BigNum::operator+ (const int& other) const {
	BigNum temp = *this;
	temp += other;

	return temp;
}

BigNum& BigNum::operator+= (const int& other) {
	if ((negative && other < 0) || (!negative && other > 0)) {
		int carry = (other < 0) ? -other : other;

		for (int i = 0; i < number.size(); i++) {
			int sum = number[i] + carry;
			number[i] = sum % 10;
			carry = sum / 10;
		}

		while (carry) {
			number.push_back(carry % 10);
			carry /= 10;
		}

		return *this;
	} else {
		return (other < 0) ? *this -= -other : BigNum(other) -= -*this;
	}
}


BigNum BigNum::operator- (const BigNum& other) const {
	BigNum temp = *this;
	temp -= other;

	return temp;
}

BigNum& BigNum::operator-= (const BigNum& other) {
	// TODO
}

BigNum BigNum::operator- (const int& other) const {
	BigNum temp = *this;
	temp -= other;

	return temp;
}

BigNum& BigNum::operator-= (const int& other) {
	// TODO
}


BigNum BigNum::operator* (const BigNum& other) const {
	BigNum temp = *this;
	temp *= other;

	return temp;
}

BigNum& BigNum::operator*= (const BigNum& other) {
	std::vector<int> result(number.size() + other.number.size(), 0);

	for (int i = 0; i < number.size(); i++) {
		int carry = 0;
		for (int j = 0; j < other.number.size() || carry > 0; j++) {
			int mult = result[i + j] + carry + number[i] * (j < other.number.size() ? other.number[j] : 0);
			result[i + j] = mult % 10;
			carry = mult / 10;
		}
	}

	while (result.size() > 1 && result.back() == 0) {
		result.pop_back();
	}

	*this = BigNum(result, negative != other.negative);

	return *this;
}

BigNum BigNum::operator* (const int& other) const {
	BigNum temp = *this;
	temp *= other;

	return temp;
}

BigNum& BigNum::operator*= (const int& other) {
	int temp = (other < 0) ? -other : other;
	int carry = 0;

	for (int i = 0; i < number.size(); i++) {
		int mult = number[i] * temp + carry;
		number[i] = mult % 10;
		carry = mult / 10;
	}

	while (carry) {
		number.push_back(carry % 10);
		carry /= 10;
	}

	negative = (other < 0) != negative;

	return *this;
}


bool BigNum::operator< (const BigNum& other) const {
	if (negative == other.negative) {
		if (negative) {
			return (-*this > -other);
		} else {
			if (number.size() == other.number.size()) {
				for (int i = number.size() - 1; i >= 0; i--) {
					if (number[i] < other.number[i]) {
						return true;
					}
					if (number[i] > other.number[i]) {
						return false;
					}
				}
				return false;
			} else {
				return number.size() < other.number.size();
			}
		}
	} else {
		return negative;
	}
}

bool BigNum::operator> (const BigNum& other) const {
	return !(*this < other) && !(*this == other);
}

bool BigNum::operator== (const BigNum& other) const {
	if (negative == other.negative && number.size() == other.number.size()) {
		for (int i = 0; i < number.size(); i++) {
			if (number[i] != other.number[i]) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

bool BigNum::operator<= (const BigNum& other) const {
	return !(*this > other);
}

bool BigNum::operator>= (const BigNum& other) const {
	return !(*this < other);
}



BigNum BigNum::operator- () const {
	BigNum temp = *this;
	temp.negative = !temp.negative;

	return temp;
}


std::istream& operator>> (std::istream& is, BigNum& a){
	std::string temp;
	is >> temp;

	a.negative = (temp[0] == '-') ? true : false;
	a.number.clear();

	for (int i = temp.size() - 1; i >= a.negative ? 1 : 0; i--) {
		a.number.push_back(temp[i] - 48);
	}

    return is;
}

std::ostream& operator<< (std::ostream& os, const BigNum& a){
	if (a.negative) {
		os << '-';
	}

    for (int i = a.number.size() - 1; i >= 0; i--) {
        os << a.number[i];
    }

    return os;
}
