package Tree;

/**
 * Generic Binary Tree data structure
 */
public class BinaryTree<T> {
	private T data;
	private BinaryTree<T> parent;
	private BinaryTree<T> left;
	private BinaryTree<T> right;

	public BinaryTree() {
		this.parent = null;
		this.left = null;
		this.right = null;
		data = null;
	}

	public void makeRoot(final T data) {
		if (!isEmpty()) {
			System.out.println("Can't make root. Already exists");
		} else {
			this.data = data;
		}
	}

	public void setData(final T data) {
		this.data = data;
	}

	public void setLeft(final BinaryTree<T> tree) {
		this.left = tree;
	}

	public void setRight(final BinaryTree<T> tree) {
		this.right = tree;
	}

	public void setParent(final BinaryTree<T> tree) {
		this.parent = tree;
	}

	public T getData() {
		return this.data;
	}

	public BinaryTree<T> getParent() {
		return this.parent;
	}

	public BinaryTree<T> getLeft() {
		return this.left;
	}

	public BinaryTree<T> getRight() {
		return this.right;
	}

	public void attachLeft(final BinaryTree<T> tree) {
		if (tree == null) return;
		else if (this.left != null || tree.getParent() != null) return;
		
		tree.setParent(this);
		this.setLeft(tree);
	}

	public void attachRight(final BinaryTree<T> tree) {
		if (tree == null) return;
		else if (this.right != null || tree.getParent() != null) return;
		
		tree.setParent(this);
		this.setRight(tree);
	}

	public BinaryTree<T> detachLeft() {
		if (this.isEmpty()) return null;

		final BinaryTree<T> retLeft = this.left;
		this.left = null;

		if (retLeft != null) {
			retLeft.setParent(null);
		}

		return retLeft;
	}

	public BinaryTree<T> detachRight() {
		if (this.isEmpty()) return null;

		final BinaryTree<T> retRight = this.right;
		right = null;

		if (retRight != null) {
			retRight.setParent(null);
		}

		return retRight;
	}

	public boolean isEmpty() {
		return data == null;
	}

	public void clear() {
		this.left = null;
		this.right = null;
		this.parent = null;
		this.data = null;
	}

	public BinaryTree<T> root() {
		if (parent == null) return this;

		BinaryTree<T> next = this.parent;

		while (next.getParent() != null) {
			next = next.getParent();
		}

		return next;
	}

	public static <T> void preorder(final BinaryTree<T> t) {
		if (t == null) return;
		
		System.out.print(t.getData() + "\t");
		preorder(t.getLeft());
		preorder(t.getRight());
	}

	public static <T> void inorder(final BinaryTree<T> t) {
		if (t == null) return;

		inorder(t.getLeft());
		System.out.print(t.getData() + "\t");
		inorder(t.getRight());
	}

	public static <T> void postorder(final BinaryTree<T> t) {
		if (t == null) return;

		postorder(t.getLeft());
		postorder(t.getRight());
		System.out.print(t.getData() + "\t");
	}

	// Simple demo
	public static void main(String[] args) {
		final BinaryTree<String> tree = new BinaryTree<String>();
		final BinaryTree<String> A = new BinaryTree<String>();
		final BinaryTree<String> B = new BinaryTree<String>();
		final BinaryTree<String> C = new BinaryTree<String>();
		final BinaryTree<String> D = new BinaryTree<String>();
		
		A.makeRoot("A");
		B.makeRoot("B");
		C.makeRoot("C");
		D.makeRoot("D");
		
		A.attachLeft(B);
		B.attachLeft(C);
		A.attachRight(D);
		
		System.out.print("Preorder:\t");
		preorder(A);
		System.out.println();
		
		System.out.print("Inorder:\t");
		inorder(A);
		System.out.println();
		
		System.out.print("Postorder:\t");
		postorder(A);
		System.out.println();
	}
}
