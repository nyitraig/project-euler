#ifndef BIGNUM_H_
#define BIGNUM_H_

#include <iostream>
#include <vector>
#include <string>

/* problems using this lib:  016, 020, 025
 * TODO: re-implement this whole class
 */

class BigNum {
private:
	std::vector<int> number;
	bool negative;

public:
	BigNum ();
	BigNum (const int&);
	BigNum (const std::string&);
	BigNum (const std::vector<int>&, const bool& = false);
	BigNum (const BigNum&);

	unsigned int num_of_digits () const;
	unsigned int digit_sum () const;

	BigNum fact () const; // TODO
	BigNum pow (const BigNum&) const; // TODO

	BigNum& operator= (const BigNum&);

	BigNum operator+ (const BigNum&) const;
	BigNum& operator+= (const BigNum&);
	BigNum operator+ (const int&) const;
	BigNum& operator+= (const int&);

	BigNum operator- (const BigNum&) const;
	BigNum& operator-= (const BigNum&); // TODO
	BigNum operator- (const int&) const;
	BigNum& operator-= (const int&); // TODO

	BigNum operator* (const BigNum&) const;
	BigNum& operator*= (const BigNum&);
	BigNum operator* (const int&) const;
	BigNum& operator*= (const int&);

	BigNum operator- () const;

	bool operator< (const BigNum&) const;
	bool operator> (const BigNum&) const;
	bool operator== (const BigNum&) const;
	bool operator<= (const BigNum&) const;
	bool operator>= (const BigNum&) const;

	friend std::istream& operator>> (std::istream&, BigNum&);
	friend std::ostream& operator<< (std::ostream&, const BigNum&);
};

std::istream& operator>> (std::istream&, BigNum&);
std::ostream& operator<< (std::ostream&, const BigNum&);


#endif //BIGNUM_H_
