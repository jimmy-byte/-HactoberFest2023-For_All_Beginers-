#include<iostream>
using namespace std;
struct Node *head;
struct Node *curr;
struct Node *previ;

struct Node{
    int value;
    struct Node *next;
};

struct Node *createNode(int item,struct Node *nextnode){
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->value = item;
    newnode->next = nextnode;
    return newnode;
};

void add(int value)
{
    if(head == NULL){
        head = createNode(value,NULL);
    }
    else{
        curr = head;

        while(curr!= NULL){
            if(curr->next == NULL){
                struct Node *newnode = createNode(value,NULL);
                curr->next = newnode;
                return;
            }
            else
            {

                curr = curr->next;
            }
        }
    }
}

void traverse(){
    curr = head;
    cout << "current item: ";
    while(curr!=NULL){
        cout << curr->value << " ";
        curr= curr->next;
    }
    cout << endl << endl;

}

bool findnode(int value)
{
    curr = head;

    while(curr!=NULL){
        if(curr->value == value)
        {

            return true;
        }
        else{
            curr = curr->next;
        }
    }

    return false;
}

void deletealstnode()
{
    curr = head;
    previ = NULL;
    while(curr!=NULL){
        if(curr->next==NULL){
            previ->next =NULL;
            return;
        }
        else{
            previ = curr;
            curr = curr->next;
        }
    }
}

void deleteDirect()
{
    int item;
    cout << "item to delete: ";
    cin >> item;
    if(findnode(item)){
        curr= head;
        previ = NULL;
        if(curr->value == item){
            head = curr->next;
            curr->next = NULL;
            return;
        }
        while(curr!=NULL){
            if(curr->value == item){
                previ->next = curr->next;
                curr->next = NULL;
                return;
            } else {
                previ = curr;
                curr = curr->next;
            }
//            cout << curr->value << " ";
        }
    } else {
        cout << "item is not in list" << endl << endl;
    }
}

void addNodeatFirst(){
    curr = head;
    if(curr == NULL){
        cout << "list is empty"<< endl;
        return;
    }
    previ = NULL;
    int item;
    cout << "item to add: ";
    cin >> item;
    struct Node *temp = createNode(item,curr);
    head = temp;
}

int main()
{
    cout << "||          Linked List          ||" <<endl;
    cout << "=================================="  <<endl;
    cout << "||                                 ||" <<endl;
    cout << "||              option             ||" <<endl;
    cout << "||   Enter 1 to add node           ||" <<endl;
    cout << "||   Enter 2 to find node          ||" <<endl;
    cout << "||   Enter 3 to delete last node   ||" <<endl;
    cout << "||   Enter 4 to directly delete    ||" <<endl;
    cout << "||   Enter 5 to add node at first  ||" <<endl;
    cout << "||   Enter q to exit program       ||" <<endl;
    cout << "|___________________________________|"  <<endl;
    char option = '16';
    while(option != 'q'){
        cout << "option: ";
        cin >> option;
        switch(option){
            case '1': {
                int value;
                cout << "enter value: ";
                cin >> value;
                add(value);
                traverse();
                break;
                }
            case '2':{
                curr = head;
                if(curr == NULL)
                {
                    cout << "No item in list" <<endl;
                    break;
                }
                int value;
                cout << "Enter item to find: ";
                cin >> value;
                if(findnode(value)){
                    cout << "node is in list" << endl;
                } else {
                    cout << "node is NOT in list" << endl;
                }

                break;
            };
            case '3': {
                deletealstnode();
                traverse();
                break;
            }
            case '4': {
                deleteDirect();
                traverse();
                break;
            }
            case '5': {
                addNodeatFirst();
                traverse();
                break;
            }
            default :{
                cout << "invalide option" <<endl;
            }
        }

    }
    return 0;
}
