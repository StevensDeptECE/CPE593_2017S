#include <iostream>
using namespace std;



class LinkedList {
private:
	class Node {  // LinkedList::Node
	public:
		int val;
		Node* next;
		//		Node() {}
		Node(int v, Node* n) : val(v), next(n) {}
	};	
	Node* head;
	int count;
public:
	LinkedList() : head(nullptr), count(0) {}
	void addEnd(int v) {
    if (head == nullptr) {
			head = new Node(v, nullptr);
			count++;
			return;
		}
		count++;
		Node* p;
		for (p = head; p->next != nullptr; p = p ->next)
			;
		p->next = new Node(v, nullptr);
	}
	void addStart(int v) { //O(1)
		head =  new Node(v, head);
		count++;
	}
	void removeStart() {		
		Node* temp = head;
		head = head->next;
		delete temp;
		count--;
	}
	void removeEnd() {
		if (head == nullptr)
			return;
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}
		Node* p;
		Node* q;
		for (p = head, q = p->next; q->next != nullptr; p = q, q = q->next)
			;
		delete q;
		p->next = nullptr;
	}
#if 0
	int size() const { //O(n)
		int count = 0;
		for (Node* p = head; p != nullptr; p = p->next)
			count++;
		return count;
	}
#endif
	int get(int i) {
		Node* p = head;
		for (int j = 0; j < i; ++j)
			p = p->next;
		return p->val;
	}
	int size() const { return count; }
#if 0

	// REALLY BAD IMPLEMENTATION
  friend ostream& operator <<(ostream& s, const LinkedList& list) {
		for (int i = 0; i < list.size(); i++)
			cout << list.get(i);
	}
#endif
  friend ostream& operator <<(ostream& s, const LinkedList& list) {
		for (Node* p = list.head; p != nullptr; p=p->next)
			cout << p->val << ' ';
		return s;
	}
	class Iterator {
	private:
		Node* current;
	public:
    Iterator(LinkedList& a) {
			current = a.head;
		}

		bool operator !() const {
			return current != nullptr;
		}

		Iterator& operator ++() {
			current = current->next;
			return *this;
		}

		int& operator*() const {
			return current->val;
		}
	};
};

int main() {
	LinkedList a; // empty list
	for (int i = 0; i < 10; i++)
		a.addEnd(i);
	for (int i = 0; i < 10; i++)
		a.addStart(i);   // 9876543210
  // 98765432100123456789
	a.removeStart();
	a.removeEnd();
	cout << a << '\n';

  for (LinkedList::Iterator i = a; !i; ++i)
		*i += 1;

	cout << a << '\n';

	//	for (LinkedList::const_Iterator i = a; !i; ++i)
	//		cout << *i;
	
}
