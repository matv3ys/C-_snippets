#include <iostream> // /usr/include/c++/11/iostream
#include <vector>

int a = 5; // global int in global scope

void f(int x);

class C; //declaration of class
struct S; //declaration of struct
union U; //declaration of union

//declaration of namespace, not working without {}
//namespace нужны для удобства на больших проектах, где могут пересекаться имена
namespace N {
	int x = 3;
}

namespace N {
	int y = 20;
}

namespace P {
	int b = 10;
}

namespace NN {
	int y = 21;
}

//Можно и так
namespace std {
//	hash_for_T(); // хэш функция для пользовательского типа, чтобы можно было использовать в unordered_map
}

// using namespase N; n3 или так
// сверху вынос всех имен из N в глобальную область видимости

// в c++ используем using а не typedef 

int main() {

	int a = 3;
	std::cout << ::a << " " << a << "\n"; // 5 3  (::a for global a)


	using std::cout;
	// using std::cin, std::cout; (через запятую начиная с c++17)
	cout << N::x << '\n';
	//n0 Или вносим x в текущий scope
	using N::x; //n1 так
	// using namespace N; n2 или так
	cout << x << '\n';
    
	{
		using namespace P;
		cout << b << '\n';
	}
	// std::cout << b << '\n'; уже не сработает
    
	// vi is alias for std::vector<int>
	using vi = std::vector<int>;
   
    int c = 4;
	{
		int c = 5;
		cout << c << "\n"; // 5
	}
	cout << c << "\n"; // 4

    // using namespace N;
	// using namespace NN;
	// cout << y << "\n";  error: reference to 'y' is ambigious
	using N::y;
	using namespace NN;
	cout << y << "\n"; // 20

    int d = d; // корректно с точки зрения компиляции, но не с точки зрения рантайма
	// 1) int d - объявление, в d попадет какое-то значение
	// 2) int d = d; // это же самое значение d вновь присвоится
	// Но использование неиницализированных переменных (а это как раз происходит в пункте 2) это UB
	cout << d << "\n";

}
