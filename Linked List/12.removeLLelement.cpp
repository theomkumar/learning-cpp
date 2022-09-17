/*
### RECURSIVE:

3 line code:
    {
        if (head == NULL) return NULL;
        head -> next = removeElements(head -> next, val);
        return (head -> val == val) ? head -> next : head;
    }

    EXPLANATION: (dry run it!)

    ListNode* removeElements(ListNode* head, int val)
    {
        //we'll solve for one case recursion will do the rest!

        if (head == NULL) return NULL;

        // 5 -> 6 -> 5 -> 4 -> 5
        //recursion will give us 6 -> 4 -> X
       //5 -> next =  6 -> 4 -> X  // we just need to solve for one case i.e to remove 5 here for example

        head -> next = removeElements(head -> next, val);

        //if our head -> val == val we'll simply return next node, thus ommiting unwanted element and solving our one case.

        if (head -> val == val)
        {
            return head -> next;
        }
        else
            return head;

       //return (head -> val == val) ? head -> next : head;
    }


### Iterative

    ListNode* removeElements(ListNode* head, int val)
    {
        //if empty node
        if (head == NULL)
            return NULL;

        //this will put head in right place then we don't have to worry about maintaing head anymore
        while (head && head -> val == val)
            head = head -> next;

        FROM HERE WE CAN USE EITHER 2 pointers or 1 pointer

    //Approach 2: 1 pointer
        ListNode* curr = head;

        while (curr && curr -> next)
        {
            if (curr -> next -> val == val)
            {
                curr -> next = curr -> next -> next;
            }
            else
                curr = curr -> next;
        }

     // Approach 3:  2 pointers (prev and curr)
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL)
        {
            if (curr -> val == val)
            {
                prev -> next = curr -> next;
                curr = curr -> next;
            }
            else
            {
                prev = curr;
                curr = curr -> next;
            }
        }

        //one pointer (curr)


        return head;
    }
    //Approach 4: in below code, here we basically did everything(maintaining head and deletion) in a single loop
                //look at above , simpler than this. I did this myself intuitively.
        while (curr != NULL)
        {
            if (curr -> data == val)
            {
                if (curr -> next) //swapping next element's data and address to current and deleting next, this will keep head in right place;
                {
                    Node* temp = curr -> next;
                    curr -> data = curr -> next -> data;
                    curr -> next = curr -> next -> next;
                    delete temp;
                }
                else if (prev != NULL) //for last node element with value as val, we can point previous node to null.
                {
                    Node* temp = curr;
                    prev -> next = curr -> next;
                    curr = curr -> next;
                    delete temp;
                }
                else // for single node element with value as val, we can simply return NULL;
                {
                    return NULL;
                }

            }
            else
            {
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;

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

Node* removeElements(Node* head, int val)
{
    if (head == NULL)
        return NULL;

    Node* curr = head;
    Node* prev = NULL;

    //look at above , simpler than this. I did this myself intuitively.
    while (curr != NULL)
    {
        if (curr->data == val)
        {
            if (curr->next) //swapping next element's data and address to current and deleting next, this will keep head in right place;
            {
                Node* temp = curr->next;
                curr->data = curr->next->data;
                curr->next = curr->next->next;
                delete temp;
            }
            else if (prev != NULL) //for last node element with value as val, we can point previous node to null.
            {
                Node* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else // for single node element with value as val, we can simply return NULL;
            {
                return NULL;
            }

        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    //creating node
    Node* node1 = new Node(7);
    //head
    Node* head = node1;

    print(head);

    insertAtHead(7, head);
    insertAtHead(7, head);
    insertAtHead(7, head);
    // insertAtHead(7, head);
    // insertAtHead(11, head);
    cout << "Before: ";
    print(head);

    Node* temp = removeElements(head, 7);
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