import java.util.ArrayList;

/**
 * Traditional Stack data structure for storing strings using an ArrayList
 */
public class StackArrayList {
	private ArrayList<String> s;

	public StackArrayList() {
		s = new ArrayList<String>();
	}

	public boolean isEmpty() {
		return (s.size() == 0);
	}

	// add to the stack
	public void push(final String x) {
		s.add(x);
	}

	// remove from stack
	public String pop() {
		String result = null;

		if (isEmpty())
			System.out.println("Stack empty");
		else {
			result = s.get(s.size()-1);
			s.remove(s.size()-1);
		}

		return result;
	}

	// look at the top piece
	public String peek() {
		String result = null;

		if (isEmpty())
			System.out.println("Stack empty");
		else
			result = s.get(s.size()-1);

		return result;
	}
}
