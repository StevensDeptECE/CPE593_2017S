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
public class MagicSquare {
	private int n;
	private int N;
	private int[] m;
	private int rowSum, colSum;
	private void swap(int i, int j) {
		int t = m[i]; m[i] = m[j]; m[j] = t;
	}
	public MagicSquare(int n) {
		this.n = n;
		N = n*n;
		m = new int[N];
		for (int i = 0; i < N; i++)
			m[i] = i+1;
		rowSum = N*(N+1)/2 / n;
		colSum = rowSum;
		generate(0);
	}
	public boolean checkRowCondition(int r) {
		int sum = 0;
		for (int i = r; i < r + n; i++)
			sum += m[i];
		return sum == rowSum;
	}

	public void doit() {
		// check if the sum of rows is acceptable
		for (int i = 0; i < N; i+= n) {
			int sum = 0;
			for (int j = i; j < i+n; j++)
				sum += m[j];
			if (sum != rowSum)
				return;
		}

		// check if the sum of cols is acceptable
		for (int i = 0; i < n; i++){
			int cSum = 0;
			for (int j = i; j < N; j += n)
				cSum += m[j];
			if (cSum != colSum)
				return;
		}

		int diag1 = 0, diag2 = 0;
		for (int i = 0, c = 0, d = n-1; i < n; i++, c += n+1, d += n-1) {
			diag1 += m[c];
			diag2 += m[d];
		}
		if (diag1 != rowSum || diag2 != rowSum)
			return;
		for (int i = 0, c = 0; i < n; i++) {
			
			for (int j = 0; j < n; j++, c++) {
				System.out.print(m[c] + "\t");
			}
			System.out.println();
		}
		System.out.println("\n");
	}
	
	public void generate(int r) {
		if (r == N) {
			doit();
			return;
		}
		for (int c = 0; c < N; c++)	{
			swap(c, N-1); generate(r+1); swap(c, N-1);
		}
		
		//		if (!checkRowCondition(r))
		//			return;

	}

	public static void main(String[] args) {
		MagicSquare m = new MagicSquare(3);

	}
}
