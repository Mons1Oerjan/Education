public class q1 {

    public static void main(String... args) {
        final int N = 1024;   // 10000000000
        final int M = 19;     // 00000010011
        final int result = insertBits(N, M, 2, 6);

        if (result == -1) {
            System.out.println("Error");
        } else {
            System.out.println("Expecting: 1100");   // 10001001100
            System.out.println("Result: " + result);
        }
    }

    /**
     * Given two 32-bit numbers and two bit positions, insert
     * M into N such that M starts at bit j and ends at bit i.
     * Assume that the bits j through i have enough space to fit all of M.
     *
     * @param N a 32-bit number
     * @param M a 32-bit number
     * @param i a bit position
     * @param j a bit position
     * @return int the result after insertion.
     */
    private static int insertBits(
            final int N,
            final int M,
            final int i,
            final int j) {
        if (i > j) return -1;

        // Step 1: Clear the bits j to i in N
        final int allOnes = ~0;                 // e.g. 11111111
        final int left = allOnes << (j + 1);    // e.g. 11100000
        final int right = (1 << i) - 1;         // e.g. 00000111
        final int mask = left | right;          // e.g. 11100111
        final int n = N & mask;                 // clear bits j to i

        // Step 2: Shift M so that it lines up with bits j to i
        final int m = M << i;                   // move M into correct position

        // Step 3: Merge M and N
        return n | m;
    }
}
