#include <iostream>
#include <typeinfo>
#include <string>

template<typename T>
std::string lit_string(T &lit) {
	return std::to_string(lit) + " (" + typeid(lit).name() + ")";
}

int main() {
	float  f = 0.2f;
	double d = 1.2;
	int i = 10;
	unsigned u = 3;

	auto sum_f_d = f + d; 
	std::cout << "f: " << lit_string(f) << "\n";  
	std::cout << "d: " << lit_string(d) << "\n";  
	std::cout << "sum_f_d: " << lit_string(sum_f_d) << "\n";  

	auto sum_u_i = i + u;
	std::cout << "i: " << lit_string(i) << "\n";  
	std::cout << "u: " << lit_string(u) << "\n";  
	std::cout << "sum_u_i: " << lit_string(sum_u_i) << "\n";  
	
	auto diff1_u_i = u - i; // 4294967289  !!!  В остальных все норм. 
	auto diff2_u_i = i - u;
	std::cout << "i: " << lit_string(i) << "\n";  
	std::cout << "u: " << lit_string(u) << "\n";  
	std::cout << "diff1_u_i: " << lit_string(diff1_u_i) << "\n";  
	std::cout << "diff2_u_i: " << lit_string(diff2_u_i) << "\n";  
}
/*
f: 0.200000 (f)
d: 1.200000 (d)
sum_f_d: 1.400000 (d)
i: 10 (i)
u: 3 (j)
sum_u_i: 13 (j)
i: 10 (i)
u: 3 (j)
diff1_u_i: 4294967289 (j)
diff2_u_i: 7 (j) 10 - 3u = 10 + 4294967293 = 7 (4294967303 mod 2^32)  
*/

