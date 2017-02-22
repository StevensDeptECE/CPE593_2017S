public class GrowArray {
	private	int used;     // the number of elements in use
	private int[] data; 
	private void grow() {
	}

	public GrowArray( ) { data = null; used = 0; }
	public GrowArray(int initialSize) {
		data = new int[initialSize];
		used = 0;
	}

	public void capacity(int newSize) {

	}
 	public void addEnd(int v) {
		if (used >= capacity)
			grow();
		
	}
	public void addStart(int v) {}
	public void removeEnd() {}
	public void removeStart() {}

	public String toString() {
		// DON'T DO THIS!!!
		String s = "";
		for (int i = 0; i < capacity; ++i)
			s += data[i];
		return s;
	}
	// add the other methods from BadGrowArray
}


