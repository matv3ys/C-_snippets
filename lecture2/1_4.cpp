#include <iostream>

int main() {
	int x, y, z;

    y = 2;
	z = 3;

	(x = y) = z;  // x = y returns lvalue (x)
	
	std::cout << x << "\n";
}
