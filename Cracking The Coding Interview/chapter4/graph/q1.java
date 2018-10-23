import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class q1 {

	public static void main(String... args) {
		final Graph<String> graph = new Graph<>(generateDirectedGraph());
		final Node<String> root = graph.nodes().get(0);

        System.out.println("A path from node0 to node1 exists (should return true): " +
            hasPath(graph, root, graph.nodes().get(1)));
		graph.unvisitAllNodes();
        System.out.println("A path from node0 to node4 exists (should return true): " +
            hasPath(graph, root, graph.nodes().get(4)));
		graph.unvisitAllNodes();
        System.out.println("A path from node0 to node10 exists (should return false): " +
            hasPath(graph, root, graph.nodes().get(10)));
		graph.unvisitAllNodes();
	}

    /**
     * Checks if there is a path between the two given nodes in a
     * directional graph using BFS.
     *
     * Time complexity: O(|V| + |E|) where V = # of vertices, and E = # of edges.
     * Space complexity: O(|V|) where V = # of vertices.
     *
     * @param graph the graph that contains the input nodes.
     * @param n1 the first node to check if a path exists.
     * @param n2 the second node to check if a path exists.
     * @return boolean value whether a path exists or not.
     */
    private static boolean hasPath(
            final Graph<String> graph,
            final Node<String> n1,
            final Node<String> n2) {
        if (n1 == null ||
            n2 == null ||
            !graph.contains(n1) ||
            !graph.contains(n2)) {
            return false;
        }

		// BFS algorithm:
		final Queue<Node<String>> queue = new LinkedList();
		queue.add(n1);
		while (!queue.isEmpty()) {
			Node<String> node = queue.remove();
			if (node == n2) {
				return true;
			}
			if (!node.visited()) {
				node.visit();
			}
			for (final Node<String> child : node.children()) {
				if (child == n2) {
					return true;
				}
				if (!child.visited()) {
					child.visit();
					queue.add(child);
				}
			}
		}

		return false;
    }

    private static ArrayList<Node<String>> generateDirectedGraph() {
		final ArrayList<Node<String>> nodes = new ArrayList<>();

		// generate nodes for the graph
		for (int i = 0; i < 12; i++) {
			final Node<String> node = new Node<>("node" + i);
			nodes.add(node);
		}

		// set directed paths for node0:
		nodes.get(0).addChild(nodes.get(1));
		nodes.get(0).addChild(nodes.get(2));
		nodes.get(0).addChild(nodes.get(3));

		// set directed paths for node1:
        nodes.get(1).addChild(nodes.get(2));
		nodes.get(1).addChild(nodes.get(7));
		nodes.get(1).addChild(nodes.get(9));

        // set directed paths for node2:
		nodes.get(2).addChild(nodes.get(6));

        // set directed paths for node5:
        nodes.get(5).addChild(nodes.get(1));
        nodes.get(5).addChild(nodes.get(9));
        nodes.get(5).addChild(nodes.get(0));
        nodes.get(5).addChild(nodes.get(4));

		// set directed paths for node6:
        nodes.get(6).addChild(nodes.get(3));
		nodes.get(6).addChild(nodes.get(4));
		nodes.get(6).addChild(nodes.get(5));
		nodes.get(6).addChild(nodes.get(7));
		nodes.get(6).addChild(nodes.get(8));

        // set directed path for node7:
		nodes.get(7).addChild(nodes.get(4));

        // set directed paths for node8:
        nodes.get(8).addChild(nodes.get(3));
		nodes.get(8).addChild(nodes.get(7));

		// set directed path: for node10:
		nodes.get(10).addChild(nodes.get(11));

		return nodes;
	}

	private static ArrayList<Node<String>> generateBidirectionalGraph() {
		final ArrayList<Node<String>> nodes = new ArrayList<>();

		// generate nodes for the graph
		for (int i = 0; i < 10; i++) {
			final Node<String> node = new Node<>("node" + i);
			nodes.add(node);
		}

		// set bidirectional connections for node0:
		nodes.get(0).addChild(nodes.get(1));
		nodes.get(0).addChild(nodes.get(2));
		nodes.get(0).addChild(nodes.get(3));
		nodes.get(1).addChild(nodes.get(0));
		nodes.get(2).addChild(nodes.get(0));
		nodes.get(3).addChild(nodes.get(0));

		// set bidirectional connections for node1:
		nodes.get(1).addChild(nodes.get(7));
		nodes.get(1).addChild(nodes.get(9));
		nodes.get(7).addChild(nodes.get(1));
		nodes.get(9).addChild(nodes.get(1));

		// set bidirectional connections for node6:
		nodes.get(6).addChild(nodes.get(4));
		nodes.get(6).addChild(nodes.get(5));
		nodes.get(6).addChild(nodes.get(7));
		nodes.get(6).addChild(nodes.get(8));
		nodes.get(4).addChild(nodes.get(6));
		nodes.get(5).addChild(nodes.get(6));
		nodes.get(7).addChild(nodes.get(6));
		nodes.get(8).addChild(nodes.get(6));

		return nodes;
	}
}
