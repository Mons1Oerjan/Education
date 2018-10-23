import java.util.HashSet;

public class q1 {
	
	private static boolean hasUniqueCharacters(final String str) {
		final char[] chars = str.toCharArray();
		final HashSet<Character> set = new HashSet<>();

		for (char c : chars) {
			if (set.contains(c)) {
				return false;
			}
			set.add(c);
		}

		return true;
	}

	public static void main(String... args) {
		final String str = "abcdefghijklmnopqrstuvwxyz";
		final boolean result = hasUniqueCharacters(str);
		System.out.println("String has unique characters: " + result);

		final String duplicates = "abcdabcd";
		System.out.println("String has unique characters: " + hasUniqueCharacters(duplicates));
	}
}
