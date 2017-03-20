public class OrderedBinaryTree {
	private static class Node {
    Node left, right;
		int val;

		Node(int v, Node left, Node right) {
			val = v; this.left = left; this.right = right;
		}
		Node(int v) {
			val = v; left = right = null;
		}
		public void inorder() {
			if (left != null)
				left.inorder();
			System.out.print(val + " ");
			if (right != null)
				right.inorder();
		}

		public void preorder() {
			System.out.print(val + " ");
			if (left != null)
				left.preorder();
			if (right != null)
				right.preorder();
		}

		public void postorder() {
			if (left != null)
				left.postorder();
			if (right != null)
				right.postorder();
			System.out.print(val + " ");
		}
	}

  Node root;	
	public OrderedBinaryTree() {
		root = null;
	}
	
	public void add(int v) {
		if (root == null) {
			root = new Node(v);
			return;
		}
		Node p = root; // p definitely not null
		while (true) {
			if (v < p.val) {
				if (p.left == null) {
					p.left = new Node(v);
					return;
				}
				p = p.left;
			} else {
				if (p.right == null) {
					p.right = new Node(v);
					return;
				}
				p = p.right;
			}
		}
	}

	public void inorder() {
    root.inorder();
	}

	public void preorder() {
    root.preorder();
	}

	public void postorder() {
    root.postorder();
	}
  public static void main(String[] args) {
		OrderedBinaryTree obt = new OrderedBinaryTree();
		int a[] = { 5, 3, 9, 1, 2, 11, 7, 8};
		for (int i = 0; i < a.length; i++)
			obt.add(a[i]);
		obt.inorder();
		System.out.println("\n\n");
		obt.preorder();
		System.out.println("\n\n");
		obt.postorder();
		System.out.println("\n\n");
	}
}
