#include<stdio.h>

int main()
{
 int a,b,c;
 char operator;
 
 printf("enter an operator-->");
 scanf("%c",&operator);

 printf("enter the first no.");
 scanf("%d",&a);

 printf("enter the second no.");
 scanf("%d",&b);
 
 switch (operator)
 {
 case'+':printf("ans:%d",a+b);
         break;
 case'-':printf("ans:%d",a-b);
         break;
 case'*':printf("ans:%d",a*b);
         break;
 case'/':printf("ans:%d",a/b);
         break;
 case'%':printf("ans:%d",a%b);
         break;
 default:printf("invalid operator");
   break;
 }
 return 0;
} 
