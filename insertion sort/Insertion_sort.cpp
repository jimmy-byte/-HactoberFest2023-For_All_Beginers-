#include<iostream>
using namespace std;

void display(int arr[],int size)
{
    cout<<"Sorted Array :- ";
    for(int i =0 ; i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insertion_sort(int arr[],int size)
{
    for(int i=1 ; i<=size-1 ; i++)          // No of passes.
    {
        int key = arr[i];
        int j = i-1;
        while(arr[j]>key && j>=0)           // No of comparision for each pass
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
}

int main()
{
   
    int size;
     int arr[100];
    cout<<"Enter the size of an Array :-";
    cin>>size;
    for(int i=0 ;i<size ; i++)
    {
        cin>>arr[i];
    }

    insertion_sort(arr,size);

    cout<<endl;

    display(arr,size);

    return 0;

}