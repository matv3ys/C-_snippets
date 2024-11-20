#include <iostream>
#include <string>

int main() {
	std::string s = "Hello!";
	s[1] = 'h';
	s.at(2) = ' ';
	s.at(3) = 'n';
	s.front() = 'O';
	s.back() = '(';
	s.push_back('!'); 
	std::cout << s << "\n";
}
