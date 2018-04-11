package LongestCommonSubsequence;

public class main {
    public static void main(String... args) {
        final LCS LongestCommonSubsequence = new LCS();
        final String s1 = "AGGTAB";
        final String s2 = "GXTXAYB";
        final int lcsLength = LongestCommonSubsequence.lcs(s1, s2);
        System.out.println(lcsLength);
    }
}
