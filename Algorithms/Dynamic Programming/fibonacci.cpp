#include <iostream>
using namespace std;


/**
 * Function that returns the n-th Fibonacci number 
 * using Dynamic Programming in O(n) time.
 *
 * Algorithm Explanation:
 * If the user inputs 0 or 1, we simply return 0 or 1.
 * We start by initializing an array with num+1 slots. We also set the first 
 * two numbers in the array equal to 0 and 1 (the first two values in the fibonacci 
 * sequence). We then calculate each number in the sequence up to (and including) num 
 * using the formula Fn = Fn-1 + Fn-2. We can solve this in O(n) time using Dynamic 
 * programming due to the recurrence that exist in the formula. Finally, we return the 
 * n-th fibonacci number which is stored in the n-th array index.
 */
int fibonacci(int num) {
	if (num <= 0) return 0;
	if (num == 1) return 1;

	int fib[num+1];
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= num; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	return fib[num];
}


int main(void) {
	cout << "Fibonacci sequence" << "\n" << "Please input the n: ";
	int n;
	cin >> n;
	int fib = fibonacci(n);
	cout << "The Fibonacci number corresponding to " << n << " in the sequence is: " << fib << "\n\n\n";
	return 0;
}