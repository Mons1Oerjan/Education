package QuickSort;

/**
 * Description:
 *   Pick a an element as the pivot, and partition the input array
 *   around the pivot. Put the pivot in the correct place, then put
 *   all values smaller than the pivot before the pivot, and all values
 *   greater than the pivot after the pivot.
 *
 * Time Complexity: O(n log n)
 *   T(n) = T(k) + T(n - k - 1) + theta(n), where k = # elements < pivot
 *
 *   Worst case: the partition process always picks the greatest or
 *               smallest element as the pivot.
 *               T(n) = T(0) + T(n - 1) + theta(n)
 *                    = T(n - 1) + theta(n)
 *                    ==> theta(n^2)
 *
 *   Best case: the partition process always picks the middle
 *              element as the pivot.
 *              T(n) = 2T(n/2) + theta(n)
 *                   ==> theta(n log n)
 *
 *   Average case: consider all possible permutations.
 *                 theta(n log n)
 *
 * Space Complexity: O(log n) due to the recursive stack calls.
 *
 * Algorithm Paradigm: Divide & Conquer
 *
 * Applications:
 *   - QuickSort is faster than MergeSort and HeapSort in practice because
 *     its inner loop can be efficiently implemented on most architectures
 *     and most datasets. Changing the choice of the pivot based on the
 *     dataset to be sorted can greatly increase performance (see
 *     best / worst case analysis above). However, MergeSort is better on
 *     huge / external datasets.
 *   - Very good at sorting arrays because it's an in-place sort (it doesn't
 *     require any extra space / storage).
 *   - Cache friendly sorting algorithm since it has good locality of
 *     reference when used for arrays.
 */
public class QuickSort {

    /**
     * Driver method
     */
    public void sort(final int[] list) {
        sort(list, 0, list.length - 1);
    }

    /**
     * Recursively sorts all elements before and after the partitionIndex.
     */
    private void sort(
            final int[] list,
            final int startIndex,
            final int endIndex) {
        if (startIndex >= endIndex) return;

        final int partitionIndex = partition(list, startIndex, endIndex);
        sort(list, startIndex, partitionIndex - 1);
        sort(list, partitionIndex + 1, endIndex);
    }

    /**
     * Places the pivot at the correct position in the sorted array,
     * places all smaller elements before the pivot, and all greater
     * elements after the pivot.
     *
     * Note: This method always picks the last element in the list as the pivot.
     */
    private int partition(
            final int[] list,
            final int startIndex,
            final int endIndex) {
        final int pivot = list[endIndex];
        int smallerElementIndex = startIndex - 1;

        for (int i = startIndex; i < endIndex; i++) {
            if (list[i] <= pivot) {
                smallerElementIndex++;

                // swap
                int temp = list[smallerElementIndex];
                list[smallerElementIndex] = list[i];
                list[i] = temp;
            }
        }

        final int partitionIndex = smallerElementIndex + 1;

        // swap pivot
        final int temp = list[partitionIndex];
        list[partitionIndex] = list[endIndex];
        list[endIndex] = temp;

        return partitionIndex;
    }
}
