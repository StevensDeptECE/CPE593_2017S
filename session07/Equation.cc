#include <iostream>
/*
   2 + 2  ==> +       
             / \
						2   2


2 + (3 * 4) ==>  tree

2 + 2 --> 4

2 * 5 --> 10

x * 0 --> 0
1 * x --> x
-1 * x --> -x

x * 3 + y * 5 - x * 2 --> x + y * 5
*/

class Expr {
public:
  virtual double eval() const = 0;
  virtual Expr* simpl() const = 0;
  virtual void inorder() const = 0;
  virtual void preorder() const = 0;
  virtual void postorder() const = 0;
};

class BinaryOp : public Expr {
private:
  Expr* left;
  Expr* right;
public:
  BinaryOp(Expr* L, Expr* R) : left(L), right(R) {}
};

class Add : public BinaryOp {
public:
  Add(Expr*L, Expr* R) : BinaryOp(L, R) {}
	double eval() const { return left->eval() + right->eval(); }
	void inorder() const {
		if (left != nullptr)
			left->inorder();
		cout << " + ";
		if (right != nullptr)
			right->inorder();
	}

};

class Const : public Expr {
private:
	double v;
public:
	Const(double v) : v(v) {}
	void inorder() const {
		cout << v;
	}
	double eval() const { return v; }
};


int main() {
	Expr* e = new Add(new Const(5), new Const(6));
}

	
