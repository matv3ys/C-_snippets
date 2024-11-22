#include <iostream>
#include <map>
#include <string>

std::string print_map(std::map<int, int> &m) {
	std::string res;
	for (auto &pair: m) {
		res += std::to_string(pair.first) + " -> " + std::to_string(pair.second) + "\n";
	}
	return res;
}

int main() {
	std::map<int, int> m;
	m[1] = 2;
	m.at(3) = 4;
	std::cout << print_map(m) << "\n";
}
