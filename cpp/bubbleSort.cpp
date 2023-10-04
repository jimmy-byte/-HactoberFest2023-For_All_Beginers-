#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int arr[],int n){
    int flag = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}
int main()
{
    int a[] = {7,9,14,5,1};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Unsorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    BubbleSort(a,n);
    cout<<"Sorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}