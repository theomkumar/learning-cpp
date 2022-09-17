//not complete
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *next;
};
struct node* top = NULL;

void push(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> val = val;
    newNode -> next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow \n");
        return;
    }
    struct node* temp = top;
    top = top -> next;
    free(temp);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack underflow \n");
        return;
    }
    struct node* temp = top;
    while (temp -> next)
    {
        printf("%d",temp -> val);
        temp = temp -> next;
    }
}
int main()
{    
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    pop();
    // display();
}