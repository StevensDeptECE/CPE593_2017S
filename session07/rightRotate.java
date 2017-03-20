void rightRotate(Node n, Node p, Node g) {
	if (n == parent.left)
		parent.left = p;
	else
		parent.right = p;
	Node temp = p.right;
	p.right = g;
	g.left = temp;
}
