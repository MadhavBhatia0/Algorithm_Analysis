#include <bits/stdc++.h>
using namespace std;

struct Item {
    float weight;
    int value;
};

struct Node {
    int level, profit, bound;
    float weight;
};

bool compareItems(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

int calculateBound(Node u, int n, int capacity, Item arr[]) {
    if (u.weight >= capacity)
        return 0;

    int profitBound = u.profit;
    int totalWeight = u.weight;
    int j = u.level + 1;

    while ((j < n) && (totalWeight + arr[j].weight <= capacity)) {
        totalWeight += arr[j].weight;
        profitBound += arr[j].value;
        j++;
    }

    if (j < n)
        profitBound += (capacity - totalWeight) * arr[j].value / arr[j].weight;

    return profitBound;
}

int knapsack(int capacity, Item arr[], int n) {
    sort(arr, arr + n, compareItems);
    queue<Node> nodeQueue;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    nodeQueue.push(u);

    int maxProfit = 0;
    while (!nodeQueue.empty()) {
        u = nodeQueue.front();
        nodeQueue.pop();

        if (u.level == -1)
            v.level = 0;
        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= capacity && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = calculateBound(v, n, capacity, arr);

        if (v.bound > maxProfit)
            nodeQueue.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, capacity, arr);

        if (v.bound > maxProfit)
            nodeQueue.push(v);
    }

    return maxProfit;
}

int main() {
    int capacity = 10;
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum possible profit = " << knapsack(capacity, arr, n);
    return 0;
}
