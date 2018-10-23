public class q4 {
	
	/**
	 * Partitions a LinkedList around the given value. All values smaller than the given
	 * value will appear first in the list, and all values greater than or equal to the 
	 * value will appear after the smaller values.
	 *
	 * Example: [1, 8, 6, 4, 9, 3] partitioned around 6 = [1, 4, 3, 8, 6, 9]
	 *
	 * Time complexity: O(n)
	 * Space complexity: O(n)
	 */
	private static LinkedListNode partition(LinkedListNode node, final int val) {
		LinkedListNode beforeHead = null;
		LinkedListNode beforeEnd = null;
		LinkedListNode afterHead = null;
		LinkedListNode afterEnd = null;

		// partition values into two lists "before" and "after"
		while (node != null) {
			LinkedListNode nodeToAdd = new LinkedListNode(node.data);

			if (nodeToAdd.data < val) {
				// add to before
				if (beforeHead == null) {
					beforeHead = nodeToAdd;
					beforeEnd = beforeHead;
				} else {
					beforeEnd.next = nodeToAdd;
					beforeEnd = beforeEnd.next;
				}
			} else {
				// add to after
				if (afterHead == null) {
					afterHead = nodeToAdd;
					afterEnd = afterHead;
				} else {
					afterEnd.next = nodeToAdd;
					afterEnd = afterEnd.next;
				}
			}
			node = node.next;
		}

		if (beforeHead == null) {
			return afterHead;
		}

		// merge "before" and "after"
		beforeEnd.next = afterHead;
		
		return beforeHead;
	}

	public static void main(String... args) {
		final LinkedListNode list = new LinkedListNode(1);

		list.appendToTail(5);
		list.appendToTail(3);
		list.appendToTail(9);
		list.appendToTail(2);
		list.appendToTail(5);
		list.appendToTail(8);
		list.appendToTail(4);
		list.appendToTail(7);
		list.appendToTail(1);
		list.appendToTail(2);

		list.print();

		System.out.println("Partitioning around 5:");
		final LinkedListNode partitionedAround5 = partition(list, 5);
		partitionedAround5.print();

		System.out.println("Partitioning around 3:");
		final LinkedListNode partitionedAround3 = partition(list, 3);
		partitionedAround5.print();

		System.out.println("Partitioning around 6:");
		final LinkedListNode partitionedAround6 = partition(list, 6);
		partitionedAround5.print();
	}
}
