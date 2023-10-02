#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {5, 3, 2, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
/*
step wise explaination 
Start with the second element in the array.
Compare the current element with the elements in the sorted subarray from right to left.
Shift elements greater than the current element one position to the right to make space for the current element.
Repeat steps 2 and 3 until the current element is smaller than or equal to the first element in the sorted subarray.
Place the current element at its correct position in the sorted subarray.
Repeat steps 1-5 for the remaining elements in the unsorted subarray.
Insertion sort is a stable sorting algorithm, which means that it preserves the original order of equal elements in the sorted array. It is also a relatively inefficient sorting algorithm, but it is simple to implement and understand.
*/
