import java.util.Random;

public class Insertionsort {
	private static Random r = new Random(0);
	public static void insertionSort(int[] x) {
		for (int i = 1; i < x.length; ++i) {
			// insert x[i] into the list before it into the correct location



		}
	}

	// fill an array of n elements with value from 0 to m
	public static void randomArray(int[] x, int m) {
		for (int i = 0; i < x.length; ++i) {
			x[i] = r.nextInt(m);
		}
	}

	public static void print(int[] x) {
		for (int i = 0; i < x.length; ++i)
			System.out.print(x[i] + " ");
		System.out.println();
	}

	public static void main(String [] args) {
		final int n = 10;
		int []x  = new int[n];
		randomArray(x, n);
		print(x);
		insertionSort(x);
		print(x);
	}
}
