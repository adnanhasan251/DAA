#include <stdio.h>
#include <stdbool.h>

// Function to find if there is a subset with sum equal to sum/2
bool canPartition(int arr[], int n) {
    int totalSum = 0;
    
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // If total sum is odd, partitioning into two equal subsets is not possible
    if (totalSum % 2 != 0) {
        return false;
    }

    int target = totalSum / 2;
    
    // Create a dp array to store results of subproblems
    bool dp[target + 1];
    
    // Initialize dp[0] as true (sum of 0 is always possible)
    dp[0] = true;
    
    // Initialize remaining dp values as false
    for (int i = 1; i <= target; i++) {
        dp[i] = false;
    }
    
    // Fill the dp array
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    
    // The answer will be in dp[target]
    return dp[target];
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (canPartition(arr, n)) {
        printf("The array can be partitioned into two subsets with equal sum.\n");
    } else {
        printf("The array cannot be partitioned into two subsets with equal sum.\n");
    }

    return 0;
}
