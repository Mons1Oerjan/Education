package GenericLinkedList;

/**
 * Generic Node data structure which represents a single item
 * in the LinkedList.
 */
public class Node<T> {
	private T data;
	private Node<T> next;

	public Node(final T data, final Node<T> next) {
		this.data = data;
		this.next = next;
	}

	public T getData() {
		return data;
	}

	public Node<T> getNext() {
		return this.next;
	}

	public void setData(final T data) {
		this.data = data;
	}

	public void setNext(final Node<T> next) {
		this.next = next;
	}
}
