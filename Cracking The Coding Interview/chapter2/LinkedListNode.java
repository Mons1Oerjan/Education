public class LinkedListNode {
	public LinkedListNode prev;
	public LinkedListNode next;
	public LinkedListNode last;
	public int data;

	public LinkedListNode(final int data, final LinkedListNode next, final LinkedListNode prev) {
		this.data = data;
		setNext(next);
		setPrevious(prev);
	}

	public LinkedListNode(final int data) {
		this.data = data;
	}

	public LinkedListNode() {}

	public void setNext(final LinkedListNode n) {
		next = n;
		if (this == last) {
			last = n;
		}
		if (n != null && n.prev != this) {
			n.setPrevious(this);
		}
	}

	public void setPrevious(final LinkedListNode p) {
		prev = p;
		if (p != null && p.next != this) {
			p.setNext(this);
		}
	}

	public LinkedListNode clone() {
		LinkedListNode next2 = null;
		if (next != null) {
			next2 = next.clone();
		}
		return new LinkedListNode(data, next2, null);
	}

	public void appendToTail(final int d) {
		final LinkedListNode end = new LinkedListNode(d);
		LinkedListNode curr = this;
		
		while (curr.next != null) {
			curr = curr.next;
		}
		
		curr.setNext(end);
	}

	public LinkedListNode deleteNode(LinkedListNode head, final int d) {
		LinkedListNode curr = head;

		if (curr.data == d) {
			// delete first node
			return head.next;
		}

		while (curr.next != null) {
			if (curr.data == d) {
				// delete node by setting next to next.next
				curr.setNext(curr.next.next);
				return head;
			}
			curr = curr.next;
		}
		
		// not found, simply return the list
		return head;
	}

	public void print() {
		LinkedListNode curr = this;
		
		System.out.print("[");

		while (curr != null) {
			System.out.print(curr.data + " -> ");
			curr = curr.next;
		}

		System.out.println("null]");
	}
}
