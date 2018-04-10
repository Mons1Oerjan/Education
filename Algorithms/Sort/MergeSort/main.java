package MergeSort;

public class main {

    private static final MergeSort mergeSort = new MergeSort();

    public static void main(String... args) {
        final int[] data = {0, 7, 4, 9, 2, 3, 6, 8, 1, 12, 10, 20, 5};
        mergeSort.sort(data);
        printArray(data);
    }

    private static void printArray(final int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + ", ");
        }
        System.out.println("]");
    }
}
