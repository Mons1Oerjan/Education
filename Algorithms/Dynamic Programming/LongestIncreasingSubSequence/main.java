package LongestIncreasingSubsequence;

public class main {
    public static void main(String... args) {
        final int[] data = {10, 22, 9, 33, 21, 50, 41, 60, 80};
        final LIS LongestIncreasingSubsequence = new LIS();
        final int lis = LongestIncreasingSubsequence.lis(data);
        System.out.println(lis);
    }
}
