/* Problem 22
 * Using names.txt (right click and 'Save Link/Target As...'),
 * a 46K text file containing over five-thousand first names,
 * begin by sorting it into alphabetical order.
 * Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a name score.
 * For example, when the list is sorted into alphabetical order,
 * COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
 * So, COLIN would obtain a score of 938 × 53 = 49714.
 * What is the total of all the name scores in the file?
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

unsigned int value (const std::string& str) {
	unsigned int result = 0;
	for (int i = 0; i < str.size(); i++) {
		result += str[i] - 'A' + 1;
	}
	return result;
}

int main () {
	unsigned int result = 0;
	std::vector<std::string> names;
	char temp[50], name[50];

	std::ifstream ifs("./022/p022_names.txt", std::ifstream::binary);
	if (!ifs.is_open()) {
		std::cout << "Can't open file";
		return 1;
	}
	while(ifs.getline(temp, 50, '"') && ifs.getline(name, 50, '"'))
		names.push_back(name);
	ifs.close();

	std::sort(names.begin(), names.end());

	for (int i = 0; i < names.size(); i++)
		result += value(names[i]) * (i + 1);

	std::cout << result;

	return 0;
}
