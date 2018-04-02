import java.util.ArrayList;

/**
 * Generic OrderedList data structure
 */
public class OrderedList<T extends Comparable<T>> {
	private ArrayList<T> elements;
	private int cursor;

	public OrderedList(int cap) {
		this.elements = new ArrayList<T>(cap);
		this.cursor = -1;
	}

	public OrderedList() {
		this.elements = new ArrayList<T>();
		this.cursor = -1;
	}

	public int size() {
		return this.elements.size();
	}

	public boolean isEmpty() {
		return this.elements.isEmpty();
	}

	public void clear() {
		this.elements.clear();
	}

	public T get(final int index) {
		if (index < 0 || index >= this.elements.size()) {
			System.out.println("Index out of bounds");
			return null;
		}

		return this.elements.get(index);
	}

	public T first() {
		if (this.elements.size() == 0) return null;
		this.cursor = 0;
		return this.elements.get(this.cursor);
	}

	public T next() {
		if (this.cursor < 0 || this.cursor == this.elements.size() - 1) return null;
		this.cursor++;
		return this.elements.get(this.cursor);
	}

	public void enumerate() {
		System.out.println(this.elements);
	}

	public int binarySearch(final T item) {
		if (this.elements.size() == 0) return -1;

		int lo = 0;
		int hi = elements.size() - 1;
		int mid = 0;

		while (lo <= hi) {
			mid = (lo + hi) / 2;
			int c = item.compareTo(this.elements.get(mid));
			if (c == 0)
				return mid;
			if (c < 0)
				hi = mid - 1;
			if (c > 0)
				lo = mid + 1;
		}

		if (item.compareTo(this.elements.get(mid)) < 0)
			return (-(mid + 1));
		else
			return (-(mid + 2));
	}

	public void add(final int pos, final T item) {
		this.elements.add(pos, item);
	}

	public void add(final T item) {
		this.elements.add(item);
	}

	public void insert(final T item) {
		if (this.elements.size() == 0) {
			this.elements.add(item);
			return;
		}

		final int pos = binarySearch(item);

		if (pos >= 0) {
			System.out.println("Item " + item + " already present");
			return;
		} else {
			this.elements.add(-pos - 1, item);
		}
	}

	public void remove(final T item) {
		final int pos = binarySearch(item);

		if (pos < 0) {
			System.out.println("No such element");
			return;
		} else {
			this.elements.remove(pos);
		}
	}

	public T remove(final int pos) {
		return this.elements.remove(pos);
	}
}
