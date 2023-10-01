#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    std::cout << "Enter the size: ";
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    insertionSort(arr);

    std::cout << "Sorted array: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
