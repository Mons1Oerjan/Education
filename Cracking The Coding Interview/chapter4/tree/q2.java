import java.util.Arrays;

public class q2 {

    public static void main(String... args) {
        final int[] list = {0, 5, 8, 2, 3, 4, 7, 9, 12, 1};
        Arrays.sort(list);
        final TreeNode tree = constructMinimalHeightBST(list);
        print(tree);
    }

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
