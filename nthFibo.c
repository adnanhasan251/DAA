#include <stdio.h>

// Define the maximum size for the Fibonacci array
#define MAX 1000

// Function to calculate nth Fibonacci number using memoization
int fibonacci(int n, int memo[]) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // If the value has already been computed, return it from the memo table
    if (memo[n] != -1) {
        return memo[n];
    }

    // Otherwise, calculate the Fibonacci value and store it in the memo table
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    
    return memo[n];
}

int main() {
    // Array to store Fibonacci numbers
    int memo[MAX];
    
    // Initialize the memo array with -1 (indicating that no Fibonacci number has been calculated yet)
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }

    int n = 10; // Example: Find the 10th Fibonacci number
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n, memo));

    return 0;
}
