#include<iostream>
//https://leetcode.com/problems/middle-of-the-linked-list/

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
        std::cout <<"memory is cleared for value: " << value <<'\n';
    }
};

void insertAtHead(int data, Node* &head)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
//by counting 
Node* middleNode1(Node* head) 
{
    Node* middle = head;
    //counting nodes  
    int cnt = 1;
    while (head -> next != NULL)
    {
        head = head -> next;
        cnt++;
    }
    //cnt is now middle node position
    cnt = cnt/2 + 1;
    
    while (--cnt) //running loop less one less than position that's why --cnt. 
    {
        middle = middle -> next;
    }
    return middle;
}
//**Optimized ** my method by observing, look at middleNode3 now
//logic : using 2 pointers , one will move twice the other, so after traversing we'll get middle.
Node* middleNode2(Node* head) {
    
    //empty list or single
    if (head -> next == NULL or head == NULL)
        return head;
    
    Node* middle = head;
    while (head -> next != NULL)
    {
        if (head -> next -> next == NULL)
        {
            middle = middle -> next;
            return middle;
        }
        head = head -> next -> next;
        middle = middle -> next;
    }
    return middle;
}
//same logic as middleNode2 but easier to understand maybe

Node* middleNode3(Node* head)
{
    //empty list or single
    if (head == NULL || head -> next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
            fast = fast -> next;
        
        slow = slow -> next;
    }
    return slow;
}

void print(Node*& head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

int main()
{
    //creating node
    Node* node1 = new Node(16);
    //head
    Node* head = node1;

    print(head);

    insertAtHead(15, head);
    insertAtHead(14, head);
    // insertAtHead(13, head);
    // insertAtHead(12, head);
    // insertAtHead(11, head);

    print(head);
    Node *middle = middleNode3(head);
    std::cout <<"print from middle node : ";
    print(middle);


    // freeing up heap memory by deleting all the allocated nodes 
    while (head != NULL)
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    //(optional-> assigning pointers to NULL);
    node1 = NULL;

    return 0;
}
