/**
 * Generic Binary Search Tree data structure.
 *
 * Rules:
 *   - Each node can have up to 2 children.
 *   - Every left child node must have a smaller value than the parent node.
 *   - Every right child node must have a greater value than the parent node.
 *   - All values in the BinarySearchTree must be unique.
 *   - General tree rules also apply.
 */
public class BinarySearchTree<T> extends Comparable<T>> {
	private BinaryTree<T> tree;
	private int size;

	public BinarySearchTree() {
		this.tree = new BinaryTree<T>();
		this.size = 0;
	}

	public BinaryTree<T> getTree() {
		return tree;
	}

	public boolean isEmpty() {
		return this.tree.isEmpty();
	}

	public int size() {
		return this.size;
	}

	public BinaryTree<T> search(final T key) {
		if (isEmpty()) return null;

		BinaryTree<T> t = tree;

		while (t != null) {
			final int c = key.compareTo(t.getData());
			if (c < 0) t = t.getLeft();
			else if (c > 0) t = t.getRight();
			else return t;
		}

		return null;
	}

	public void insert(final T item) {
		final BinaryTree<T> newNode = new BinaryTree<T>();
		newNode.setData(item);

		if (this.size == 0) {
			this.tree = newNode;
			this.size++;
			return;
		}

		BinaryTree<T> t = tree;
		boolean done = false;

		while (!done) {
			int c = item.compareTo(t.getData());
			if (c == 0) {
				System.out.println("Duplicate key. Can't insert");
				return;
			}
			else if (c < 0) {
				// go left
				if (t.getLeft() == null) {
					// place to insert has been found
					t.setLeft(newNode);
					newNode.setParent(t);
					done = true;
				} else {
					t = t.getLeft();
				}
			}
			else {
				// go right
				if (t.getRight() == null) {
					// place to insert has been found
					t.setRight(newNode);
					newNode.setParent(t);
					done = true;
				} else {
					t = t.getRight();
				}
			}
		}

		this.size++;
	}

	public BinaryTree<T> findPredecessor(final BinaryTree<T> node) {
		if (node == null || node.getLeft() == null) return null;

		BinaryTree<T> pred = node.getLeft();

		while (pred.getRight() != null) {
			pred = pred.getRight();
		}

		return pred;
	}

	private void deleteHere(final BinaryTree<T> deleteNode, final BinaryTree<T> attach) {
		if (deleteNode == null) return;

		final BinaryTree<T> parent = deleteNode.getParent();

		if (parent == null) return;

		if (attach == null) {
			if (parent.getLeft() == deleteNode)
				parent.setLeft(null);
			else
				parent.setRight(null);
			return;
		}

		if (deleteNode == parent.getRight()) {
			parent.detachRight();
			attach.setParent(parent);
			parent.attachRight(attach);
		} else {
			parent.detachLeft();
			attach.setParent(parent);
			parent.attachLeft(attach);
		}

		deleteNode.clear();
	}

	public void delete(final T key) {
		if (this.size == 0) {
			System.out.println("Can't delete. Empty tree");
			return;
		}

		BinaryTree<T> deleteNode = search(key);

		if (deleteNode == null) {
			System.out.println("Key not found. Can't delete");
			return;
		}

		BinaryTree<T> hold = null;

		if (deleteNode.getLeft() == null && deleteNode.getRight() == null) {
			deleteHere(deleteNode, null);
		} else if (deleteNode.getLeft() == null) {
			hold = deleteNode.getRight();
			deleteHere(deleteNode, hold);
		} else if (deleteNode.getRight() == null) {
			hold = deleteNode.getLeft();
			deleteHere(deleteNode, hold);
		} else {
			hold = findPredecessor(deleteNode);
			deleteNode.setData(hold.getData());
			deleteNode = hold;
			deleteHere(deleteNode, deleteNode.getLeft());
		}

		this.size--;
	}

	/**
	 * returns the rightmost node
	 */
	public T findMax() {
		if (isEmpty()) return null;

		BinaryTree<T> t = tree;

		while (t.getRight() != null) {
			t = t.getRight();
		}

		return t.getData();
	}

	/**
	 * returns the leftmost node
	 */
	public T findMin() {
		if (isEmpty()) return null;

		BinaryTree<T> t = tree;

		while (t.getLeft() != null) {
			t = t.getLeft();
		}

		return t.getData();
	}

	/**
	 * driver method
	 */
	public BinaryTree<T> recursiveSearch(final T key) {
		if (tree.isEmpty()) return null;
		return recursiveSearch(this.tree, key);
	}

	public BinaryTree<T> recursiveSearch(final BinaryTree<T> t, final T key) {
		final int c = key.compareTo(t.getData());

		if (c == 0)
			return t;
		else if (c < 0)
			return recursiveSearch(t.getLeft(), key);
		else
			return recursiveSearch(t.getRight(), key);
	}

	/**
	 * Determines if the given tree is a binary search tree
	 */
	public boolean isBinarySearchTree(final BinaryTree<T> t, final T min, final T max) {
		if (t.getData() == null) {
			// base case
			return true;
		} else if (
			t.getData().compareTo(min) > 0 &&
			t.getData().compareTo(max) < 0 &&
			isBinarySearchTree(t.getLeft(), min, t.getData()) &&
			isBinarySearchTree(t.getRight(), t.getData(), max)
		) {
			// min and max sets the limits of each child-node
			return true;
		} else {
			return false;
		}
	}

	/**
	 * Driver method
	 */
	public static <T> int inorder(final BinaryTree<T> t, T[] a, int i) {
		if (t == null) {
			// base case
			return i;
		}
		i = inorder(t.getLeft(), a, i);
		a[i] = t.getData();
		i = inorder(t.getRight(), a, i +1);

		return i;
	}

	// public BinarySearchTree<T> merge(BinarySearchTree<T> t1, BinarySearchTree<T> t2) {
		// TODO: Implement this function.
	// }

	// simple demo
	public static void main(String... args) {
		final BinarySearchTree<Integer> tree = new BinarySearchTree<>();

		tree.insert(5);
		tree.insert(2);
		tree.insert(3);
		tree.insert(1);
		tree.insert(9);
		tree.insert(7);
		tree.insert(8);

		// TODO: test delete, search, inorder, and merge methods
	}
}
