public class BackTrack {
	private char[] p;

	private void swap(int i, int j) {
		char t = p[i]; p[i] = p[j]; p[j] = t;
	}
	BackTrack(int n) {
		p = new char[n];
		for (int i = 0; i < n; i++)
			p[i] = (char)('A' + i);
		generate(n);
	}

	public void doit() {
		System.out.println(new String(p));
	}
	
	public void generate(int N) {
		if (N == 0)
			doit();
		for (int c = 0; c < N; c++)	{
			swap(c, N-1); generate(N-1); swap(c, N-1);
		}
	}
	public static void main(String[] args) {
		BackTrack b = new BackTrack(4);

	}

}
