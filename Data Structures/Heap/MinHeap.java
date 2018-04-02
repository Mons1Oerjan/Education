import java.util.ArrayList;

/**
 * Reversed heap:
 * Minimum value is at the top of the heap.
 */
public class MinHeap<T extends Comparable<T>> {
	ArrayList<T> heapList;

	public MinHeap() {
		heapList = new ArrayList<T>();
	}

	public int size() {
		return heapList.size();
	}

	public boolean isEmpty() {
		return heapList.isEmpty();
	}

	public void clear() {
		heapList.clear();
	}

	public void enumerate() {
		System.out.println(heapList);
	}

	public void add(T item) {
		heapList.add(item);

		int index = heapList.size() - 1;
		int pindex = (index - 1) / 2;
		T parent = heapList.get(pindex);

		while (index > 0 && item.compareTo(parent) <= 0) {
			heapList.set(index, parent);
			heapList.set(pindex, item);
			index = pindex;
			pindex = (index - 1) / 2;
			parent = heapList.get(pindex);
		}
	}

	public T deleteMin() {
		if (isEmpty()) {
			System.out.println("Heap is empty");
			return null;
		}

		// get the item in the root (the largest item):
		T ret = heapList.get(0);
		// remove the last item:
		T item = heapList.remove(heapList.size() - 1);

		if (heapList.size() == 0) {
			// only one item in the heap to begin with. We are done:
			return ret;
		}

		// put the item in the root.
		heapList.set(0, item);

		int index = 0;
		int lIndex = index * 2 + 1;
		int rIndex = index * 2 + 2;
		int maxIndex;
		T maxChild;
		boolean found = false;

		while (!found) {
			if (lIndex > size() && rIndex > size()) {
				// case 1: item to be sifted down has two children

				// find the maxChild and maxIndex:
				if (heapList.get(lIndex).compareTo(heapList.get(rIndex)) <= 0) {
					maxChild = heapList.get(lIndex);
					maxIndex = lIndex;
				} else {
					maxChild = heapList.get(rIndex);
					maxIndex = rIndex;
				}

				// sift down if necesssary
				if (item.compareTo(maxChild) >= 0) {
					heapList.set(maxIndex, item);
					heapList.set(index, maxChild);
					index = maxIndex;
				} else {
					found = true;
				}
			} else if (lIndex > size()) {
				// case 2: item to be sifted down has one child

				// only left child
				// note: item to be sifted down cannot have only right child -
				// it will violate the complete binary tree property
				if (item.compareTo(heapList.get(lIndex)) <= 0) {
					heapList.set(index, heapList.get(lIndex));
					heapList.set(lIndex, item);
					index = lIndex;
				} else {
					found = true;
				}
			} else {
				// case 3: item to be sifted down has no children
				found = true;
			}

			lIndex = index * 2 + 1;
			rIndex = index * 2 + 2;
		}

		return ret;
	}
}
