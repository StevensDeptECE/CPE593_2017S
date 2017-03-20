public class LinkedListCopy implements Cloneable {
	private static class Node { // LinkedList.Node
    int val;
		Node next;
		Node(int v, Node n) { val = v; next = n; }
	}
	private Node head;
	public LinkedList() {
		head = null;
	}

	public Object clone() {
		LinkedList copy = new LinkedList();
		if (head == null)
			return copy;
		copy.head = new Node(head.val, null);
		if (head.next == null) {
			return copy;
		}
    Node q = copy.head;			
		for (Node p = head.next; p != null; p = p.next, q = q.next)
			q.next = new Node(p.val, null);
		return copy;
	}
	public void addStart(int v) { // O(1)
		head = new Node(v, head);
	}

	public void addEnd(int v) {  //O(n)
		if (head == null) { //O(1)
			head = new Node(v, null);
			return;
		}
		Node p;
		for (p = head; p.next != null; p = p.next) //O(n)
			;
		p.next = new Node(v, null);
	}
	public int get(int i) {
		Node p = head;
		for (int j = 0; j < i; j++)
			p = p.next;
    return p.val;			
	}

	public String toString() {
		// make sure this isn't O(n^2)
		StringBuilder b = new StringBuilder();
		
		for (Node p = head; p != null; p = p.next)
			b.append(p.val).append(' ');
		return b.toString();
	}

	public static void main(String[] args) {
		LinkedListCopy a = new LinkedListCopy();
		LinkedListCopy b = a.clone();
	}
	
}

