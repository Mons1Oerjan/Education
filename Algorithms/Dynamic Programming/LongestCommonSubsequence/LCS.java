package LongestCommonSubsequence;

public class LCS {

    public int lcs(final String s1, final String s2) {
        return lcs(s1.toCharArray(), s2.toCharArray());
    }

    private int lcs(final char[] c1, final char[] c2) {
        final int len1 = c1.length;
        final int len2 = c2.length;
        final int[][] table = new int[len1+1][len2+1];

        // build the DP table in tabular (bottom-up) fashion
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 || j == 0)
                    table[i][j] = 0;
                else if (c1[i - 1] == c2[j - 1])
                    table[i][j] = table[i - 1][j - 1] + 1;
                else
                    table[i][j] = maxNum(table[i - 1][j], table[i][j - 1]);
            }
        }

        return table[len1][len2];
    }

    private int maxNum(final int x, final int y) {
        return x > y ? x : y;
    }
}
