#include <stdio.h>
#include <stdlib.h>

// Structure for an item
typedef struct Item {
    int weight;
    int value;
} Item;

// Comparator function for sorting items by value-to-weight ratio in descending order
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    double r1 = (double)item1->value / item1->weight;
    double r2 = (double)item2->value / item2->weight;
    return (r1 < r2) ? 1 : -1;
}

// Function to calculate the maximum profit for the fractional knapsack problem
double fractionalKnapsack(Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0; // Total value in knapsack
    int currentWeight = 0;   // Current weight in knapsack

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding the full item doesn't exceed capacity, take it
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } 
        // Otherwise, take the fraction of the item that fits
        else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    // Define items with weights and values
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    double maxProfit = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxProfit);

    return 0;
}
