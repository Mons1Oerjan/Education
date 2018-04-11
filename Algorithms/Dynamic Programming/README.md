# Dynamic Programming
An algorithmic paradigm which solves a complex problem by breaking it down into subproblems and stores the results of the subproblems to avoid computing the same results again.

## When to use Dynamic Programming?
The two main properties which suggests that a problem can be solved with Dynamic Programming are:
1. Overlapping Subproblems
2. Optimal Substructure

### Overlapping Subproblems
When results from a Divide & Conquer strategy are needed more than once. For example, Binary Search has no common subproblems, but a recursive function to find the n-th fibonacci number solves the same subproblems multiple times:
```
int fibonacci(int n) {
	return (n <= 1) ? n : fib(n-1) + fib(n-2);
}
```

There are two different ways to store values in a table so that they can be reused:
1. Memoization (top-down)
2. Tabulation (bottom-up)

### Optimal Substructure
A given problem has an Optimal Substructure Property if an optimal solution of a given problem can be obtained by using optimal solutions of its subproblems. For example, the Shortest Path graph problem has an Optimal Substructure Property, but the Longest Path graph problem does not.
