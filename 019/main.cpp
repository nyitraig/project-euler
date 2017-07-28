/* Problem 19
 * You are given the following information,
 * but you may prefer to do some research for yourself.
 *     1 Jan 1900 was a Monday.
 *     Thirty days has September,
 *     April, June and November.
 *     All the rest have thirty-one,
 *     Saving February alone,
 *     Which has twenty-eight, rain or shine.
 *     And on leap years, twenty-nine.
 *     A leap year occurs on any year evenly divisible by 4,
 *     but not on a century unless it is divisible by 400.
 * How many Sundays fell on the first of the month during
 * the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <iostream>

int main () {
	int c = 2, result = 0; // 1 Jan 1901 was a Tuesday, therefore c = 2
	//                      JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
	const int months[12] = {31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31};

	for (int i = 1901; i <= 2000; i++) {
		const bool isLeapYear = (i % 4 == 0) ? (i % 100 == 0) ? (i % 400 == 0) ? true : false : true : false;
		for (int j = 1; j <= 12; j++) {
			const int days = (j == 2 && isLeapYear) ? 29 : months[j - 1];
			for (int k = 1; k <= days; k++)
				if (c++ % 7 == 0 && k == 1)
					result++;
		}
	}

	std::cout << result;

	return 0;
}
