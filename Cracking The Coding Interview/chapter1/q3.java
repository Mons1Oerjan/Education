public class q3 {
	
	private final String SPACE = "%20";

	private static String URLify(final String str, final int len) {
		char[] chars = str.toCharArray();
		int fullLenIndex = chars.length - 1;

		for (int i = len - 1; i >= 0; i--) {
			if (chars[i] == ' ') {
				chars[fullLenIndex] = '0';
				chars[fullLenIndex - 1] = '2';
				chars[fullLenIndex - 2] = '%';
				fullLenIndex -= 3;
			} else {
				chars[fullLenIndex] = chars[i];
				fullLenIndex--;
			}
		}

		return String.valueOf(chars);
	}

	public static void main(String... args) {
		final String inputStr = "Mr John Smith      ";
		final int lenWithoutTrailingSpaces = 13;

		System.out.println(URLify(inputStr, lenWithoutTrailingSpaces));
	}
}
