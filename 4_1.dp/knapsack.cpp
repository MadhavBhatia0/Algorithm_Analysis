#include <iostream>
using namespace std;

int findMax(int x, int y) {
   return (x > y) ? x : y;
}

int calculateKnapsack(int capacity, int weights[], int values[], int itemCount) {
   int i, wt;
   int dpTable[itemCount + 1][capacity + 1];

   for (i = 0; i <= itemCount; i++) {
      for (wt = 0; wt <= capacity; wt++) {
         if (i == 0 || wt == 0)
            dpTable[i][wt] = 0;
         else if (weights[i - 1] <= wt)
            dpTable[i][wt] = findMax(values[i - 1] + dpTable[i - 1][wt - weights[i - 1]], dpTable[i - 1][wt]);
         else
            dpTable[i][wt] = dpTable[i - 1][wt];
      }
   }
   return dpTable[itemCount][capacity];
}

int main() {
   cout << "Enter the number of items in a Knapsack: ";
   int itemCount, capacity;
   cin >> itemCount;

   int values[itemCount], weights[itemCount];
   for (int i = 0; i < itemCount; i++) {
      cout << "Enter value and weight for item " << i << ": ";
      cin >> values[i];
      cin >> weights[i];
   }

   cout << "Enter the capacity of the knapsack: ";
   cin >> capacity;

   cout << "Maximum value: " << calculateKnapsack(capacity, weights, values, itemCount);
   return 0;
}
