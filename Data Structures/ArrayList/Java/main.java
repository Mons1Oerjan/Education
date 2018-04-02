package ArrayList;

import java.util.stream.IntStream;

public class main {
	public static void main(String... args) {
		final int[] values = IntStream.range(0, 9).toArray();
		final ArrayList list = new ArrayList(values);

		list.print();

		list.add(9);
		list.add(10);
		list.add(11);

		list.print();
		System.out.println(list.size());

		list.remove(list.size() - 1);
		list.remove(list.size() - 1);
		list.remove(list.size() - 1);

		list.print();
		System.out.println(list.size());
	}
}
