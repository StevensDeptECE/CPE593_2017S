#include <iostream>
using namespace std;


//O(n)
//omega(1)
bool isPrimeBF(unsigned long long n) {
	for (unsigned long long i = 2; i < n; i++) // O(n)
		if (n % i == 0)   //O(1)
			return false;   //O(1)
	return true;
}

//  28 = 2 * 14   4 * 7 


//O(sqrt n)
//omega(1)
bool isPrimeBetter(unsigned long long n) {
	for (unsigned long long i = 2; i <= sqrt(n); i++) // O(sqrt n)
		if (n % i == 0)   //O(1)
			return false;   //O(1)
	return true;
}

int main() {
	cout << "Enter n: ";
	unsigned long long n;
	cin >> n;
	cout << isPrime(n);
}
