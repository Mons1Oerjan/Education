package MergeSort;

/**
 * Description:
 *   Merge Sort is a sorting algorithm which recursively divides the input array
 *   into two halves until the size of the arrays are 1, and then it merges
 *   the two halves together in sorted order.
 *
 * Algorithmic Paradigm: Divide & Conquer
 *
 * Time Complexity: O(n log n)
 *   T(n) = 2T(n/2) + theta(n)
 *        ==> apply Master Theorem's case 2
 *        ==> theta(n log n)
 *
 * Space Complexity: O(n)
 *
 * Applications:
 *   - Sorting LinkedLists in O(n log n) time
 *   - Inversion Count Problem: How close is the input data from being sorted?
 *   - External Sorting: When the data being sorted is too big to fit in the main memory.
 */
public class MergeSort {

    /**
     * Driver method
     */
    public void sort(final int[] list) {
        sort(list, 0, list.length - 1);
    }

    /**
     * Recursively divides the list into two halves until the size becomes 1,
     * and then merges all arrays back into one array in ascending order.
     */
    private void sort(final int[] list, final int left, final int right) {
        if (left >= right) return;

        final int mid = (left + right) / 2;

        sort(list, left, mid);
        sort(list, mid + 1, right);

        merge(list, left, mid, right);
    }

    /**
     * Merges two subarrays from the list back together in ascending order.
     */
    private void merge(
            final int[] list,
            final int left,
            final int mid,
            final int right) {
        // find the size of both subarrays to be merged
        final int leftArraySize = mid - left + 1;
        final int rightArraySize = right - mid;

        // create subarrays
        final int[] leftArray = new int[leftArraySize];
        final int[] rightArray = new int[rightArraySize];

        // copy data to subarrays
        for (int i = 0; i < leftArraySize; i++) {
            leftArray[i] = list[left + i];
        }
        for (int i = 0; i < rightArraySize; i++) {
            rightArray[i] = list[mid + 1 + i];
        }

        int leftArrayIndex = 0;
        int rightArrayIndex = 0;
        int mergedArrayIndex = left;

        // merge subarrays
        while (
            leftArrayIndex < leftArraySize &&
            rightArrayIndex < rightArraySize
        ) {
            if (leftArray[leftArrayIndex] <= rightArray[rightArrayIndex]) {
                list[mergedArrayIndex] = leftArray[leftArrayIndex];
                leftArrayIndex++;
            } else {
                list[mergedArrayIndex] = rightArray[rightArrayIndex];
                rightArrayIndex++;
            }
            mergedArrayIndex++;
        }

        // copy remaining elements of leftArray if any
        while (leftArrayIndex < leftArraySize) {
            list[mergedArrayIndex] = leftArray[leftArrayIndex];
            leftArrayIndex++;
            mergedArrayIndex++;
        }

        // copy remaining elements of rightArray if any
        while (rightArrayIndex < rightArraySize) {
            list[mergedArrayIndex] = rightArray[rightArrayIndex];
            rightArrayIndex++;
            mergedArrayIndex++;
        }
    }
}
