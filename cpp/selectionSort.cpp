#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int a[],int n){
    int Min;
    for(int i = 0;i<n-1;i++){
        Min = i;
        for(int j = i+1;j<n;j++){
            if(a[j]<a[Min])
                Min = j;
        }
        swap(&a[i],&a[Min]);
    }
}
int main()
{
    int arr[] = {7,9,14,5,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    SelectionSort(arr,n);
    cout<<"Sorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}