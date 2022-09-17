//this is how solved myself iteratively better approaches are there.
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
bool isPossible(Node* head, int k)
    {
        Node* temp = head;
        while (--k)
        {
            temp = temp -> next;
            if (temp == NULL)
                return 0;
        }
        return true;
    }
Node* reverse(Node* &head,Node* &temp, int k)
{

    Node* prev = NULL;
    temp = head;
    Node* curr = head;
    Node* forward = NULL;
    int cnt = 0;
    while (cnt < k && curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    } 
    head -> next = forward;
    head = prev;
    return curr;//this is start of next K-group
}
Node* reverseKGroup(Node* head, int k) {
        Node* curr = head;
        Node* temp = head;
        Node* temp2 = head;
        int cnt = 0;
        while (curr != NULL)
        {
            Node* temp1 = temp2;
            if (isPossible(curr, k) == 0)
                return temp;
            curr = reverse(head, temp2, k);
            if (cnt == 0)
            {
                temp = head;
                cnt++;
            }
            else 
                temp1 -> next = head; 
            head = curr;
        }
        return temp;
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
    insertAtHead(13, head);
    insertAtHead(12, head);
    // insertAtHead(11, head);
    cout <<"Before Reversing: ";
    print(head);

    // Node* nxt = reverse(head, 1);
    Node* temp = reverseKGroup(head, 3);
    cout <<"After Reversing: ";
    print(temp);


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