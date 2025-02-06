#include "list.h"

using namespace std;

signed main() {
	List<int> a = {1,5,3,8,4,5};
	List<int> b = {3,4,5,6,7};
	List<int> c = a;
	c = (a + b);
	c.merge_sort();
	cout <<c<< endl;
	
}