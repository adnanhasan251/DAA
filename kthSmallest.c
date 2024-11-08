#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain min-heap property
void minHeapify(int arr[], int n, int i) {
    int smallest = i;          // Initialize smallest as root
    int left = 2 * i + 1;      // Left child
    int right = 2 * i + 2;     // Right child

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to build the min-heap
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to extract the root (minimum element) from the heap
int extractMin(int arr[], int *n) {
    if (*n <= 0)
        return -1;
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }

    // Store the minimum value and remove it from the heap
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);

    return root;
}

// Function to find the kth smallest element using min-heap
int kthSmallestHeap(int arr[], int n, int k) {
    // Step 1: Build a min-heap from the array
    buildMinHeap(arr, n);

    // Step 2: Extract the minimum element k times
    for (int i = 0; i < k - 1; i++) {
        extractMin(arr, &n);
    }

    // The root now contains the kth smallest element
    return arr[0];
}

int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Kth smallest element is %d\n", kthSmallestHeap(arr, n, k));
    return 0;
}
