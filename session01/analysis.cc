#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	double sum = 0;
	for (int i = a; i <= b; i+= 16)   // O(b-a)
		sum += i;

	cout << sum;

	//O(n^2)
	for (int i = 0; i < n; i++)  // O(n)
		for (int j = i; j < n; j++)	// O(n/2)    n  ... 1
			cout << "X";

	// n-1 + n-2 + n-3 + ... + 2 + 1    (n^2 - n) / 2

	//O(n^2)
	for (int i = 0; i < n; i++)  //O(n)
		for (int j = sqrt(i) ; j < i; j++)  // n - sqrt(n)  O(n)
			f();
}
