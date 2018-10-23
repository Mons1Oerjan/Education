public class q5 {
	
	private static int minValue(final int num1, final int num2, final int num3) {
		if (num1 <= num2 && num1 <= num3) return num1;
		else if (num2 <= num1 && num2 <= num3) return num2;
		return num3;
	}

	/**
	 * Returns the minimum edit distance between 2 strings using Dynamic Programming.
	 * 
	 * The 3 Edit Distance operations are:
	 *   - inserting a character
	 *   - replacing a character
	 *   - removing a character
	 * 
	 * Time complexity: O(i * j) where i=s1.length() and j=s2.length() 
	 */
	private static int getEditDistance(String s1, String s2) {
		s1 = "0" + s1;
		s2 = "0" + s2;
		final char[] chars1 = s1.toCharArray();
		final char[] chars2 = s2.toCharArray();
		final int len1 = chars1.length;
		final int len2 = chars2.length;
		final int[][] table = new int[len1][len2];
		
		// initialize table
		table[0][0] = 0;
		for (int i = 1; i < len1; i++) {
			table[i][0] = i;
		}
		for (int i = 1; i < len2; i++) {
			table[0][i] = i;
		}
		
		// fill table with edit distances using DP
		for (int i = 1; i < len1; i++) {
			for (int j = 1; j < len2; j++) {
				if (chars1[i] == chars2[j]) {
					table[i][j] = table[i-1][j-1];
				} else {
					table[i][j] = minValue(table[i-1][j], table[i-1][j-1], table[i][j-1]) + 1;
				}
			}
		}
		
		return table[len1-1][len2-1];
	}

	private static boolean isOneOrLessEditsAway(String s1, String s2) {
		s1 = s1.toLowerCase();
		s2 = s2.toLowerCase();

		if (s1.equals(s2)) return true;
	
		return getEditDistance(s1, s2) <= 1;
	}

	public static void main(String... args) {
		final String s1 = "foo";
		String s2 = "foo";
		System.out.println(s1 + " and " + s2 + ": " + isOneOrLessEditsAway(s1, s2));
		s2 = "doo";
		System.out.println(s1 + " and " + s2 + ": " + isOneOrLessEditsAway(s1, s2));
		s2 = "oo";
		System.out.println(s1 + " and " + s2 + ": " + isOneOrLessEditsAway(s1, s2));
		s2 = "fooo";
		System.out.println(s1 + " and " + s2 + ": " + isOneOrLessEditsAway(s1, s2));
		s2 = "fff";
		System.out.println(s1 + " and " + s2 + ": " + isOneOrLessEditsAway(s1, s2));
		s2 = "abc";
		System.out.println(s1 + " and " + s2 + ": " + isOneOrLessEditsAway(s1, s2));
		s2 = "";
		System.out.println(s1 + " and " + s2 + ": " + isOneOrLessEditsAway(s1, s2));
	}
}
