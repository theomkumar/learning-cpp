/* linked list is Linear data structure i.e collection of nodes and each node consists of Data + next node address(pointer of node type)
why?? -> dynamic data structure(grow and shrink at runtime)
    ->insertion/deletion is easy no shift need

*/
//singly linked list -> unidirectional 
//note: generally only head is maintained.
#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node()
    {
        int value = this->data; //to print after

        //we are assign next pointer to NULL, 
        if (this -> next != NULL)
        {
            this -> next = NULL;
            // delete next; umm by looking at debugger deleting next makes , this->next from NULL to different value
        }
        cout <<"memory is cleared for value: " << value <<'\n';
    }
};

void insertAtHead(int data, Node* &head)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(int data, Node*& tail)
{
    Node* temp1 = new Node(data);
    tail -> next = temp1;
    tail = temp1;
}
//to insert at any position 

void insertAtPosition(Node*& head, Node* &tail, int position, int data)
{
    //insert at start why? coz we need previous node to insert.
    if (position == 1)
    {
        insertAtHead(data, head);
        return;
    }
    //traversing to position-1 th node.
    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }
    //insert at end why?? we can insert without this too but we need to update tail as well.
    if (temp->next == NULL) //or if (tail == temp) same thing
    {
        insertAtTail(data, tail);
        return;
    }
    //creating a node for data
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNodeByPosition(Node* &head, Node* &tail, int position)
{
    //deleting first node & maintaining head
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
    
        temp->next = NULL; //we are doing it in destructor too so it's not necessary to write here.
        delete temp;
        return;
    }

    Node* current = head;
    Node* prev = NULL;
    int cnt = 1;
    while (cnt < position)
    {
        prev = current;
        current = current->next;
        cnt++;
    }

    prev->next = current->next;
    current->next = NULL;
    delete current;

    //for maintaining tail
    if (prev->next == NULL)
        tail = prev;
}

void deleteNodeByValue(Node* &head, Node* &tail, int value)
{
   
    Node* current = head;
    Node* prev = head;
    bool isFound = 0;
    //before deletion of first node head should be maintained
    if (head->data == value)
    {
        head = head->next;
        current -> next = NULL;
        delete current;
        return;
    }
    
    while (current->data != value && current->next != NULL)
    {
        current = current->next;
        if(prev->next != current)
            prev = prev->next;
        if (current->data == value)
        {
            isFound = 1;
        }
    }
    //i added this to prevent segmentation error caused by unnecessary deletion of head.
    if (!isFound)
    {
        return;
    }
    //for maintaing tail
    if (current->next == NULL)
    {
        tail = prev;
        current -> next = NULL;
        delete current;
        return;
    }
    //deletion of required node
    prev->next = current->next;
    current -> next = NULL;
    delete current;
    
}
void print(Node*& head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

int main()
{
    //creating node
    Node* node1 = new Node(12);
    //head
    Node* head = node1;
    //tail
    Node* tail = node1;

    print(head);

    insertAtHead(15, head);
    print(head);

    insertAtTail(10, tail);
    print(head);
    
    insertAtPosition(head, tail, 1, 17);
    print(head);

    insertAtPosition(head, tail, 1, 19);
    print(head);

    insertAtPosition(head, tail, 1, 24);
    print(head);

    insertAtPosition(head, tail, 5, 4);
    print(head);

    deleteNodeByPosition(head, tail, 1); //obviously position is refreshed everytime a node is deleted
    deleteNodeByPosition(head, tail, 4);
    
    print(head);

    deleteNodeByValue(head, tail, 15);
    print(head);

    deleteNodeByValue(head, tail, 12);//15 has already been deleted
    print(head);

    cout <<"Head: " << head->data <<'\n';
    cout <<"Tail: "<< tail->data << '\n';

    // freeing up heap memory by deleting all the allocated nodes 
    while (head != NULL)
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    //(optional-> assigning pointers to NULL);
    tail = NULL;
    node1 = NULL;

    return 0;
}