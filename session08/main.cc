#include "HashMapLinearProbing.hh"

int main() {
	HashMapLinearProbing m(1000);
	//	m.load("dict.dat");
	m.load("c++keywords.dat");
	//	m.put("cat", 1);

	const int* p = m.get("cat");
	if (p != nullptr) {
		cout << *p << '\n';
	}

	cout << m.contains("cat") << '\n';
	cout << m.contains("dogh") << '\n';

	m.printHist();
}
