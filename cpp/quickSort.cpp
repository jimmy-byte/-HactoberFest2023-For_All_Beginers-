#include<iostream>
using namespace std;
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int low ,int high){
    int i = low - 1;
    int p = a[high];
    for(int j = low;j<high;j++){
        if(a[j]<p){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}
void QuickSort(int a[],int low, int high){
    if(low<high){
        int p = partition(a,low,high);
        QuickSort(a,low,p-1);
        QuickSort(a,p+1,high);
    }
}
int main()
{
    int arr[] = {7,2,56,12,3,1,92,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array : ";
    for(int i  = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    QuickSort(arr,0,n-1);
    cout<<"Sorted Array : ";
    for(int i  = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }
    return 0;
}