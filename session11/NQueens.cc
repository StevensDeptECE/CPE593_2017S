#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NQueens {
private:
	vector<int> queens;
	bool test(int n) {
		int nqueen = abs(queens[n-1] - (n-1));
		for (int i = n-1; i < queens.size()-1; i++) {
			int iqueen = abs(queens[i] - i);
			if (nqueen == iqueen)
				return true;
		}
		if (n > 0)
			return false; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << (queens[i] == j ? " Q " : " + ");
			cout << '\n';
		}
		return true;
	}
public:
	NQueens(int n) : queens() {
		for (int i = 0; i < n; i++)
			queens.push_back(i);
		generate(n);
	}

	void generate(int n) {
		if (test(n)) return;
		for (int c = 0; c < n; c++) {
			generate(n-1);
			swap(queens[n % 2 != 0 ? 0 : c], queens[n-1]);
		}
	}
};

int main() {
	NQueens q(4);
}
			
