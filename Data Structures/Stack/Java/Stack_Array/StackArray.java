/**
 * Stack data structure for storing strings using an array
 */
public class StackArray {
	private String[] s;
	private int top;

	public StackArray(final int capacity) {
		s = new String[capacity];
		top = -1;
	}

	public void push(final String x) {
		if (top == s.length-1)
			System.out.println("Stack full");
		else {
			top++;
			s[top] = x;
		}
	}

	public String pop() {
		String result = null;

		if (top == -1)
			System.out.println("empty stack");
		else {
			result = s[top];
			top--;
		}

		return result;
	}

	public boolean isEmpty() {
		return top == -1;
	}

	public String peek() {
		String result = null;

		if (top == -1)
			System.out.println("Empty stack");
		else
			result = s[top];

		return result;
	}
}
