/**
 * Unordered List Data Structure based on a LinkedList.
 */
public class List<T> {
	private LinkedList<T> elements;
	private int cursor;

	public List() {
		this.elements = new LinkedList<T>();
		this.cursor = -1;
	}

	public void add(final T item) {
		this.elements.add(item);
	}

	public int size() {
		return this.elements.size();
	}

	public boolean isEmpty() {
		return this.elements.isEmpty();
	}

	public boolean contains(final T item) {
		return this.elements.indexOf(item) != -1;
	}

	public void remove(final T item) {
		this.elements.remove(item);
	}

	public void removeAll(final T item) {
		this.elements.removeAll(item);
	}

	public void clear() {
		this.elements.clear();
	}

	public void enumerate() {
		this.elements.enumerate();
	}

	// gets the first item
	public T first() {
		if (this.elements.size() == 0) return null;
		this.cursor = 0;
		return this.elements.getAt(this.cursor);
	}

	// gets the next item
	public T next() {
		if (this.cursor < 0 || this.cursor == this.elements.size() - 1) return null;
		this.cursor++;
		return this.elements.getAt(this.cursor);
	}
}
