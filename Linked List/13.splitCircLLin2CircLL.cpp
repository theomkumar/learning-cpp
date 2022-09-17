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


void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if (head == NULL || head -> next == NULL) return;
    
    Node* fast = head;
    Node* slow = head;
    *head1_ref = head;
    while (fast -> next != head && fast -> next -> next!= head)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    *head2_ref = slow -> next;
    //first split circle complete
    slow -> next = head;
    //second circle
    Node* temp = *head2_ref;
    while (temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> next = *head2_ref;
}
int main() 
{
    Node* tail = NULL;
    insertNode(tail, 1, 12);
    insertNode(tail, 12, 14);
    insertNode(tail, 14, 17);
    insertNode(tail, 12, 13);


    print(tail);

    Node *head1_ref = NULL;
    Node *head2_ref = NULL;
    splitList(tail, &head1_ref, &head2_ref);
    
    print(head1_ref);
    print (head2_ref);

    //deletion
    Node* temp = head1_ref;
    do
    {
        Node* deleteNode = temp;
        temp = temp -> next;
        delete deleteNode;
        /* code */
    } while (temp != head1_ref);
    
    temp = head2_ref;
    do
    {
        Node* deleteNode = temp;
        temp = temp -> next;
        delete deleteNode;
        /* code */
    } while (temp != head2_ref);
}