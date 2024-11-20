#include <iostream>
#include <string>

int main() {
	std::string s = "Hello!";
	s.front() = 'G';
	std::cout << s.front() << " " << s << "\n";
}
