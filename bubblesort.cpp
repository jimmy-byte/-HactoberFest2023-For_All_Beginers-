#include<iostream>
using namespace std;

int main( )
  {
int counter=0;
int n= 5;
int arr[n]={88,111,01,10,12};
while (counter<n-1)
{
    for(int i=0;i<n-counter-1;i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i]= temp;
        }

    }
    counter++;
}
cout<<"ok";
for (int i = 0; i < n; i++)
{
    cout<< arr[i]<<" ";
}

return 0 ;
}
