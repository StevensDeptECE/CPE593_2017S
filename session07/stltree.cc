#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, double> quote;

	quote["IBM"] = 182.52;
	quote["AAPL"] = 123.56;
	quote["BIDU"] = 125.01;

	for (auto x : quote) {
		cout << x.first << "==>" << x.second << '\n';
	}
}
	
