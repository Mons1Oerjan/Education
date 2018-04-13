# Edit Distance

## The Problem
Given two strings, calculate how many operations we must make to make string1 equal to string2.

The operations are:
- Inserting a character
- Removing a character
- Replacing a character

## The Solution
This can be solved using Dynamic Programming in `O(i * j)` time, where `i = string1.length()` and `j = string2.length()`.

## Compile Program
`javac EditDistance.java`

## Run Program
- To run the program with sample tests, run this command: `java EditDistance`
- To run the program with your own input, run this command: `java EditDistance "<your_input_string1>" "<your_input_string2>"`
