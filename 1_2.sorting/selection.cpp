#include <iostream>
using namespace std;

void swapElements(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void displayArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void sortArray(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int minIndex = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[minIndex])
        minIndex = i;
    }
    swapElements(&array[minIndex], &array[step]);
  }
}

int main() {
  int data[] = {20, 12, 10, 15, 2};
  int size = sizeof(data) / sizeof(data[0]);
  sortArray(data, size);
  cout << "Sorted array in Ascending Order:\n";
  displayArray(data, size);
}
