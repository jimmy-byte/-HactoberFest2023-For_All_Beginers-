#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int arr1[n1];
    int arr2[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr[k++] = arr2[j++];
    }
}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int n;
    cout << "Enter size of array";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) // enter array elements
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "Array after sorting ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
