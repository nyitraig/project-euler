/* Problem 42
 * The nth term of the sequence of triangle numbers is given by, t_n = ½n(n+1);
 * so the first ten triangle numbers are:
 *     1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * By converting each letter in a word to a number corresponding to
 * its alphabetical position and adding these values we form a word value.
 * For example, the word value for SKY is 19 + 11 + 25 = 55 = t_10.
 * If the word value is a triangle number then we shall call the word a triangle word.
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file
 * containing nearly two-thousand common English words, how many are triangle words?
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

int main () {
	unsigned int result = 0;
	std::vector<std::string> words;
	char temp[50], word[50];
	std::set<unsigned int> triangles;
	std::ifstream ifs("./042/p042_words.txt", std::ifstream::binary);
	if (!ifs.is_open()) {
		std::cout << "Can't open file";
		return 1;
	}
	while (ifs.getline(temp, 50, '"') && ifs.getline(word, 50, '"'))
		words.push_back(word);
	ifs.close();
	for (int i = 1; i < 50; i++)
		triangles.insert(i * (i + 1) / 2);
	for (int i = 0; i < words.size(); i++) {
		unsigned int sum = 0;
		for (int j = 0; j < words[i].size(); j++)
			sum += words[i][j] - 'A' + 1;
		if (triangles.count(sum))
			result++;
	}
	std::cout << result;
	return 0;
}
