package LinkedList;

import java.util.Objects;

class main {

	private static void populateLinkedList(LinkedList list, int nodesToAdd) {
		if (Objects.isNull(list) || nodesToAdd < 0) {
			return;
		}

		for (int i = 0; i < nodesToAdd; i++) {
			final LinkedList temp = new LinkedList(i);
			list.next = temp;
			list = list.next;
		}
	}

	private static void printLinkedList(final LinkedList list) {
		if (Objects.isNull(list)) {
			return;
		}

		LinkedList curr = list;

		while (Objects.nonNull(curr)) {
			System.out.println(curr.value);
			curr = curr.next;
		}
	}
	
	public static void main(String... args) {
		final LinkedList list = new LinkedList(1);
		populateLinkedList(list, 10);
		printLinkedList(list);
	}
}
