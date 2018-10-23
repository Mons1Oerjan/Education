import java.util.Math;

public class q4 {

    private static final int ERROR = Integer.MIN_VALUE;

    public static void main(String... args) {
        
    }

    private boolean isTreeBalanced(final TreeNode root) {
        return getHeight(root) != ERROR;
    }

    private int getHeight(
            final TreeNode root) {
        if (root == null) return -1;

        int leftHeight = getHeight(root.left);
        if (leftHeight == ERROR) return ERROR;

        int rightHeight = getHeight(root.right);
        if (rightHeight == ERROR) return ERROR;

        return Math.abs(leftHeight - rightHeight) > 1
            ? ERROR
            : Math.max(leftHeight, rightHeight) + 1;
    }

}
