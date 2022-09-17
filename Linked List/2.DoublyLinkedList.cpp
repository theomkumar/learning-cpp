//handling empty linked list.
#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node ()
    {
        int value = this -> data;
        cout <<"memory cleared of value: "<< value;
        cout <<'\n';

        if (this -> prev != NULL)
        {
            this -> prev = NULL;
            delete prev;

        }
        if (this -> next != NULL)
        {
            this -> next = NULL;
            delete next;

        }
    }
};

void print(Node* &head)
{
    Node* temp = head; 
    while (temp != NULL)
    {
        cout << temp->data <<' ';
        temp = temp->next;
    }
    cout <<'\n';
}
//length of linked list
int getLength (Node* &head)
{
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void insertAtHead(Node* &head, Node* &tail, int data)
{
    //if list is empty it means the only node will be both head and tail.
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = head;
    }
     
    else 
    {
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int data)
{
    //list is empty 
    if (tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = tail;
    }
    else
    {
        Node* temp = new Node(data);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, tail,data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    Node* temp = head;

    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;        
        cnt++;
    }
    //maintaining tail
    /*
    if (temp -> next == NULL)
        tail = nodeToInsert;
    */
    if (temp -> next == NULL)
    {
        insertAtTail(tail,head, data);
        return;
    }
    //inserting somewhere in middle 
    nodeToInsert -> prev = temp;
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    temp -> next -> prev = nodeToInsert;
}

void deleteByPosition(Node* &head, Node* &tail, int position)
{
    //
    if (position == 1)
    {
        Node *temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp; 
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        //last position
        if (curr -> next == NULL)
        {
            prev -> next = NULL;
            tail = prev;
            delete curr;
            return;
        }
        //anywhere in middle
        else 
        {
            prev -> next = curr -> next;
            curr -> next -> prev = prev;
            delete curr;
        }
    }
    
}
int main() 
{
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtTail(tail, head, 2);

    insertAtHead(head,tail, 12);
    print(head);

    insertAtHead(head,tail, 10);
    print(head);

    insertAtTail(tail, head, 40);
    print(head);

    insertAtPosition(head, tail, 24, 4);
    print (head);

    insertAtPosition(head, tail, 74, 2);
    print (head);

    deleteByPosition(head, tail, 1);
    print (head);

    deleteByPosition(head, tail, 3);
    print (head);

    deleteByPosition(head, tail, 4);
    print (head);

    cout << "Length: " << getLength(head) <<'\n';
    cout << "Head: " << head->data <<'\n';
    cout << "Tail: " << tail->data <<'\n';

    //deleting nodes to free up memory allocated in heap
    while (head != NULL)
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    tail -> prev = NULL;
    tail = NULL;
    return 0;
}