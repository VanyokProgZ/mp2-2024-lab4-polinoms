#include "polinome.h"
#if defined(_WIN32)
const char* OS_CLEAR = "cls";
#elif defined(__linux__)
const char* OS_CLEAR = "clear";
#elif defined(__unix__)
const char* OS_CLEAR = "clear";
#endif
#define CLS system(OS_CLEAR)

int main() {
	try {
		while (true) {

			std::string q;
			std::cout << "The polynomials are entered in the following format: 'CXaYbZc + CYbXaZc - ZcYa + C' ->\nC - const, \nX - 'X or x', Y - 'Y or y', Z-'Z or z';\na,b,c - degrees of X Y Z\n\n ";
			std::cout << "what to do?\n1 -> polinome + polinome\n2 -> polinome - polinome\n3 -> polinome * polinome\n4 -> polinome * double\nexit -> exit()\nYour choice: ";
			std::cin >> q;
			if (q == "1") {
				std::cout << "Enter the number of Monoms in first polinome: ";
				size_t sz1, sz2;
				std::cin >> sz1;
				std::cout << "Enter the number of Monoms in second polinome: ";
				std::cin >> sz2;
				Polinome<double> a(sz1), b(sz2);
				std::cout << "Type first polinom: ";
				std::cin >> a;
				std::cout << "Type second polinom: ";
				std::cin >> b;
				std::cout << "Result first + second: " << (a + b) << std::endl;
			}
			else if (q == "2") {
				std::cout << "Enter the number of Monoms in first polinome: ";
				size_t sz1, sz2;
				std::cin >> sz1;
				std::cout << "Enter the number of Monoms in second polinome: ";
				std::cin >> sz2;
				Polinome<double> a(sz1), b(sz2);
				std::cout << "Type first polinom: ";
				std::cin >> a;
				std::cout << "Type second polinom: ";
				std::cin >> b;
				std::cout << "Result first - second: " << (a - b) << std::endl;
			}
			else if (q == "3") {
				std::cout << "Enter the number of Monoms in first polinome: ";
				size_t sz1, sz2;
				std::cin >> sz1;
				std::cout << "Enter the number of Monoms in second polinome: ";
				std::cin >> sz2;
				Polinome<double> a(sz1), b(sz2);
				std::cout << "Type first polinom: ";
				std::cin >> a;
				std::cout << "Type second polinom: ";
				std::cin >> b;
				std::cout << "Result first * second: " << (a * b) << std::endl;
			}
			else if (q == "4") {
				std::cout << "Enter the number of Monoms in first polinome: ";
				size_t sz1;
				std::cin >> sz1;
				Polinome<double> a(sz1);
				double b;
				std::cout << "Type polinom: ";
				std::cin >> a;
				std::cout << "Type const: ";
				std::cin >> b;
				std::cout << "Result polinom * const: " << (a * b) << std::endl;
			}
			else if (q == "exit") {
				return 0;
			}
			else {
				std::cout << "Type something to continue";
				std::cin >> q;
				CLS;
				continue;
			}
			std::cout << "\nType something to continue";
			std::cin >> q;
			CLS;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}