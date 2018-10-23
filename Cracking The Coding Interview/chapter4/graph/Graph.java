import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

/**
 * The Graph class is a collection of all nodes in a graph.
 */
public class Graph<T> {

	private ArrayList<Node<T>> nodes;

	public Graph() {
		nodes = new ArrayList<>();
	}

	public Graph(final ArrayList<Node<T>> nodes) {
		this.nodes = nodes;
	}

	public ArrayList<Node<T>> nodes() {
		return nodes;
	}

	public Node<T> getNode(final int index) {
		return nodes.get(index);
	}

	public void add(final Node<T> n) {
		nodes.add(n);
	}

	public boolean contains(final Node<T> node) {
		return nodes.contains(node);
	}

	/**
	 * Driver method for flagging all nodes as unvisited.
	 */
	public void unvisitAllNodes() {
		if (nodes.isEmpty()) return;
		unvisitAllNodes(nodes.get(0));
	}

	/**
	 * Driver method for the recursive DFS algorithm.
	 *
	 * @param root the starting node for the DFS algorithm.
	 */
	public void depthFirstSearch(final Node<T> root) {
		if (!nodes.contains(root)) return;
		DFS(root);
	}

	/**
	 * Driver method for the recursive BFS algorithm.
	 *
	 * @param root the starting node for the BFS algorithm.
	 */
	public void breadthFirstSearch(final Node<T> root) {
		if (!nodes.contains(root)) return;
		BFS(root);
	}

	/**
	 * Performs Depth First Search starting from the given node in the graph.
	 * Time complexity:
	 * Space complexity:
	 *
	 * @param root the starting node for the DFS algorithm.
	 */
	private void DFS(final Node<T> root) {
		if (root == null) return;

		root.visit();

		for (final Node<T> node : root.children()) {
			if (!node.visited()) {
				DFS(node);
			}
		}
	}

	/**
	 * Performs Breadth First Search starting from the given node in the graph.
	 * Time complexity:
	 * Space complexity:
	 *
	 * @param root the starting node for the BFS algorithm.
	 */
	private void BFS(final Node<T> root) {
		if (root == null) return;

		final Queue<Node<T>> queue = new LinkedList<>();
		queue.add(root);

		while (!queue.isEmpty()) {
			Node<T> node = queue.remove();

			if (!node.visited()) {
				node.visit();
			}

			for (final Node<T> childNode : node.children()) {
				if (!childNode.visited()) {
					childNode.visit();
					queue.add(childNode);
				}
			}
		}
	}

	/**
	 * Recursively flags all nodes in the graph as unvisited using DFS.
	 *
	 * @param root the starting node for the DFS algorithm.
	 */
	private void unvisitAllNodes(final Node<T> root) {
		if (root == null) return;

		root.unvisit();

		for (final Node<T> node : root.children()) {
			if (node.visited()) {
				unvisitAllNodes(node);
			}
		}
	}
}
