#include<iostream>
#include<map>

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
        if (this->next != NULL)
        {
            this->next = NULL;
            // delete next; umm by looking at debugger deleting next makes , this->next from NULL to different value
        }
        cout << "memory is cleared for value: " << value << '\n';
    }
};

void insertAtHead(int data, Node*& head)
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

//BEST CASE (already sorted list) TC: O(n) SC: O(1), worst case: O(n^2)
Node* BubbleSort(Node *head)
{
    if (head == NULL || head -> next == NULL)
        return head;
    
    Node* curr = head;
    int cnt = 0;
    while (curr != NULL)
    {
        cnt++;
        curr = curr -> next;
    }
    //
    curr = head;  
    while (curr != NULL)
    {
        curr = head;
        bool isSwapped = 0;
        for (int i = 0; i < cnt && curr -> next; i++)
        {
            if (curr -> data > curr -> next -> data)
            {
                isSwapped = 1;
                int temp = curr -> data;
                curr -> data = curr -> next -> data;
                curr -> next -> data = temp;
            }
            curr = curr -> next;
        }
        if (isSwapped == 0) return head;
    }
    return head;
}
int main()
{
    //creating node
    Node* node1 = new Node(2);
    //head
    Node* head = node1;

    print(head);

    insertAtHead(1, head);
    insertAtHead(0, head);
    insertAtHead(2, head);
    insertAtHead(0, head);
    // insertAtHead(11, head);
    cout << "Before: ";
    print(head);

    Node* temp = BubbleSort(head);
    cout << "After: ";
    print(temp);

    // freeing up heap memory by deleting all the allocated nodes 
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    //(optional-> assigning pointers to NULL);
    node1 = NULL;

    return 0;
}