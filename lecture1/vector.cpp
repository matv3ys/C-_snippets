#include <iostream>
#include <vector>
#include <string>

std::string print_vect(std::vector<int> &v) {
	std::string res;
	for (auto &elem: v) {
		res += std::to_string(elem) + ' ';
	}
	return res;
}

void print_info(std::vector<int> &v) {
	std::cout << v.size() << " | " << v.capacity() << "\n";
	std::cout << print_vect(v) << '\n';
}

int main() {
	std::vector<int> v;
	
	v.push_back(1);
	print_info(v);
	v.push_back(3);
	print_info(v);
	v.resize(7, 8);
	print_info(v);
	v.reserve(20);
	print_info(v);
	v.resize(4);
	print_info(v);
	v.shrink_to_fit();
	print_info(v);
	v.clear();
	print_info(v);
	v.shrink_to_fit();
	print_info(v);
}

/*
1 | 1
1
2 | 2
1 3
7 | 7
1 3 8 8 8 8 8
7 | 20
1 3 8 8 8 8 8
4 | 20
1 3 8 8
4 | 4
1 3 8 8
0 | 4

0 | 0

*/

