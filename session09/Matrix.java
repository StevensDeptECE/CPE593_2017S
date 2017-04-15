public class Matrix {
	private double[] m;
	private int rows, cols;

	public Matrix(int r, int c) {
		m = new double[r*c];
		rows = r; cols = c;
	}

	/*
		0 5 0 0
		0 0 0 0
		0 0 0 0



	 */
	public Matrix add(Matrix b) {
		if (b.rows != this.rows || b.cols != this.cols)
			throw new RuntimeException("Bad Size");
		Matrix ans = new Matrix(this.rows, this.cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				ans.m[i*cols+j] = this.m[i*cols+j] + b.m[i*cols+j];
		
    for (int i = 0; i < rows * cols; i++)
			ans.m[i] = m[i] + b.m[i];
	}

	public void set(int i, int j, double v) {
		m[i*cols+j] = v;
	}
	public double get(int i, int j) {
		return m[i*cols+j];
	}
	public static void main(String[] args) {
		Matrix m1 = new Matrix(3,4);
		m1.set(0,1, 5.0);
		Matrix m2 = new Matrix(3,4);
		m2.set(2,0, 2.5);
		Matrix m3 = m1.add(m2); // m1 + m2
		Matrix m4 = Matrix.add(m1,m2);

	}
}
