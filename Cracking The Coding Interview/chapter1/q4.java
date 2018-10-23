import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;

public class q4 {
	
	private static boolean isNumberOdd(final Integer num) {
		return num % 2 == 1;
	}

	private static boolean isPermutationOfPalindrome(String str) {
		if (str.length() == 0) return false;
		if (str.length() == 1) return true;
		
		// remove whitespace and convert to lower case
		str = str.replaceAll("\\s", "");
		str = str.toLowerCase();

		final char[] chars = str.toCharArray();
		final Map<Character, Integer> map = new HashMap<>();
		
		// count how many we have of each character and store results in a map
		for (char c : chars) {
			if (map.containsKey(c)) {
				map.put(c, map.get(c) + 1);
			} else {
				map.put(c, 1);
			}
		}

		if (isNumberOdd(str.length())) {
			// all chars counts must be even except for one char count which must be odd.
			int count = 0;
			for (Entry<Character, Integer> entry : map.entrySet()) {
				if (isNumberOdd(entry.getValue())) {
					count++;
					if (count > 1) return false;
				}
			}
		} else {
			// all chars counts must be even
			for (Entry<Character, Integer> entry : map.entrySet()) {
				if (isNumberOdd(entry.getValue())) {
					return false;
				}
			}
		}

		return true;
	}
	
	public static void main(String... args) {
		System.out.println("Is this string a permutation of a palindrome?");
		String input = "Tact Coa";
		System.out.println("\"" + input + "\": " + isPermutationOfPalindrome(input));
		input = "abccbA";
		System.out.println("\"" + input + "\": " + isPermutationOfPalindrome(input));
		input = "abcdefgh";
		System.out.println("\"" + input + "\": " + isPermutationOfPalindrome(input));
	}
}
