public class BitManipulationUtils {

    /**
     * Gets the bit at the given index in the given number.
     *
     * @param num the number to get the bit from.
     * @param i the index of the bit to get.
     * @return boolean the bit value
     */
    public boolean getBit(final int num, final int i) {
        // shift 1 over by i bits (e.g. 00100000)
        // AND with num to clear all other bits
        // compare to 0 and return the respective boolean value
        return (num & (1 << i)) != 0;
    }

    /**
     * Sets the bit at the given index in the given number.
     *
     * @param num the number to set the bit in.
     * @param i the index of the bit to set.
     * @return int the new number
     */
    public int setBit(final int num, final int i) {
        // shift 1 over by i bits (e.g. 00100000)
        // OR with num, to change only the value at bit i.
        return num | (1 << i);
    }

    /**
     * Clears the bit at the given index in the given number.
     *
     * @param num the number to clear the bit from.
     * @param i the index of the bit to clear.
     * @return int the new number
     */
    public int clearBit(final int num, final int i) {
        // create a number like 11101111
        final int mask = ~(1 << i);
        // AND with num to clear the ith bit
        return num & mask;
    }

    /**
     * Clears all bits from MSB to i, inclusive.
     *
     * @param num the number to clear the bit from.
     * @param i the index of the bit to clear.
     * @return int the new number
     */
    public int clearBitsMSBthroughI(final int num, final int i) {
        // create a mask like 00010000 and subtract 1, resulting in 00001111
        final int mask = (1 << i) - 1;
        // AND with num to clear all bits up to i, including i.
        return num & mask;
    }

    /**
     * Clears all bits from i to LSB, inclusive.
     *
     * @param num the number to clear the bit from.
     * @param i the index of the bit to clear.
     * @return int the new number
     */
    public int clearBitsIthroughLSB(final int num, final int i) {
        // create a mask like 11111111 (this is -1), and leftshift by i+1 bits.
        // this creates a mask like 11110000
        final int mask = (-1 << (i + 1));
        // AND with num to clear all bits from i to LSB
        return num & mask;
    }

    /**
     * Updates the ith bit to the given bit value in num.
     *
     * @param num the number to update the bit in.
     * @param i the index of the bit to update.
     * @param bit the value of the updated bit.
     * @return int the new number
     */
    public int updateBit(final int num, final int i, final boolean bit) {
        final int value = bit ? 1 : 0;
        // create a mask like 11101111
        final int mask = ~(1 << i);
        // shift value left i times to create a sequence like 000value0000
        // AND num and mask to clear the ith bit in num
        // OR these two together to update the ith bit if value = 1
        return (num & mask) | (value << i);
    }
}
