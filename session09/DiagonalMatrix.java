public class DiagonalMatrix {
	private double[] m;
	public DiagonalMatrix(int n) {
		m = new double[n];
	}
	void set(int i, int j, double v) {
		if (i != j)
			throw new OutOfBoundsException();
		m[ i] = v;
	}
	double get(int i, int j) {
		if (i != j)
			return 0;
		return m[i];
	}

	
