import java.lang.Math;

public class q3 {

    public static void main(String... args) {
        System.out.println("11011101111 - Longest sequence of 1s after bit flip is: "
            + flipBitToWin(1775));
    }

    /**
     * Flips a 0 bit to a 1 where the longest consecutive
     * number of 1s occurs.
     *
     * @param num the input number.
     * @return int the length of the longest sequence of 1s after the bit flip.
     */
    private static int flipBitToWin(int num) {
        // if all 1s, then this is already the longest sequence.
        if (~num == 0) return Integer.BYTES * 8;

        int currSeqLen = 0;
        int prevSeqLen = 0;
        int maxSeqLen = 1; // due to the bit flip, the minimum sequence len is one 1.

        while (num != 0) {
            final int currBit = num & 1;
            final int nextBit = num & 2;

            if (currBit == 1) {
                currSeqLen++;
            } else if (currBit == 0) {
                prevSeqLen = (nextBit == 0)
                    ? 0
                    : currSeqLen;
                currSeqLen = 0;
            }

            maxSeqLen = Math.max(prevSeqLen + currSeqLen + 1, maxSeqLen);

            // logically right shift num by 1
            num = num >>> 1;
        }

        return maxSeqLen;
    }
}
