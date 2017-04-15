public class Backtrack2 {
	private char[] p;
	
	public Backtrack2(int n) {
		p = new char[n];
		for (int i = 0; i < n; i++)
			p[i] = (char)('A' + i);
		generate(n);
	}

	private void doit() {
		System.out.println(new String(p));
	}
	private void swap(int i, int j) {
		char temp = p[i]; p[i] = p[j]; p[j] = temp;
	}
	public void generate(int n) {
    if (n == 0) {
			doit();
			return;
		}
		for (int i = 0; i < n; i++) {
			swap(i, n-1);
			generate(n-1);
			swap(i, n-1);
		}
	}
	public static void main(String[] args) {
		Backtrack2 b = new Backtrack2(4);
	}		
}
