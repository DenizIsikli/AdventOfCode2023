#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>

int main() {
	std::ifstream file("Input3.txt");
	std::string line;

	std::map<char, int> priority = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}, {'A', 27}, {'B', 28}, {'C', 29}, {'D', 30}, {'E', 31}, {'F', 32}, {'G', 33}, {'H', 34}, {'I', 35}, {'J', 36}, {'K', 37}, {'L', 38}, {'M', 39}, {'N', 40}, {'O', 41}, {'P', 42}, {'Q', 43}, {'R', 44}, {'S', 45}, {'T', 46}, {'U', 47}, {'V', 48}, {'W', 49}, {'X', 50}, {'Y', 51}, {'Z', 52}};


	std::vector<std::string> rucksack;
	int priority_sum = 0;

	while(getline(file, line)) {
		rucksack.push_back(line);
	}
	
	for (size_t i = 0; i < rucksack.size(); i += 3) {
		std::set<char> common_chars;
		std::set<char> checked_chars;

		for (char ch : rucksack[i]) {
			if ((rucksack[i + 1].find(ch) != std::string::npos && checked_chars.find(ch) == checked_chars.end()) && (rucksack[i + 2].find(ch) != std::string::npos && checked_chars.find(ch) == checked_chars.end())) {
				priority_sum += priority[ch];
				common_chars.insert(ch);
				checked_chars.insert(ch);
			}
		}
	}

	std::cout << priority_sum << std::endl;
}

