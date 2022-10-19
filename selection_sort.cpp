#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter number of elements in array : ";
    cin >> size;
    int arr[11];
    cout << "Enter elements of array " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }

    cout<<"Sorted array "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}