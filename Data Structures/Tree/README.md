# Trees
This directory contains a collection of different types of Tree data structures.

## Important Tree Algorithms

### In-Order Traversal
Visit the left branch first, then the current node, then finally the right branch.
```
public void inOrderTraversal(final TreeNode node) {
    if (node != null) {
        inOrderTraversal(node.left);
        visit(node);
        inOrderTraversal(node.right);
    }
}
```

### Pre-Order Traversal
Visit the current node first, then the left branch, then finally the right branch.
```
public void preOrderTraversal(final TreeNode node) {
    if (node != null) {
        visit(node);
        preOrderTraversal(node.left);
        preOrderTraversal(node.right);
    }
}
```

### Post-Order Traversal
Visit the left branch, then the right branch, then finally the current node. The root is always the last node visited.
```
public void postOrderTraversal(final TreeNode node) {
    if (node != null) {
        postOrderTraversal(node.left);
        postOrderTraversal(node.right);
        visit(node);
    }
}
```
