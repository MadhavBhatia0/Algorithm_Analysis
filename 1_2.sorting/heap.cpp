#include <iostream>
using namespace std;

void heapifyArray(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapifyArray(arr, n, largest);
  }
}

void sortArray(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapifyArray(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapifyArray(arr, i, 0);
  }
}

void displayArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";
}

int main() {
  int arr[] = {1, 12, 9, 5, 6, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  sortArray(arr, n);

  cout << "Sorted array is \n";
  displayArray(arr, n);
}
