import java.util.ArrayList;

/**
 * Represents a single node in a graph.
 */
public class Node<T> {

	private T data;
	private boolean visited;
	private ArrayList<Node<T>> children;

	public Node() {
		visited = false;
		children = new ArrayList<>();
	}

	public Node(final T data) {
		this.data = data;
		visited = false;
		children = new ArrayList<>();
	}

	public Node(final T data, final ArrayList<Node<T>> children) {
		this.data = data;
		visited = false;
		this.children = children;
	}

	public void visit() {
		System.out.println(data);
		visited = true;
	}

	public void unvisit() {
		visited = false;
	}

	public T data() {
		return data;
	}

	public boolean visited() {
		return visited;
	}

	public ArrayList<Node<T>> children() {
		return children;
	}

	public void setChildren(final ArrayList<Node<T>> children) {
		this.children = children;
	}

	public void addChild(final Node<T> child) {
		children.add(child);
	}

	public void addChildren(final ArrayList<Node<T>> children) {
		children.stream().forEach(child -> addChild(child));
	}
}
