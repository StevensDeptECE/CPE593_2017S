#include <iostream>
using namespace std;

class BadGrowArray {
private:
	int capacity;
	int* data;
public:
	BadGrowArray() : data(nullptr), capacity(0) {}
	~BadGrowArray() {
		delete [] data;
	}
	BadGrowArray(const BadGrowArray& orig) : capacity(orig.capacity),
																					 data(new int[capacity]){
		for (int i = 0; i < capacity; ++i)
			data[i] = orig.data[i];
	}
	BadGrowArray& operator =(const BadGrowArray& orig) {
    if (this != &orig) {		
			delete [] data;
			capacity = orig.capacity;
			data = new int[capacity];
			for (int i = 0; i < capacity; ++i)
				data[i] = orig.data[i];
		}
		return *this;
	}
  void addEnd(int v) { //O(n)
		int* temp = data; //O(1)
		data = new int[capacity+1]; //O(1)
		for (int i = 0; i < capacity; ++i) //O(n)
			data[i] = temp[i];
    data[capacity] = v;
		capacity++;
		delete [] temp;
	}
  void addStart(int v) { //O(n^2)
		int* temp = data; //O(1)
		data = new int[capacity+1]; //O(1)
		data[0] = v;
		for (int i = 0; i < capacity; ++i) //O(n)
			data[i+1] = temp[i];
		capacity++;
		delete [] temp;
	}
	void insert(int i, int val) { //O(n^2)
		int* temp = data; //O(1)
		data = new int[capacity+1]; //O(1)
		for (int j = 0; j < i; ++j)
			data[j] = temp[j];
		data[i] = val;
		for (int j = i + 1; j < capacity; ++j)
			data[j] = temp[j-1];
		capacity++;
		delete [] temp;
	}
	void removeEnd() { //O(n^2)
		int* temp = data;
		data = new int[--capacity];
		for (int i = 0; i < capacity; ++i)
			data[i] = temp[i];
		delete [] temp;
	}
	void removeEnd2() { //O(1)
		--capacity;
	}
	void removeStart() { //O(n^2)
		int* temp = data;
		data = new int[--capacity];
		for (int i = 0; i < capacity; ++i)
			data[i] = temp[i+1];
		delete []temp;
	}
};

void f(BadGrowArray x) {}
	
int main() {
	BadGrowArray b;
	for (int i = 0; i < 1000000; ++i) // 1 + 2 + 3 + ... + n = O(n^2)
		b.addEnd(i);
	BadGrowArray c = b; // copy constructor
	BadGrowArray d(b); // copy constructor
	f(b); //copy consturctor
	d = d;
	d = b;
}
