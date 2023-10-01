//implementation of circular queue using c language


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 5
void cqinsert();
void cqdelete();
void cqdisplay();
int cqueue[MAXSIZE];
int front=-1,rear=-1;
int main()
{
int choice;
while(1)
{
printf("\nSTATIC IMPLEMENTATION OF CIRCULAR QUEUE");
printf("\n-------------------------------------");
printf("\n1. Insert");
printf("\n2. Delete");
printf("\n3. Traverse");
printf("\n4. Exit");
printf("\n-------------------------------------");
printf("\n\nEnter your choice [1/2/3/4] : ");
scanf("%d",&choice);
switch(choice)
{
case 1 : cqinsert();
break;
case 2 : cqdelete();
break;
case 3 : cqdisplay();
break;
case 4 : exit(0);
default : printf("\nInvalid choice");
}
getch();
}
}
// Function to insert element in the Circular Queue
void cqinsert()
{
int num;
if(front==(rear+1)%MAXSIZE)
{
printf("\nQueue is Full(Queue overflow)");
return;
}
printf("\nEnter the element to be inserted in circular queue : ");
scanf("%d",&num);
if(front==-1)
front=rear=0;
else
rear=(rear+1) % MAXSIZE;
cqueue[rear]=num;
}
// Function to delete element from the circular queue
void cqdelete()
{
int num;
if(front==-1)
{
printf("\nQueue is Empty (Queue underflow)");
return;
}

num=cqueue[front];
printf("\nDeleted element from circular queue is : %d",num);
if(front==rear)
front=rear=-1;
else
front=(front+1)%MAXSIZE;
}
// Function to display circular queue
void cqdisplay()
{
int i;
if(front==-1)
{
printf("\nQueue is Empty (Queue underflow)");
return;
}
printf("\n\nCircular Queue elements are : \n");
for(i=front;i<=rear;i++)
printf("\ncqueue[%d] : %d",i,cqueue[i]);
if(front>rear)
{
for(i=0;i<=rear;i++)
printf("cqueue[%d] : %d\n",i,cqueue[i]);
for(i=front;i<MAXSIZE;i++)
printf("cqueue[%d] : %d\n",i,cqueue[i]);
}
}
