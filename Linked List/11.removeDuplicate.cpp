/*
Case : 1 -> sorted LL

Logic: check next node val and if it's equal to current then move curr -> next pointer to curr -> next -> next, and delete curr -> next node.

    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;

        ListNode *curr = head;
        while (curr -> next != NULL)
        {
            if (curr -> val == curr -> next -> val)
            {
                ListNode* temp = curr -> next;
                curr -> next = curr -> next -> next;
                delete temp;
            }
            else
                curr = curr -> next;
        }
        return head;
    }

Case 2: Unsorted LL

Approach 1: simple 2 loop TC: O(n^2) SC: O(1)

ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;

        ListNode *curr = head;
        while (curr != NULL && curr -> next != NULL)
        {
            ListNode* prevTrav = curr;
            ListNode* trav = curr -> next;
            while (trav != NULL)
            {
                if (trav -> val == curr -> val)
                {
                    ListNode* to_delete = trav;
                    prevTrav -> next = trav -> next;

                    trav = trav -> next;

                    delete(to_delete);
                }
                else
                {
                    prevTrav = trav;
                    trav = trav -> next;
                }
            }
                curr = curr -> next;
        }
        return head;
    }

Approach 2: sort LL(nlogn) & use algo of removing duplicate from sorted LL i.eO(n). TC: O(nlogn) SC: O(1);

Approach 3: use map TC: O(n) SC: O
    Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    map<int, bool> visited;
    Node* curr = head;
    Node* prev = head;

    while (curr != NULL)
    {
        if (visited[curr -> data] == 1)
        {
            Node* temp = curr;
            prev -> next = curr->next;
            curr = curr->next;
            delete(temp);
        }
        else
        {
            visited[curr -> data] = 1;
            prev = curr;
            curr = curr -> next;
        }
    }
    return head;
}
*/

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

Node* removeDuplicates(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    map<int, bool> visited;
    Node* curr = head;
    Node* prev = head;

    while (curr != NULL)
    {
        if (visited[curr->data] == 1)
        {
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(temp);
        }
        else
        {
            visited[curr->data] = 1;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;

}


int main()
{
    //creating node
    Node* node1 = new Node(16);
    //head
    Node* head = node1;

    print(head);

    insertAtHead(14, head);
    insertAtHead(14, head);
    insertAtHead(14, head);
    insertAtHead(15, head);
    // insertAtHead(11, head);
    cout << "Before: ";
    print(head);

    Node* temp = removeDuplicates(head);
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