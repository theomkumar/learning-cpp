//LIFO -> Last in First order
#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;

    Node (int val)
    {
        this -> val = val;
        next = NULL;
    }
};
Node* top = NULL;

void push(int val)
{
    Node* temp = new Node(val);
    temp -> next = top;
    top = temp;
}

int peek()
{
    if (top == NULL)
    {
        cout << "STACK IS EMPTY! ";
        return -1;
    }
    else
        cout <<"PEEK VALUE IS : ";
        return top -> val;
}

void pop ()
{
    if (top == NULL) 
    {
        cout <<"Stack will underflow!!! \n";
        return;
    }
    Node* temp = top;
    top = top -> next;
    delete temp;
}

bool isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}
int main() 
{
    push(10);
    push(20);
    push(30);
    push(50);

    cout<< peek() <<endl;
    pop();
    pop();
    cout <<peek()<<endl;
    pop();
    pop();
    pop();
    cout <<peek()<<endl;
    push(99);

    if (isEmpty())
    {
        cout << "Stack is emptyy!!";
    }
    else 
        cout << "Stack is not empty!!";

    return 0;
}