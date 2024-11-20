#include <iostream>
#include <set>

void print_set(std::set<int> &s) {
	for (auto &elem: s) {
		std::cout << std::to_string(elem) << " ";
	}
	std::cout << "\n";
}

int main() {
	std::set<int> s;
	s.insert(2);
	s.insert(2);
	s.insert(4);
	s.insert(-1);
	print_set(s);
	auto it = s.find(3);
	if (it == s.end()) {
		std::cout << "Not found\n";
	}
	s.erase(4);
	print_set(s);
}
