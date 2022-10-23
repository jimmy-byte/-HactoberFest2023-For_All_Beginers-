#include<stdio.h> 

void Fibonacci(int n){    
    static int n1=0,n2=1,n3;    
    if(n>0){    
         n3 = n1 + n2;  // sum of the previous two elements  
         n1 = n2;    
         n2 = n3;    
         printf("%d ",n3);    
         Fibonacci(n-1);    
    }    
}    
int main(){    
    int n;    
    // takes user input for the number of elements 
    printf("Enter the number of elements: ");    
    scanf("%d",&n);
    // prints the fibonacci series    
    printf("Series: ");    
    printf("%d %d ",0,1); // the first two elements are 0 and 1 
    // calling the fibonacci function 
    Fibonacci(n-2); //n-2 because 2 numbers are already printed    
  return 0;  
 }    