#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x*x - 9; }

typedef double  (*FuncOneVar)(double);

double bisection(FuncOneVar f, double a, double b, double eps) {
	double x;
  double y1 = f(a), y2 = f(b);
	if (y1*y2 > 0)
		throw "Both a and b are positive or negative, FAIL!";
	if (y2 < 0)
		swap(a,b);

	// guarantee that f(a) <0, f(b) >0
	int count = 53;
	do {
		x = (a + b) / 2;
		double y = f(x);
		if (y > 0)
			b = x;
		else if (y < 0)
			a = x;
		else
			return x;
	} while (abs(b - a) > eps & count-- > 0);
  return x;
}
