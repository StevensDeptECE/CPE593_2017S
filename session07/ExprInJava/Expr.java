public interface Expr {
	public double eval();
	public void inorder(StringBuilder b);
	public void preorder(StringBuilder b);
	public void postorder(StringBuilder b);
	public Expr simplify();

	public static void main(String[] args) {
		Expr e1 = new Add(new Const(5.5), new Const(3.5));
		System.out.println(e1.eval());
		StringBuilder b = new StringBuilder();
		e1.inorder(b);
		System.out.println(b);

		b = new StringBuilder();
		Expr e2 = e1.simplify();
		e2.inorder(b);
		System.out.println(b);
		
	}
}

abstract class BinaryOperator implements Expr {
	protected Expr L, R;
	private String op;
	public BinaryOperator(Expr L, Expr R, String op) {
		this.L = L;
		this.R = R;
		this.op = op;
	}
  public void inorder(StringBuilder b) {
		if (L != null)
			L.inorder(b);
		b.append(op);
		if (R != null)
			R.inorder(b);
	}
  public void preorder(StringBuilder b) {
	}

  public void postorder(StringBuilder b) {
	}

}

class Const implements Expr {
	private double val;
	public Const(double v) { val = v; }
	public double eval() { return val; }
	public Expr simplify() { return this; }
	public void inorder(StringBuilder b) { b.append(val); }
	public void preorder(StringBuilder b){ b.append(val); }
	public void postorder(StringBuilder b){ b.append(val); }
}

class Add extends BinaryOperator {
	public Add(Expr L, Expr R) {
		super(L, R, "+");
	}
	public double eval() {
		return L.eval() + R.eval();
	}
	public Expr simplify() {
		if (L instanceof Const && R instanceof Const) {
			return new Const(eval());
		}
		return this;
	}
}
	
	/*
class Mult extends BinaryOperator {
}
class Div extends BinaryOperator {
}
	*/
