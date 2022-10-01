#include <iostream>
using namespace std;
int main()
{
    int arr[100];
    int mid, i, num, search;

    cout << "Enter the size of the array: " << endl;
    cin >> num;
    cout << " Enter the values in sorted array: " << endl;

    for (i = 0; i < num; i++)
    {
        cout << " arr [" << i << "] = ";
        cin >> arr[i];
    }

    int st = 0;
    int end = num - 1;
    cout << "Enter the number to be searched from sorted array: " << endl;
    cin >> search;

    while (st <= end)
    {
        mid = (st + end) / 2;
        if (arr[mid] == search)
        {
            cout << " Element is found at index " << (mid);
            exit(0);
        }
        else if (search > arr[mid])
        {
            st = mid + 1;
        }
        else if (search < arr[mid])
        {
            end = mid - 1;
        }
    }
    cout << "Number is not found. " << endl;
    for (int i = num-1; i > mid; i--)
        arr[i + 1] = arr[i];
      arr[mid+1] = search;
    cout << "Array after insertion:- ";
    for (int i = 0; i < num + 1; i++)
        cout << arr[i] << " ";

    return 0;
}
