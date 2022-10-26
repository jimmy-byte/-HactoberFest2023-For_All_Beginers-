#include<iostream>
using namespace std;
void insertion_sort(int arr[], int l);
int main()
{
    int n,a[n];
    cout<<"Enter the number of values\n";
    cin>>n;
    cout<<"Elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertion_sort(a, n);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
void insertion_sort(int arr[],int l)
{
    {
        for (int step = 1; step < l; step++) {
    int key = arr[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
        arr[j + 1] = key;
    }
    }

}