class GrowArray {
private:
	int capacity; // the size of the block
	int used;     // the number of elements in use
	int* data;
	void grow() {
		// size = size * 2 + 1
		// double the size
	}
public:
	GrowArray( ) : data(nullptr), capacity(0), used(0) {}
	GrowArray(int initialSize) :
		data(new int[initialSize]), capacity(initialSize), used(0) {}
	~GrowArray() {   write this!!! }
	GrowArray(const GrowArray& orig);
	GrowArray& operator =(const GrowArray& orig);
  void capacity(int newSize) {
	}
	void addEnd(int v) {
		if (used >= capacity)
			grow();
    		
	}
	void addStart(int v) {}
	void removeEnd() {}
	void removeStart() {}

	// add the other methods from BadGrowArray
};

void f(GrowArray x) {

}

int main() {
	GrowArray a(5);
	a.addEnd(2);
	GrowArray b = a; // copy constructor
  f(a);
}
