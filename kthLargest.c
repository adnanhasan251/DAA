#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the max heap property
void maxHeapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and go upwards
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to find the k-th largest element using max heap
int findKthLargest(int arr[], int n, int k) {
    buildMaxHeap(arr, n);

    // Extract max k-1 times
    for (int i = n - 1; i >= n - k + 1; i--) {
        // Move the current max to the end
        swap(&arr[0], &arr[i]);
        // Reduce the heap size by 1
        maxHeapify(arr, i, 0);
    }

    // The root element is now the k-th largest
    return arr[0];
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int kthLargest = findKthLargest(arr, n, k);
    printf("The %d-th largest element is %d\n", k, kthLargest);

    return 0;
}
