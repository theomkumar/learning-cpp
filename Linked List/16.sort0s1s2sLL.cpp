/*


##APPROACH 1a: TC: O(n) SC: O(3) this can be avoided easily look at approach 1b, i did this one first.
LOGIC: by counting elements and replacing data.
Node* sortList(Node *head)
{
    vector<int> cnt(3,0);
    Node* temp = head;
    while (temp)
    {
        int idx = temp -> data;
        cnt[idx]++;
        temp = temp -> next;
    }
    temp = head;
    int i = 0;
    while (temp)
    {
        while (temp && cnt[i])
        {
            temp -> data = i;
            cnt[i]--;
            temp = temp -> next;
        }
        i++;
    }
    return head;
}
## Approach 1.b : TC: O(n) SC: O(1) (same as approach 1a just using variable instead of vector)
Node* sortList(Node *head)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    Node* temp = head;
    
    while (temp)
    {
        if (temp -> data == 0)
            cnt0++;
        else if (temp -> data == 1)
            cnt1++;
        else if (temp -> data == 2)
            cnt2++;

        temp = temp -> next;
    }
    temp = head;
    while (temp)
    {
        if (cnt0)
        {
            temp -> data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp -> data = 1;
            cnt1--;
        }
        else if (cnt2) 
        {
            temp -> data = 2;
            cnt2--;
        }  
        temp = temp -> next;
    }
    return head;
}

##Approach 2: When data replacement is not allowed, TC: O(n) SC: O(1)
*/
#include<iostream>
#include<vector>

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

Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
   //created separate list for 0, 1, 2 
    while (curr)
    {
        if (curr -> data == 0)
        {
            zeroTail -> next = curr;
            zeroTail = curr;//temp0 = temp0 -> next;
        }
        else if (curr -> data == 1)
        {
            oneTail -> next = curr;
            oneTail = curr;
        }
        else if (curr -> data == 2)

        {
            twoTail -> next = curr;
            twoTail = curr;
        }
        curr = curr -> next;
    }
    // // merge 3 sublist (assuming one's list is not empty)
    // zeroTail -> next = oneHead -> next;
    // oneTail -> next = twoHead -> next;
    // twoTail -> next = NULL;

    // return zeroHead -> next;

    //merge 3 sublist (Note: if 1st list is empty, then we can't connect zero list with two list using previous code)

    //merge 3 sublist
    if (oneHead -> next != NULL) //one's list is not empty, so we'll connect 0 list with one
    {
        zeroTail -> next = oneHead -> next;
        oneTail -> next = twoHead -> next;
    }

    else 
        zeroTail -> next = twoHead -> next; //one's list is empty, so we'll connect 0 list with 2s directly;

    
    twoTail -> next = NULL; //this will end the LL.

    return zeroHead -> next;


    // //to prevent memory leak, due to allocation of dummy node so we need to delete it.
    // Node* ans = zeroHead -> next;
    // delete(zeroHead);
    // delete(oneHead);
    // delete(twoHead);
    // return ans;
}

Node* sortList1(Node *head)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    Node* temp = head;
    
    while (temp)
    {
        if (temp -> data == 0)
            cnt0++;
        else if (temp -> data == 1)
            cnt1++;
        else if (temp -> data == 2)
            cnt2++;

        temp = temp -> next;
    }
    temp = head;
    while (temp)
    {
        if (cnt0)
        {
            temp -> data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp -> data = 1;
            cnt1--;
        }
        else if (cnt2) 
        {
            temp -> data = 2;
            cnt2--;
        }  
        temp = temp -> next;
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

    insertAtHead(0, head);
    insertAtHead(0, head);
    insertAtHead(1 , head);
    insertAtHead(0, head);
    // insertAtHead(11, head);
    cout << "Before: ";
    print(head);

    Node* temp = sortList(head);
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
