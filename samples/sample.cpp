#include "polinome.h"

using namespace std;

int main() {

	int n, m; cin >> n >> m;
	Polinome<int> a(n), b(m);
	cin >> a >> b;
	auto c = a + b;
	cout << c << endl;
}