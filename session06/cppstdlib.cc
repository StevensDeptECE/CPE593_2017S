#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
	vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);

	list<int> b;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	const vector<int> c = a; // c is an exact copy of a

  for (vector<int>::const_iterator i = c.begin(); i != c.end(); ++i)
		cout << *i << ' ';
	cout << '\n';

	for (vector<int>::iterator i = a.begin(); i != a.end(); ++i)
		*i += 2;
	cout << '\n';

	for (list<int>::iterator i = b.begin(); i != b.end(); ++i)
		*i += 2;
	cout << '\n';

	for (auto x : b) {
		cout << x << ' ';
	}
}
	
	
