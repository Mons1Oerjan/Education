package LongestIncreasingSubsequence;

public class LIS {

    private static final int BASE_CASE = 1;

    public int lis(final int[] data) {
        return lis(data, data.length);
    }

    private int lis(final int[] data, final int len) {
        if (len == BASE_CASE) return BASE_CASE;
        int max = 1;

        for (int i = 1; i < len; i++) {
            final int result = lis(data, i);
            if (data[i - 1] < data[len - 1] && result + 1 > max) {
                max = result + 1;
            }
        }

        return max;
    }
}
