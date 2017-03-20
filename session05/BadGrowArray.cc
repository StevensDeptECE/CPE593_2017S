class BadGrowArray {
private:
	int size;
	int* data;
public:
  BadGrowArray() : size(0), data(nullptr) {}
	~BadGrowArray() { delete [] data; }
	void addEnd(int v) { //O(size)
		int* temp = data;
		data = new int[size+1];// allocate one more space
		for (int i = 0; i < size; ++i) // copy the old values
			data[i] = temp[i];
		data[size++] = v; // add the new value to the list, and increase the size
		delete [] temp;
	}
	void addStart(int v) { //O( size )
		int* temp = data;
		data = new int[size+1];// allocate one more space
		data[0] = v;
		for (int i = 0; i < size; ++i) // copy the old values
			data[i+1] = temp[i];
		size++;
		delete [] temp;
	}
	void removeEnd() { //O(size)
		int* temp = data;
		data = new int[--size];
		for (int i = 0; i < size; ++i)
			data[i] = temp[i];
		delete [] temp;
	}
	void removeEnd2() { //O(1)
		size--;
	}
	void removeStart() { //O(size)
		int* temp = data;
		data = new int[--size];
    for (int i = 0; i < size; ++i)
			data[i] = temp[i+1];
		delete [] temp;
	}
	int get(int i) const {
		return data[i];
	}
	int operator [](int i) const { //O(1)
		return data[i];
	}
	int& operator [](int i)  {//O(1)
		return data[i];
	}
	friend ostream& operator <<(ostream&s, const BadGrowArray& a) {
		for (int i = 0; i < a.size; ++i)
			s << a[i] << ' ';
		return s;
	}
};

int main() {
	BadGrowArray a;
	for (int i = 0; i < 10; i++)
		a.addEnd(i);

	cout << a << '\n';
}
