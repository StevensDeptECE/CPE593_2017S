/*
  n = 3

	1   2   3
  4   5   6
  7   8   9

O(n*n !)

1+2+3 + ... + 9 = 45
sum of all numbers = n*n(n*n+1) / 2
rows = ???  n
sum of a row = n*n(n*n+1)/2 / n = n(n*n+1)/2

3*(3*3+1) / 2 = 15 


 */

void magicSquareBruteForce1() {
	for (int a = 1; a <= 9; a++)
		for (int b = 1; b <= 9; b++) {
			if (a == b)
				continue;
			for (int c = 1; c <= 9; c++) {
				if (c == a || c == b)
					continue;
        if (a + b + c != 15)
					continue;
				for (int d = 1; d <= 9; d++) {
					if (d == a || d == b || d == c)
						continue;
					for (int e = 1; e <= 9; e++) {
						if (e == a || e == b || e == c || e == d)
							continue;
						for (int f = 1; f <= 9; f++) {
							if (f == a || f == b || f == c || f == d || f == e)
								continue;
							if (d + e + f != 15)
								continue;

							for (int g = 1; g <= 9; g++) {
								if (g == a || g == b || g == c || g == d || g == e || g == f)
 									continue;
								if (a + d + g != 15)
									continue;
								for (int h = 1; h <= 9; h++) {
								if (h == a || h == b || h == c || h == d || h == e || h == f || h == g)
 									continue;
								if (b + e + h != 15)
									continue;
								for (int i = 1; i <= 9; i++)
									if (i == a || i == b || i == c || i == d || i == e || i == f ||
											i == g || i == h)
										continue;
								if (c + g + i != 15 || a + e + i != 15 || c + e + g != 15 || g + h + i != 15)
									continue;
								cout
									<< a << '\t' << b << '\t' << c << '\n' <<
									<< d << '\t' << e << '\t' << f << '\n' <<
									<< g << '\t' << h << '\t' << i << '\n';
								}
							}
						}
					}
				}
			}
		}

void magicSquareBruteForce2() {
	const int N = 9;
	for (int a = 1; a <= 9; a++)
		for (int b = 1; b <= 9; b++) {
			if (a == b)
				continue;
			int c = 15 - a - b;
			if (c < 1 || c > N || c == a || c == b)
				continue;
			
			for (int d = 1; d <= 9; d++) {
				if (d == a || d == b || d == c)
					continue;
				for (int e = 1; e <= 9; e++) {
					if (e == a || e == b || e == c || e == d)
						continue;
					int f = 15 - d - e;
					if (f == a || f == b || f == c || f == d || f == e)
						continue;
					if (f < 1 || f > N)
						continue;
					int g = 15 - a - d;
					if (g < 1 || g > N ||g == a || g == b || g == c || g == d || g == e || g == f)
						continue;
					int h = 15 - b - e;
 					if (h < 1 || h > N ||h == a || h == b || h == c || h == d || h == e ||
							h == f || h == g)
						continue;
					int i = 15 - c - f;
					if (i == a || i == b || i == c || i == d || i == e || i == f ||
							i == g || i == h)
						continue;
					if (c + g + i != 15 || a + e + i != 15 || c + e + g != 15 || g + h + i != 15)
						continue;
					cout
						<< a << '\t' << b << '\t' << c << '\n' <<
						<< d << '\t' << e << '\t' << f << '\n' <<
						<< g << '\t' << h << '\t' << i << '\n';
				}
			}
		}


	void magicSquareBruteForce3() {
	const int N = 9;
	const int rowSum = 15, colSum = 15;
	for (int a = 1; a <= 9; a++) {
		int maxB = rowSum - a - 1;
		if (maxB > N)
			maxB = 9;
		for (int b = rowsum - a - 9; b <= maxB; b++) {
			if (a == b)
				continue;
			int c = 15 - a - b;
			if (c < 1 || c > N || c == a || c == b)
				continue;
			int maxD = colSum - a - 1;
			if (maxD > N)
				maxD = 9;
			for (int d = colSum - a - 9; d <= maxD; d++) {
				if (d == a || d == b || d == c)
					continue;
				int maxE = rowSum - d - 1;
				if (maxE > N)
					maxE = 9;
				for (int e = rowSum - d - 9; e <= maxE; e++) {
					if (e == a || e == b || e == c || e == d)
						continue;
					int f = 15 - d - e;
					if (f == a || f == b || f == c || f == d || f == e)
						continue;
					if (f < 1 || f > N)
						continue;
					int g = 15 - a - d;
					if (g < 1 || g > N ||g == a || g == b || g == c || g == d || g == e || g == f)
						continue;
					int h = 15 - b - e;
 					if (h < 1 || h > N ||h == a || h == b || h == c || h == d || h == e ||
							h == f || h == g)
						continue;
					int i = 15 - c - f;
					if (i == a || i == b || i == c || i == d || i == e || i == f ||
							i == g || i == h)
						continue;
					if (c + g + i != 15 || a + e + i != 15 || c + e + g != 15 || g + h + i != 15)
						continue;
					cout
						<< a << '\t' << b << '\t' << c << '\n' <<
						<< d << '\t' << e << '\t' << f << '\n' <<
						<< g << '\t' << h << '\t' << i << '\n';
				}
			}
		}


	
}
