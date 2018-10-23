import java.util.Arrays;

public class q2 {
	
	private static boolean isPermutation(final String s1, final String s2) {
		char[] chars1 = s1.toCharArray();
		char[] chars2 = s2.toCharArray();

		Arrays.sort(chars1);
		Arrays.sort(chars2);

		final String sortedStr1 = String.valueOf(chars1);
		final String sortedStr2 = String.valueOf(chars2);

		return sortedStr1.equals(sortedStr2);
	}

	public static void main(String... args) {
		final String s1 = "abc";
		final String s2 = "bac";
		final String s3 = "cka";

		System.out.println(s1 + " and " + s2 + " are permutations: " + isPermutation(s1, s2));
		System.out.println(s1 + " and " + s3 + " are permutations: " + isPermutation(s1, s3));
	}
}
