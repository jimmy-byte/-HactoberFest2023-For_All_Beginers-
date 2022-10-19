#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Node
{
    struct Node *right;
    char data;
};

typedef struct Node node;
node *top1 = 0;
node *here = 0;
char popped;

int isop(char ch)
{
    if (ch == '^' || ch == '*' || ch == '/' || ch == '-' || ch == '+')
        return 1;
    else
        return 0;
}

int priority_check(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int is_empty(node *top)
{
    if (top == 0)
        return 1;
    else
        return 0;
}

node *push(node *top, char c)
{
   // printf("here\n");
    node *new = (node *)malloc(sizeof(node));
    if (top == 0)
    {
        top = new;
        new->right = 0;
    }
    else
    {
        new->right = top;
        top = new;
    }
    new->data = c;
    return top;
}

node *pop(node *top)
{
    if (!is_empty(top))
    {
        popped = top->data;
        node *g = top;
        top = top->right;
        free(g);
    }
    else
    {
        printf("the stack is empty!!!\n");
        // return -1;
    }
    return top;
}

void display(node *top)
{
    node *p = top;
    while (p != 0)
    {
        printf("%d ", p->data);
        p = p->right;
    }
    printf("\n");
}

int main()
{
    char *str;
    int n;
    printf("enter the value of n\n");
    scanf("%d", &n);
    str = (char *)malloc((n + 1) * sizeof(char));
    printf("enter the infix expression\n");
    scanf("%s", str);
    // printf("here");
    for (int i = 0; i < strlen(str); i++)
    {
        // printf("%c",str[i]);
        if (isalnum(str[i]))
        {
            printf("%c", str[i]);
        }
        else if (str[i] == '(')
            top1 = push(top1, str[i]);
        else if (str[i] == ')')
        {
            while (top1->data != '(')
            {
                top1=pop(top1);
                printf("%c", popped);
            }
            top1=pop(top1);
        }
        else if (isop(str[i]))
        {

            if (is_empty(top1))
                top1=push(top1, str[i]);
            else if (top1->data == '(')
                top1=push(top1, str[i]);
            else if (priority_check(str[i]) > priority_check(top1->data))
                top1=push(top1, str[i]);
            else
            {
                //printf("  hera  ");
                while (!(is_empty(top1) || top1->data == '(' || priority_check(str[i]) > priority_check(top1->data)))
                {
                    top1=pop(top1);
                    printf("%c", popped);
                }
                top1=push(top1, str[i]);
            }
        }
    }
    //printf("..%d\n",is_empty(top1));
    while (!is_empty(top1))
    {
        //printf("here\n");
        top1=pop(top1);
        printf("%c", popped);
    }
    return 0;
}