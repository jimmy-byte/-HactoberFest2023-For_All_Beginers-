#include <iostream>
#include <string.h>
using namespace std;

// function definition of the revstr()
void revstr(char *str1) {
    // declare variable
    int i, len, temp;
    len = strlen(str1);

    // use strlen() to get the length of str string
    // use or loop to iterate the string
    for(i = 0;i < len/2;i++)
    {
        //temp variable use to temporary hold the string
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}
int main()
{
    char str[50] = "Priyanka";
    cout << "Before reversing the string: " << str;

    revstr(str);
    
    cout<< "\nAfter reversing the string: " << str;
    return 0;
}
