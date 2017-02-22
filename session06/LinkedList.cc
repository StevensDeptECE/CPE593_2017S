#include <iostream>
using namespace std;


class LinkedList {
private:
	struct Node {
    int val;
		Node* next;
	};
	Node* head;
	int count;
	void copy(const LinkedList&orig) {
				if (orig.head == nullptr) {
			head = nullptr;
			return;
		}

		head = new Node();
		head->val = orig.head->val;
		// we got at least one....
		Node*q = head;
		for (Node* p = orig.head->next; p != nullptr; p=p->next) {
			Node* temp = new Node();
			temp->val = p->val;
			q->next = temp;
			q = temp;
		}
		q->next = nullptr;
	}
	void clear() {
		Node* q;
		for (Node* p = head; p != nullptr; p = q) {
			q = p->next;  // NOTE: Never look at memory after deleting
			delete p;
		}
	}
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() {
		clear();
	}

	// if you don't want to write copy constructor, at least write this!
	// this way, you will get a link error rather than crashing
	//	LinkedList(const LinkedList& orig);
	//LinkedList& operator =(const LinkedList& orig) {
	
#if 0
	LinkedList(const LinkedList& orig);
	LinkedList& operator =(const LinkedList& orig);
	// O(n^2) horrible implementation
	LinkedList(const LinkedList& orig) : head(nullptr), count(0) {
    for (int i = 0; i < orig.size(); i++)
			addEnd(orig.get(i));
	}
#endif
	LinkedList(const LinkedList& orig) : head(nullptr), count(0) {
		copy(orig);
	}

	LinkedList& operator =(const LinkedList& orig) {
		if (this != &orig) {
			clear();
			copy(orig);
		}
		return *this;
	}
		
	
	void addStart(int v) { // O(1)
		Node* temp = new Node();
		temp->val = v;
		temp->next = head;
		head = temp;
		count++;
	}
	void removeStart() { //O(1)
		Node* temp = head;
    head = head->next;
		delete temp;
		count--;
	}

	void addEnd(int v) {  //O(n)
		Node * p;
		if (head == nullptr) { //O(1)
			head = new Node();
			head->val = v;
			head->next = nullptr;
			count++;
			return;
		}
		for (p = head; p->next != nullptr; p=p->next) //O(n)
			;
		Node* temp = new Node();
		temp->val = v;
		temp->next = nullptr;
		p->next = temp;
		count++;
	}
  void removeEnd() {
		Node * p;
		if (head == nullptr) { //O(1)
			return;
		}
		if (head->next == nullptr) {
      delete head;
			count--;
			head = nullptr;
		}
		Node* q;
		for (p = head, q = p->next; q->next != nullptr; p = q, q = q->next) //O(n)
			;

		delete q;
		count--;
		p->next = nullptr;
	}
#if 0
	int size() const { //O(n)
    int count = 0;
		for (Node* p = head; p != nullptr; p=p->next) //O(n)
			count++;
		return count;
	}
#endif

	int size() const { return count; }
	int get(int i) const {
		Node* p = head;
		for (int j = 0; j < i; j++)
			p = p->next;
    return p->val;			
	}
#if 0
	// extremely bad implementation n + n^2 + n^2/2 = O(n^2)
	friend ostream&  operator<<(ostream& s, LinkedList list) {
		for (int i = 0; i < list.size(); ++i)
			s << list.get(i);
		return s;
	}
#endif
	
	friend ostream&  operator<<(ostream& s, LinkedList list) { //O(n)
		for (Node* p = list.head; p != nullptr; p = p->next)//O(n)
			s << p->val << ' ';
		return s;
	}
};

int main() {
	LinkedList a;
	for (int i = 0; i < 10; i++)
		a.addEnd(i);
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	a.removeEnd();
	a.removeStart();

	cout << a << '\n';
	
	cout << a.get(5) << '\n';
	LinkedList b;
	b.addEnd(5);
	b = a;
	b = b;
}
