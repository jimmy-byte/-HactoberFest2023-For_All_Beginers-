#include<iostream>
using namespace std;
int main()
{
    int mylist[] = {2,34,1,4,8,9,32,21,15};
    int sized = sizeof(mylist) / sizeof(mylist[0]);
    for(int i=0;i<sized;i++){
        for(int j=i+1;j<sized;j++){
            if(mylist[i] > mylist[j]){
                int temp = mylist[i];
                mylist[i] = mylist[j];
                mylist[j] = temp;
            }
        }
    }

    for(int i=0;i<sized;i++){
        cout << mylist[i] << " ";
    }
}
