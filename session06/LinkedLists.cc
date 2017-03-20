class LinkedList1 {
private:
	class Node {
		int val;
		Node* next;
	};
	Node* head;
	void addEnd(int v); // O(n)
	void addStart(int v); // O(1)
	void removeEnd(); //O(n)
	void removeStart(); //O(1)
};

class LinkedList2 {
private:
	class Node {
		int val;
		Node* next;
	};
	Node* head;
	Node* tail;
	void addEnd(int v); // O(??)
	void addStart(int v); // O(1)
	void removeEnd(); //O(??)
	void removeStart(); //O(1)
};

class LinkedList3 {
private:
	class Node {
		int val;
		Node* next;
		Node* prev;
	};
	Node* head;
};

class LinkedList4 {
private:
	class Node {
		int val;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
};

class LinkedList5 {
private:
	class Node {
		int val;
		Node* next;
		Node* prev;
	};
	Node* head; // tail is head->prev
};
