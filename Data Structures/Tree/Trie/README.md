# Trie (Prefix Tree)
A trie is a special case of an n-ary tree where characters are
stored at each node, and every path down the tree may represent
a word in a real language (e.g. English). The paths that are
real words are flagged as complete words by a boolean value.

## Applications
- Storing entire languages for quick prefix lookups.
- Many problems involving lists of valid words uses tries over HashMaps for optimization.

## Complexity
- Time: `O(n)` lookups of words where `n = word.length()`
