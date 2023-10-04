#include <iostream>
using namespace std;
void InsertionSort(int a[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        int j = i - 1;
        while (j > 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
int main()
{
    int arr[] = {5, 3, 87, 29, 2, 69, 41};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    InsertionSort(arr, n);
    cout << "Sorted array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}