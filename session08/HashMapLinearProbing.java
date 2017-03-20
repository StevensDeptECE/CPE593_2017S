import java.io.*;
import java.util.*;

public class HashMapLinearProbing {
	//  private String[] keys;
	//	private int values[];
	
	private static class Node {
		String key;
		int val;
		Node(String k, int v) { key = k; val = v; }
	}
	private Node[] table;
  private int used;
	private int[] hist;
	private final int hash(String word) {
		int sum = word.length();
		for (int i = 0; i < word.length(); i++)
			sum = sum << 13 + sum << 3 + word.charAt(i) + sum >> 17;
		return sum & (table.length-1);
	}
	private void grow() {
		// double in size, reinsert all elements
	}
	public HashMapLinearProbing(int initialSize) {
		table = new Node[initialSize];
		used = 0;
		hist = new int[12];
	}
	
	public void load(String filename) throws Exception {
		FileReader r = new FileReader(filename);
		Scanner s = new Scanner(r);
		int count = 0;
		while (s.hasNext()) {
			String word = s.next();
			add(word, count++);
		}
		s.close();
	}

	public void add(String word, int v) {
		if (2*used >= table.length)
			grow();
		int pos = hash(word);
		int count = 1;
		while (table[pos] != null) {
			if (table[pos].key.equals(word)) {
				table[pos].val = v;
				if (count > 11)
					count = 11;
				hist[count]++;
				return;
			}
			count++;
			pos++;
			if (pos >= table.length)
				pos = 0;
		}
		// guaranteed that table[pos].key == null
		used++;
		table[pos] = new Node(word, v);
		if(count > 11)
			count = 11;
		hist[count]++;
	}

	public boolean contains(String word) {
		int pos = hash(word);
		while (table[pos] != null) {
			if (table[pos].key.equals(word))
				return true;
			pos++;
			if (pos >= table.length)
				pos = 0;
		}
		return false;
	}
	public void printHist() {
		for (int i = 1; i < 12; i++) {
			System.out.println(i + "\t" + hist[i]);
		}
	}
	
	public static void main(String[] args) throws Exception {
		HashMapLinearProbing m = new HashMapLinearProbing(1000);
		m.load("dict.dat");
		//	m.load("c++keywords.dat");
		/*
				Integer v = m.get("cat");
		if (v != nullptr) {
			cout << v.intValue() << '\n';
		}
		*/
		System.out.println(m.contains("cat"));
		System.out.println(m.contains("dogh"));
		m.printHist();
	}
}
