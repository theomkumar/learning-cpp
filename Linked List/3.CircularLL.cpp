#include<iostream>
using namespace std;
// do while loop -> executes atleast one time, as it executes then check the condition.

class Node 
{
    public:
    int data;
    Node* next;
    //constructor
    Node (int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
    // destructor
    ~Node ()
    {
        int value = this -> data;
        if (this -> next != NULL)
        {
            next = NULL;
        }
        cout << "Heap memory free for data: " << value << '\n';
    }
};

void insertNode (Node* &tail, int element, int d)
{
    //assuming that the element is present in LL

    //empty LL
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        temp -> next = temp;
        tail = temp;
    }
    else 
    {
        //non-empty assuming element is present in the list
        Node *curr = tail;

        while (curr -> data != element)
        {
            curr = curr -> next;
        }
        // element is present in current node
        Node *temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail, int element)
{
    //empty list
    if (tail == NULL)
    {
        cout <<"List empty";
        return;
    }

    Node *prev = tail;
    Node *curr = prev -> next;

    while (curr -> data != element)
    {
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;
    if (tail == curr) // to make sure we don't delete tail
    {
        tail = prev;
    }
    delete curr;
}

void print(Node* &tail)
{
    Node *temp = tail;
    do 
    {
        cout << temp -> data <<' ';
        temp = temp -> next;
    } 
    while (temp != tail);
    cout <<'\n';
}
int main() 
{
    Node* tail = NULL;
    insertNode(tail, 1, 12);
    insertNode(tail, 12, 14);
    insertNode(tail, 14, 17);
    insertNode(tail, 12, 13);
    insertNode(tail, 17, 25);
    insertNode(tail, 25, 26);
    insertNode(tail, 25, 29);
    insertNode(tail, 29, 39);

    print(tail);

    deleteNode(tail, 12);

    print(tail);
    
    Node *ptr = tail;
    do 
    {
        Node *temp = tail;
        tail = tail -> next;
        delete temp;
    }
    while (tail != ptr);

    return 0;
}