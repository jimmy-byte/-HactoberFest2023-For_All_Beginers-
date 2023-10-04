
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int findMax(int arr[], int n)
{
    int i,max=arr[0],cnt=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    while(max>0)
    {
        cnt++;
        max=max/10;
    }
   
    return cnt;
}

void bucketSort(int arr[],int *bct[],int n)
{
    int c=0;
    c=findMax(arr,n);

     int i,j[10],k,l,d=1;

    for(int m=0;m<c;m++)
    {
        for(i=0;i<10;i++)
            j[i]=0;
        for(i=0;i<n;i++)
        {
            k=(arr[i]/d)%10;
            bct[k][j[k]]=arr[i];
            j[k]++;
        }
     
        l=0;
        for(i=0;i<10;i++)
        {
            for(k=0;k<j[i];k++)
            {
                arr[l]=bct[i][k];
                l++;
            }
        }
        d*=10;
    }
}
int main()
{
    int n=0;
    int *bct[10];
    cout<<"Enter total no of element : ";
    cin>>n;
 int arr[n+1];
    for(int i=0;i<10;i++)
        bct[i]=new int[n];
    cout<<"Enter array element : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bucketSort(arr,bct,n);
   
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
