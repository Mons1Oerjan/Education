public class q9 {
	private static boolean isRotation(final String s1, final String s2) {
		return (s1.length() == s2.length()) && (s1+s1).contains(s2);
	}

	public static void main(String... args) {
		final String s1 = "stackoverflow";
		final String s2 = "overflowstack";
		final String s3 = "overflowstakk";

		System.out.println(s2 + " is a rotation of " + s1 + ": " + isRotation(s1, s2));
		System.out.println(s3 + " is a rotation of " + s1 + ": " + isRotation(s1, s3));
	}
}
