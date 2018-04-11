# Longest Common Subsequence
## Problem
Given two sequences, find the length of the longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

## Example
`LCS(“AGGTAB”, “GXTXAYB”) = “GTAB”` ==> `length = 4`

## Solution
We can solve this most efficiently using the Tabulation strategy in O(n1 * n2) time, where n1 = length of input-string-1, and n2 = length of input-string-2.

## Applications
- the basis of diff
- BioInformatics
