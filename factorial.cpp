#include <iostream>

using namespace std;

int factorial(int num)
{
    if(num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int main()
{
    int num;
    cout<<"Enter the number to calculate it's factorial: ";
    cin>>num;
    int result = factorial(num);
    cout<<endl<<"It's factorial = "<<num<<"! = "<<result;
    return 0;
}
