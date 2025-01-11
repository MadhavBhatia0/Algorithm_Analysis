#include <bits/stdc++.h>
using namespace std;

// Structure to represent a Job
struct Job {
    char id;     // Job ID
    int profit;  // Profit from the job
    int deadline; // Deadline for the job
};

// Comparator function to sort jobs in decreasing order of profit
bool compare(Job a, Job b) {
    return a.profit > b.profit; // Sort in descending order of profit
}

// Function to find the maximum profit job sequence
void jobSequence(Job jobs[], int n) {
    // Sort jobs based on their profit in descending order
    sort(jobs, jobs + n, compare);

    int result[n]; // Array to store the sequence of jobs
    bool time[n];  // Array to keep track of available time slots

    // Initially, all time slots are free
    for (int i = 0; i < n; i++)
        time[i] = false;

    // Iterate through all the jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!time[j]) {  // If the slot is free
                result[j] = i;  // Assign this job to the slot
                time[j] = true; // Mark the slot as filled
                break;
            }
        }
    }

    // Print the result (the sequence of jobs)
    for (int i = 0; i < n; i++) {
        if (time[i]) {
            cout << jobs[result[i]].id << ' ';
        }
    }
}

// Driver code
int main() {
    // Array of jobs
    Job jobs[] = { { 'A', 70, 4 },
                   { 'B', 20, 1 },
                   { 'C', 30, 2 },
                   { 'D', 40, 1 },
                   { 'E', 60, 3 } };
    
    int n = sizeof(jobs) / sizeof(jobs[0]);
    
    cout << "The maximum profit can be achieved by doing the following jobs in sequence:\n";
    
    // Function call to find the job sequence
    jobSequence(jobs, n);
    
    return 0;
}
