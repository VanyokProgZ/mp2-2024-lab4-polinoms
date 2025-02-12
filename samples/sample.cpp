#include "polinome.h"

using namespace std;

int main() {
	try {
		while (true) {

			string q;
			cout << "The polynomials are entered in the following format: 'CXaYbZc + CYbXaZc - ZcYa + C' ->\nC - const, \nX - 'X or x', Y - 'Y or y', Z-'Z or z';\na,b,c - degrees of X Y Z\n\n ";
			cout << "what to do?\n1 -> polinome + polinome\n2 -> polinome - polinome\n3 -> polinome * polinome\n4 -> polinome * double\nexit -> exit()\nYour choice: ";
			cin >> q;
			if (q == "1") {
				cout << "Enter the number of Monoms in first polinome: ";
				size_t sz1, sz2;
				cin >> sz1;
				cout << "Enter the number of Monoms in second polinome: ";
				cin >> sz2;
				Polinome<double> a(sz1), b(sz2);
				cout << "Type first polinom: ";
				cin >> a;
				cout << "Type second polinom: ";
				cin >> b;
				cout << "Result first + second: " << (a + b) << endl;
			}
			else if (q == "2") {
				cout << "Enter the number of Monoms in first polinome: ";
				size_t sz1, sz2;
				cin >> sz1;
				cout << "Enter the number of Monoms in second polinome: ";
				cin >> sz2;
				Polinome<double> a(sz1), b(sz2);
				cout << "Type first polinom: ";
				cin >> a;
				cout << "Type second polinom: ";
				cin >> b;
				cout << "Result first - second: " << (a - b) << endl;
			}
			else if (q == "3") {
				cout << "Enter the number of Monoms in first polinome: ";
				size_t sz1, sz2;
				cin >> sz1;
				cout << "Enter the number of Monoms in second polinome: ";
				cin >> sz2;
				Polinome<double> a(sz1), b(sz2);
				cout << "Type first polinom: ";
				cin >> a;
				cout << "Type second polinom: ";
				cin >> b;
				cout << "Result first * second: " << (a * b) << endl;
			}
			else if (q == "4") {
				cout << "Enter the number of Monoms in first polinome: ";
				size_t sz1;
				cin >> sz1;
				Polinome<double> a(sz1);
				double b;
				cout << "Type polinom: ";
				cin >> a;
				cout << "Type const: ";
				cin >> b;
				cout << "Result polinom * const: " << (a * b) << endl;
			}
			else if (q == "exit") {
				return 0;
			}
			else {
				continue;
			}

		}
	}
	catch (std::exception& e) {
		cout << e.what() << endl;
	}
}