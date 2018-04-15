import java.util.ArrayList;

public class main {

	/**
	 * Main method for testing the graph
	 */
	public static void main(String... args) {
		final Graph<String> graph = new Graph<>(generateGraph());
		final Node<String> root = graph.nodes().get(0);

		System.out.println("\nDFS from " + root.data() + ":");
		graph.depthFirstSearch(root);

		System.out.println("Unvisiting all nodes...");
		graph.unvisitAllNodes();

		System.out.println("\nBFS from " + root.data() + ":");
		graph.breadthFirstSearch(root);
	}

	private static ArrayList<Node<String>> generateGraph() {
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
