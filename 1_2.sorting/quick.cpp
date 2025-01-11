#include <iostream>
using namespace std;

void swapElements(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void displayArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int partitionArray(int array[], int low, int high) {
  int pivot = array[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swapElements(&array[i], &array[j]);
    }
  }

  swapElements(&array[i + 1], &array[high]);
  return i + 1;
}

void sortArray(int array[], int low, int high) {
  if (low < high) {
    int pi = partitionArray(array, low, high);
    sortArray(array, low, pi - 1);
    sortArray(array, pi + 1, high);
  }
}

int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);

  cout << "Unsorted Array: \n";
  displayArray(data, n);

  sortArray(data, 0, n - 1);

  cout << "Sorted array in ascending order: \n";
  displayArray(data, n);
}
