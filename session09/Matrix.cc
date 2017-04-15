class Matrix {
private:
	int rows, cols;
	double* m;
	// this one doesn't initialize, you had better know what you are doing!!!
	Matrix(int r, int c, char*) : rows(r), cols(c), m(new double[r*c]) {
	}
public:
  Matrix(int r, int c, double val = 0) : rows(r), cols(c),
																				 m(new double[rows*cols]) {
		for (int i = 0; i < rows*cols; ++i)
			m[i] = val;
	}

	~Matrix() {
		delete [] m;
	}
	Matrix(const Matrix& orig);
	Matrix& operator =(const Matrix& orig);
  Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
		orig.m = nullptr;
	}
	
	friend Matrix operator + (const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			throw "Bad size";
    Matrix ans(a.rows, a.cols, "internal");
#if 0
		// slow way, thinking like a rectangle
		for (int i = 0; i < a.rows; ++i)
			for (int j = 0; j < a.cols; ++j)
				ans.m[i*cols+j] = a.m[i*cols+j] + b.m[i*cols+j];
#endif
		//faster (just a bit) linearizing
		for (int i = 0; i < a.rows*a.cols; ++i)
			ans.m[i] = a.m[i] + b.m[i];

		return ans;
	}

};

int main() {
	Matrix m1(3,4, 1);
	Matrix m2(3,4, 2);
	Matrix m3 = m1 + m2;
										
