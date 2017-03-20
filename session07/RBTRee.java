public class RBTree {
	private static class Node {
		Node left;
		Node right;
		Node parent;
		int val;
		boolean red;
		Node(int v, Node p, Node L, Node R, bool red) {
			val = v;
			parent = p;
			left = L;
			right = R;
			this.red = red;
		}
		Node(int v, Node p, Node L, Node R) {
			return this(v, p, L, R, true);
		}
		Node grandparent() {
			if (parent != null)
				return parent.parent;
		}

		Node uncle() {
			Node g = grandparent();
			if (g == null)
				return null;
			if (parent == g.right)
				return g.left;
			else
				return g.right;
		}
	  static void redBlack(RBTree tree, Node n) {
			if (n.parent == null) {
				//TODO: is this test necessary?
				n.red = false;
				return;
			}
			if (n.parent.red == false)
				return;
			// your parent is RED
			Node g = n.grandparent();
			Node u = n.uncle();
			if (u != null && u.red) {
				n.parent.red = false;
				u.red = false;
				g.red = true;
				redBlack(g);
				return;
			}
			if ((n == parent.right) && (parent == g.left)) {
				parent.rotateLeft();
				n = n.left;
				return;
			} else if ((n == parent.left) && (parent == g.right)) {
				parent.rotateRight();
				n = n.right; 
				return;
			}
			parent.red = false;
			g.red = true;
			if (n == parent.left) {
				g.rotateRight();
			} else
				g.rotateLeft();
		}
		
		static void rotateRight(RBTree tree, Node g) {
			Node p = n.parent;
			if (g.parent == null)
				tree.root = p;
			else {
				if (n == parent.left)
					parent.left = p;
				else
					parent.right = p;
				p.red = false;
				Node temp = p.right;
				p.right = n.right;
				left = temp;
			}
			
		}
	}
			
	private Node root;

	public void add(int v) {
		if (root == null) {
			root = new Node(v, null, null, null, false);
			return;
		}
		Node p = root;
		while (true) {
			if (v > p.val) {
				if (p.right == null) {
					p.right = new Node(v, p, null, null);
					p.right.redBlack();
					return;
				}
				p = p.right;
			} else {
				if (p.left == null) {
					p.left = new Node(v, p, null, null);
					p.left.redBlack();
					return;
				}
			}
		}
	}

	}
}
