#include<iostream>
/*
 1/n **ITERATIVE APPROACH**
ListNode* reverseList(ListNode* head) 
    {
        //empty or single element list.
        if (head == NULL || head -> next == NULL)
            return head;
        
        ListNode *prev = NULL;
        while (head != NULL)
        {
            ListNode *nextNode = head -> next;
            head -> next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
				//

		2/n **Recursive approach 1/2**

    void reverse (ListNode* &head, ListNode* curr, ListNode* prev)
    {
        //base case
        if (curr == NULL)
        {
            head = prev;
            return;
        }
        //ListNode* forward = curr -> next;
        reverse(head, curr -> next, curr);//curr = forward, prev = curr
        curr -> next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse (head, curr, prev);
        return head;;
    }
};

3/3 **recursive 2nd approach
ListNode* reverseList(ListNode* head) {

        //base case: empty or single element list 
        if (head == NULL || head -> next == NULL)
        {
            return head;
        }                                              
        //this will reverse elements after first element            eg. head is 3:  3 -> 4 -> 6 -> 9 -> X
        ListNode* smallHead = reverseList (head -> next); // small head will return: X <-4 <- 6 <- 9
        //solving for one case                                    // we need to join 4 -> 3 and 3 -> X
        head -> next -> next = head;
        head -> next = NULL;
        
        return smallHead; 
    }
*/
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

Node* reverse (Node* head)
{
    //base case 
    if (head == NULL or head -> next == NULL)
    {
        return head;
    }
    //
    Node* smallHead = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return smallHead;
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
    cout <<"Before Reversing: ";
    print(head);

    head = reverse(head);

    cout <<"After Reversing: ";
    print(head);
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