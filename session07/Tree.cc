#include <iostream>
using namespace std;

class OrderedTree {
private:
	class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node(int v, Node* L, Node* R) : val(v), left(L), right(R){}
		void inorder() {
			if (left != nullptr)
				left->inorder();
			cout << val;
			if (right != nullptr)
				right->inorder();
		}

		void preorder() {
			cout << val;
			if (left != nullptr)
				left->preorder();
			if (right != nullptr)
				right->preorder();
		}

		void postorder() { // RPN
			if (left != nullptr)
				left->preorder();
			if (right != nullptr)
				right->preorder();
			cout << val;
		}
	};
	Node* root;
public:
	OrderedTree() : root(nullptr) {}
	void add(int v) {  //O(n)  --> log n if we keep the tree balanced!
		if (root == nullptr) {
			root = new Node(v, nullptr, nullptr);
			return;
		}
		Node* p = root;
		while(true) {
			if (v > p->val) {
				if (p->right == nullptr) {
					p->right = new Node(v, nullptr, nullptr);
					return;
				}
				p = p->right;
			}
			else {
				if (p->left == nullptr) {
					p->left = new Node(v, nullptr, nullptr);
					return;
				}
				p = p->left;
			}
		}
	}
	void inorder() {
		if (root != nullptr)
			root->inorder();
	}

	void preorder() {
		if (root != nullptr)
			root->preorder();
	}

	void postorder() {
		if (root != nullptr)
			root->postorder();
	}
};

int main() {
	OrderedTree a;
	int x[] = {5, 3, 9, 1, 4, 2, 8, 11};
	for (auto y : x) {
		a.add(y);
	}

	a.inorder(); // 1, 2, 3, 4, 5, 8, 9
	cout << "\n\n";
	a.preorder(); //
	cout << "\n\n";
  a.postorder();
	cout << "\n\n";
}


	
