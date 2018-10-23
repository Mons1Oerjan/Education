import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Arrays;

public class q3 {

    public static void main(String... args) {
        // construct a binary tree:
        final int[] list = {0, 5, 8, 2, 3, 4, 7, 9, 12, 1};
        Arrays.sort(list);
        final TreeNode tree = constructMinimalHeightBST(list);
        print(tree);
        
        final ArrayList<LinkedList<TreeNode>> depthLists = convertAllTreeDepthsToLists(tree);

        depthLists.stream().forEach(linkedList -> {
            for (final TreeNode node : linkedList) {
                System.out.print(node.data + " ");
            }
            System.out.println();
        });
    }

    /**
     * Returns a list of LinkedLists for each depth in a binary tree.
     */
    private static ArrayList<LinkedList<TreeNode>> convertAllTreeDepthsToLists(
            final TreeNode root) {
        final ArrayList<LinkedList<TreeNode>> list = new ArrayList();
        createDepthLinkedList(list, root, 0);
        return list;
    }

    /**
     * Uses InOrderTraversal to recursively build LinkedLists of each tree depth.
     */
    private static void createDepthLinkedList(
            final ArrayList<LinkedList<TreeNode>> list,
            final TreeNode root,
            final int depth) {
        if (root == null) return;

        LinkedList<TreeNode> linkedList = null;

        if (list.size() == depth) {
            // this depth is not stored in the list
            linkedList = new LinkedList();
            list.add(linkedList);
        } else {
            linkedList = list.get(depth);
        }

        linkedList.add(root);
        createDepthLinkedList(list, root.left, depth + 1);
        createDepthLinkedList(list, root.right, depth + 1);
    }


    /********************* Helper methods taken from q2: *********************/

    /**
     * Driver method
     */
    private static TreeNode constructMinimalHeightBST(final int[] list) {
        return constructMinimalHeightBST(list, 0, list.length - 1);
    }

    /**
     * Recursively constructs a minimal height BinarySearchTree.
     */
    private static TreeNode constructMinimalHeightBST(
            final int[] list,
            final int start,
            final int end) {
        if (end > start) return null;

        // create a node holding the middle value
        final int mid = start + end / 2;
        final TreeNode node = new TreeNode(list[mid]);

        // recursively create left and right children by picking
        // the middle value in the left and right sub-arrays.
        node.left = constructMinimalHeightBST(list, start, mid - 1);
        node.right = constructMinimalHeightBST(list, mid + 1, end);

        return node;
    }

    /**
     * Driver method for InOrderTraversal
     */
    private static void print(final TreeNode root) {
        printInOrder(root);
    }

    /**
     * Print the tree using InOrderTraversal
     *
     * @param root the root of the Binary Tree.
     */
    private static void printInOrder(final TreeNode root) {
        if (root != null) {
            printInOrder(root.left);
            System.out.println(root.data);
            printInOrder(root.right);
        }
    }
}
