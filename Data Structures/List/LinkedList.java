package GenericLinkedList;

/**
 * Generic LinkedList data structure
 */
public class LinkedList<T> {
	private Node<T> front;
	private int count;

	public LinkedList() {
		this.front = null;
		this.count = 0;
	}

	public Node<T> getFront() {
		return this.front;
	}

	/**
	 * Adds the item to the front of the LinkedList.
	 */
	public void add(final T item) {
		final Node<T> newNode = new Node<T>(item, front);
		this.front = newNode;
		this.count++;
	}

	public int size() {
		return this.count;
	}

	public void clear() {
		this.front = null;
		this.count = 0;
	}

	public boolean isEmpty() {
		return this.count == 0;
	}

	public void enumerate() {
		Node<T> curr = this.front;

		while (curr != null) {
			System.out.print(curr.getData() + " --> ");
			curr = curr.getNext();
		}
	}

	/**
	 * Returns the data at the given index.
	 */
	public T getAt(final int index) {
		if (index < 0 || index >= this.count) {
			System.out.println("Error. Index out of bounds");
			return null;
		}

		Node<T> curr = this.front;

		for (int i = 0; i < index; i++) {
			curr = curr.getNext();
		}

		return curr.getData();
	}

	/**
	 * Inserts the given item at the given index.
	 */
	public void insertAt(final T item, final int index) {
		if (index < 0 || index > this.count) {
			System.out.println("Can't insert. Index out of bounds.");
			return;
		}

		if (index == 0) {
			add(item);
			return;
		}

		Node<T> prev = front;

		for (int i = 0; i < index - 1; i++) {
			prev = prev.getNext();
		}

		final Node<T> itemnode = new Node<T>(item, prev.getNext());
		prev.setNext(itemnode);
		this.count++;
	}

	/**
	 * Sets the given item at the given index.
	 */
	public void setAt(final T item, final int index) {
		if (index < 0 || index >= count) {
			System.out.println("Can't set. Index out of bounds");
			return;
		}

		Node<T> curr = front;

		for (int i = 0; i < index; i++) {
			curr = curr.getNext();
		}

		curr.setData(item);
	}

	/**
	 * Returns the index of the first occurrence of
	 * the given item, or -1 if not found
	 */
	public int indexOf(final T item) {
		Node<T> curr = front;

		for (int i = 0; i < count; i++) {
			if (item.equals(curr.getData())) {
				return i;
			}
			curr = curr.getNext();
		}

		return -1;
	}

	/**
	 * Removes the node at the given index.
	 */
	public T removeAt(final int index) {
		if (index < 0 || index >= count) {
			System.out.println("Can't remove. Index out of bounds");
			return null;
		}

		T result = null;

		if (index == 0) {
			result = this.front.getData();
			front = this.front.getNext();
		} else {
			Node<T> prev = this.front;

			for (int i = 0; i < index - 1; i++) {
				prev = prev.getNext();
			}

			result = prev.getNext().getData();
			prev.setNext(prev.getNext().getNext());
		}

		count--;

		return result;
	}

	/**
	 * Removes the node containing the first occurrence of a given item.
	 */
	public void remove(final T item) {
		if (indexOf(item) == -1) {
			System.out.println("Can't remove. Item not found.");
			return;
		}

		removeAt(i);
	}

	/**
	 * Removes all nodes containing a given item in one scan using O(n) time.
	 */
	public void removeAll(final T item) {
		Node<T> curr = this.front;
		Node<T> prev = null;

		while (curr != null) {
			if (this.front.getData().equals(item)) {
				this.front = this.front.getNext();
				curr = curr.getNext();
				count--;
			} else if (curr == this.front) {
				prev = curr;
				curr = curr.getNext();
			} else {
				if (curr != null) {
					if (curr.getData().equals(item)) {
						prev.setNext(curr.getNext());
						curr = prev.getNext();
						count--;
					} else {
						prev = curr;
						curr = curr.getNext();
					}
				}
			}
		}
	}

	/**
	 * Adds an item to the end of the LinkedList.
	 */
	public void addToEnd(final T item) {
		Node<T> n = new Node<T>(item, null);

		if (front == null) {
			this.front = n;
		} else {
			Node<T>	curr = this.front;

			while (curr.getNext() != null) {
				curr = curr.getNext();
			}

			curr.setNext(n);
		}

		count++;
	}
}
