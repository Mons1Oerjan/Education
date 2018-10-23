/**
 * A BinarySearchTree class with full (public) access to the internals
 * of the data structure.
 */
public class TreeNode {

    public int data;
    public TreeNode left;
    public TreeNode right;
    public TreeNode parent;
    public int size = 0;
    public boolean visited;

    public TreeNode(final int d) {
        data = d;
        size = 1;
        visited = false;
    }

    public int size() {
        return size;
    }

    public void setLeftChild(final TreeNode left) {
        this.left = left;
        if (left != null) {
            left.parent = this;
        }
    }

    public void setRightChild(final TreeNode right) {
        this.right = right;
        if (right != null) {
            right.parent = this;
        }
    }

    /**
     * Recursively inserts a node in the correct position in
     * the BinarySearchTree.
     */
    public void insertInOrder(final int d) {
        if (d <= data) {
            if (left == null) {
                setLeftChild(new TreeNode(d));
            } else {
                left.insertInOrder(d);
            }
        } else {
            if (right == null) {
                setRightChild(new TreeNode(d));
            } else {
                right.insertInOrder(d);
            }
        }
    }

    /**
     * Recursively finds a node with the given data in
     * the BinarySearchTree.
     */
    public TreeNode find(final int d) {
        if (d == data) {
            return this;
        } else if (d <= data) {
            return left != null
                ? left.find(d)
                : null;
        } else if (d > data) {
            return right != null
                ? right.find(d)
                : null;
        }
        return null;
    }
}
