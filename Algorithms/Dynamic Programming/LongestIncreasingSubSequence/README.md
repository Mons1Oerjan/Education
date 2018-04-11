# Longest Increasing Subsequence
## Problem
This problem is about finding the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

For example, the LIS of the array `[10, 22, 9, 33, 21, 50, 41, 60, 80]` is `[10, 22, 33, 50, 60, 80]`.

## Solution
This problem can be solved using Dynamic Programming's Optimal Substructure technique.

Let `arr[0..n-1]` be the input array.
Let `L(i)` be the length of the LIS ending at index `i` such that `arr[i]` is the last element of the LIS.

Then, `L(i)` can be recursively defined as:
```
L(i) = 1 + max(L(j)) where 0 < j < i and arr[j] < arr[i]
or
L(i) = 1, if no such j exists.
```

To find the LIS, simply return `max(L(i))` where `0 < i < n`.
