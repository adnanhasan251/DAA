#include <stdio.h>

void findMinMax(int arr[], int n, int *min, int *max) {
    // Initialize min and max to the first element
    *min = arr[0];
    *max = arr[0];
    
    // Traverse the array to find min and max
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i]; // Update min
        }
        if (arr[i] > *max) {
            *max = arr[i]; // Update max
        }
    }
}

int main() {
    int arr[] = {3, 5, 1, 7, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, n, &min, &max);

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
