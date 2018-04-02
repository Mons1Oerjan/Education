/**
 * Generic Queue data structure
 */
public class Queue<T> {
	private LinkedList<T> list;
	int cursor;

	public Queue() {
		list = new LinkedList<T>();
		cursor = -1;
	}

	public void enqueue(T item) {
		if (list.size() == 0)
			list.add(item);
		else
			list.addToEnd(item);
	}

	public T dequeue() {
		if (list.size() == 0)
			return null;
		else {
			T item = list.getAt(1);
			list.removeAt(1);

			return item;
		}
	}

	public int size() {
		return list.size();
	}

	public boolean isEmpty() {
		return (list.size() == 0);
	}

	public void clear() {
		list.clear();
	}

	public T peek() {
		if (list.size() == 0)
			return null;
		else
			return list.getAt(0);
	}

	public int positionOf(T item) {
		return list.indexOf(item);
	}

	public void remove(T item) {
		list.remove(item);
	}

	public T first() {
		if (list.size() == 0) {
			return null;
		}
		cursor = 0;

		return list.getAt(cursor);
	}

	public T next() {
		if (cursor < 0 || cursor == list.size() - 1) {
			return null;
		}
		cursor++;

		return list.getAt(cursor);
	}
}
