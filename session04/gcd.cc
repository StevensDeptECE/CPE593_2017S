#include <iostream>
using namespace std;

//Euclid's gcd

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


int gcd2(int a, int b) {
	while (b != 0) {
		int temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main() {
	cout << gcd(12, 18) << '\n'; // gcd(18, 12) --> gcd(12, 6) --> gcd(6, 0) = 6
	cout << gcd(3025, 1025) << '\n'; //gcd(1025, 975) --> gcd(975, 50)
	//-->gcd(50,25) --> gcd(25,0)
	cout << gcd2(12, 18) << '\n';
	cout << gcd2(3025, 1025) << '\n';
	cout <<	lcm(12, 18) << '\n'; // lcm(a,b) = a*b / gcd(a,b)
}
	
