import java.lang.StringBuilder;

public class q2 {

    public static void main(String... args) {
        double n = 0.75;
        System.out.println(n + ": " + printDoubleInBinary(n));
        n = 0.9375 + 0.015625;
        System.out.println(n + ": " + printDoubleInBinary(n));
        n = 0.79;
        System.out.println(n + ": " + printDoubleInBinary(n));
        n = 1.2;
        System.out.println(n + ": " + printDoubleInBinary(n));
        n = -5.0;
        System.out.println(n + ": " + printDoubleInBinary(n));
    }

    /**
     * Prints a real number between 0 and 1 in binary representation.
     * Prints "ERROR" if the number can't be represented in 32 chars.
     *
     * @param num the number to print in binary.
     */
    private static String printDoubleInBinary(double num) {
        if (num >= 1 || num <= 0) return "ERROR: invalid input.";

        final StringBuilder binaryString = new StringBuilder();
        binaryString.append(".");

        while (num > 0) {
            if (binaryString.length() >= 32) return "ERROR: binary string too long.";

            final double r = num * 2;

            if (r >= 1) {
                binaryString.append(1);
                num = r - 1;
            } else {
                binaryString.append(0);
                num = r;
            }
        }

        return binaryString.toString();
    }
}
