#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    int id;      // Job ID
    int deadline; // Job deadline
    int profit;   // Profit if job is completed before or on the deadline
} Job;

// Comparator function for sorting jobs by profit in descending order
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

// Function to find the maximum deadline in the job list
int findMaxDeadline(Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

// Function to schedule jobs to maximize profit
void jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // Find the maximum deadline to define the number of slots
    int maxDeadline = findMaxDeadline(jobs, n);
    int slots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = -1; // Initialize all slots to -1 (empty)
    }

    int totalProfit = 0;
    int jobCount = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        // Try to place job in its latest possible slot (before or on deadline)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id; // Assign job ID to slot
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    // Print the scheduled jobs and the maximum profit
    printf("Scheduled Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i] != -1) {
            printf("Job%d ", slots[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
