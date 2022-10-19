#include <stdio.h>
#include<stdlib.h>
int l,u,m;
    int key,n;



int main()
{
    int arr[7]={10,20,30,40,50,60,70};
    
    //printf("enter the value of n\n");
    //scanf("%d",&n);
     key=70;

    l=0;u=6;
    int flag=0;
    while(l<=u)
    {
        m=(l+u)/2;
        if(arr[m]==key)
        {
            flag=1;
            printf("the index is %d\n",m+1);
            break;
        }
        else if(key<arr[m]) u=m-1;
        else l=m+1;
    }
    if (flag==0) printf("the key is not present\n");
    
    return 0;
}