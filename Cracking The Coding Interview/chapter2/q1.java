import java.util.HashSet;

public class q1 {
	
	/**
	 * Removes duplicates from the given unsorted LinkedList
	 * Time complexity: O(n)
	 * Space complexity: O(n)
	 */
	private static void removeDuplicates(LinkedListNode node) {
		LinkedListNode prev = null;
		final HashSet<Integer> set = new HashSet<Integer>();
		
		while (node != null) {
			if (set.contains(node.data)) {
				prev.next = node.next;
			} else {
				set.add(node.data);
				prev = node;
			}
			node = node.next;
		}
	}

	/**
	 * Removes duplicates from the given unsorted LinkedList
	 * Time complexity: O(n^2)
	 * Space complexity: O(1)
	 */
	private static void removeDuplicatesInPlace(LinkedListNode node) {
		while (node != null) {
			LinkedListNode runner = node;

			while (runner != null && runner.next != null) {
				if (runner.next.data == node.data) {
					runner.next = runner.next.next;
				} else {
					runner = runner.next;
				}
			}
			node = node.next;
		}
	}

	public static void main(String... args) {
		final LinkedListNode list = new LinkedListNode(1);
		
		list.appendToTail(5);
		list.appendToTail(3);
		list.appendToTail(3);
		list.appendToTail(2);
		list.appendToTail(5);
		list.appendToTail(6);
		list.appendToTail(4);
		list.appendToTail(5);
		list.appendToTail(1);
		list.appendToTail(2);
		
		list.print();

		final LinkedListNode clone = list.clone();

		removeDuplicates(list);
		System.out.println("Removed all duplicates. List content updated:");
		list.print();

		removeDuplicatesInPlace(clone);
		System.out.println("Removed all duplicates in place. Clone content updated:");
		clone.print();
	}
}
