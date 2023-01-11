#include<stdio.h>
#include<stdlib.h>

struct node {

    int info;
    struct node *link;
};

struct node *addatbeg(struct node *start, int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;

    return start;
}

struct node *addatend(struct node *start, int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;

    struct node *ptr=start;

    while(ptr->link!=NULL) ptr=ptr->link;
    ptr->link=temp;
    temp->link=NULL;

    return start;
}
struct node *create_list(struct node *start){

    int n;
    printf("Enter the number of nodes : ");
	scanf("%d",&n);

    start=NULL;

    if(n==0){
        printf("List is empty\n");
    }

    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    start=addatbeg(start, data);

    for(int i=2; i<=n; i++){
         printf("Enter the data to be inserted: ");
         scanf("%d", &data);
         start=addatend(start, data);
    }
    return start;

}

void display(struct node *start){

    struct node *ptr=start;
    if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
    
    printf("List contains data: \n");
    while(ptr!=NULL){
        printf("%d ", ptr->info);
        ptr=ptr->link;
    }

    printf("\n\n");


}
struct node* deletealternate(struct node *start){

    struct node *ptr=start;

    while(ptr!=NULL && ptr->link!=NULL){
        ptr->link=ptr->link->link;
        ptr=ptr->link;
    }

    return start;
}
int main(){

    struct node *start=NULL;
    start=create_list(start);
    display(start);
    
    start=deletealternate(start);
    display(start);
    return 0;
}