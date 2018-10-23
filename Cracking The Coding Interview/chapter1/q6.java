import java.lang.StringBuilder;

public class q6 {
	
	private static String compressString(final String str) {
		final int strLength = str.length();

		if (strLength == 0) return "";
		
		final StringBuilder result = new StringBuilder();
		char c = str.charAt(0);
		int count = 1;

		for (int i = 1; i < strLength; i++) {
			final char currChar = str.charAt(i);
			if (c == currChar) {
				count++;
			} else {
				// append char and count to the result
				result.append(c);
				result.append(count);

				// reset variables
				c = currChar;
				count = 1;
			}
		}
		
		// append the last chars:
		result.append(c);
		result.append(count);

		final String compressedStr = result.toString();

		return strLength <= compressedStr.length()
			? str
			: compressedStr;
	}
	
	public static void main(String... args) {
		String input = "aaaabbbcccdde";
		System.out.println("Compressing \"" + input + "\": " + compressString(input));
		input = "aabbccdd";
		System.out.println("Compressing \"" + input + "\": " + compressString(input));
	}
}
