public class q2 {

	/**
	 * Returns the Kth last element in a LinkedList.
	 * Time complexity: O(n)
	 * Space complexity: O(1)
	 */
	private static int findKthLastElement(LinkedListNode node, final int K) {
		LinkedListNode runner = node;

		// place the runner K steps in front of the node
		for (int i = 0; i < K; i++) {
			runner = runner.next;
		}
		
		// iterate until the runner hits the end
		while (runner != null) {
			runner = runner.next;
			node = node.next;
		}

		// node will now be Kth last element in the LinkedList
		return node.data;
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
		
		int K = 4;
		System.out.println("Element #" + K + " from the back is: " + findKthLastElement(list, K));
		
		K = 8;
		System.out.println("Element #" + K + " from the back is: " + findKthLastElement(list, K));
	}
}
