class LinkedList {
private:
	class Node {
    int val;
		Node* next;
		Node(int v, Node* n) : val(v), next(n) {}
	};

	Node* head;
	Node* tail;
public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	
	void addStart(int v) {
		head = new Node(v, head);
		if (tail == nullptr)
			tail = head;
	}
	void addEnd(int v) {
		if (tail == nullptr) {
			head = tail = new Node(v, nullptr);
			return;
		}
		tail = tail->next = new Node(v, nullptr);
	}
	int removeStart() {
		Node* temp = head;
		int val = temp->val;
		head = head->next;
		delete temp;
		return val;
	}
	bool isEmpty() const {
		return head == nullptr;
	}
};

class Queue {
private:
	LinkedList impl;
public:
	Queue() : impl() {}

  void enqueue(int v) {
		impl.addEnd(v);
	}

	int dequeue() {
		return impl.removeStart();
	}
	bool isEmpty() const {
		return impl.isEmpty();
	}
}
