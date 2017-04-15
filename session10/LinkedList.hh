class LinkedList {
private:
	class Node {
	public:
		int val;
		Node* next;
	};

	Node* head;
	Node* tail;
public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	~LinkedList() {
		Node* q;
		for (Node* p = head; p != nullptr; p = q) {
			q = p->next;
			delete p;
		}
	}
	
	void addLast(int v) {
    if (head == nullptr ) {
			head = tail = new Node(v, nullptr);
			return;
		}
		
		tail->next = new Node(v, nullptr);
		tail = tail->next;
	}
