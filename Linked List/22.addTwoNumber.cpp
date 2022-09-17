/*

My intuition:

sum of 2 types: one will be :  9,9,8 -> X      2nd   9,9,8   for 2nd we need to reverse both the lists and
                               9,0,1,2 -> X        9,0,1,2   then add like 1st. then reverse the sum list!
                                                            e.g  8,9,9 (reverse of l1)
                            =  8,0,0,3         = 1,0,0,0,0       2,1,0,9 (reverse of l2)
                                                            =    0,0,0,0,1 (it's reverse, is our ans;
 
//1st type: 
********Approach 1: By modifying LL, thus SC: O(1) TC: O(N+M)********

//my first attempt:

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //dummy node
        ListNode* ans = new ListNode(-1);
        
        ListNode* temp = ans;
        ListNode* future = ans;
        int sum = 0, carry = 0, digit = 0;
        
        while (l1 && l2)
        {
            sum = carry + (l1 -> val) + (l2 -> val);
            digit = sum % 10;
            carry = sum / 10;
            l1 -> val = digit;
            temp -> next = l1;
            temp = l1;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1)
        {
            sum = carry + (l1 -> val);
            digit = sum % 10;
            carry = sum / 10;
            l1 -> val = digit;
            temp -> next = l1;
            temp = l1;
            l1 = l1 -> next;
        }
        while (l2) 
        {
            sum = carry + (l2 -> val);
            digit = sum % 10;
            carry = sum / 10;
            l2 -> val = digit;
            temp -> next = l2;
            temp = l2;
            l2 = l2 -> next;
        }
        if (carry)
        {
            ListNode* finalAns = ans -> next;
            temp -> next = future;
            future -> val = 1;
            future -> next = NULL;
            return finalAns;
        }
        return ans -> next;
    }
#2nd attempt of approach 1(everything done in single loop)

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //dummy node
        ListNode* ans = new ListNode(-1);
        
        ListNode* temp = ans;
        ListNode* future = ans;
        int sum = 0, carry = 0, digit = 0;
        
        while (l1 || l2 || carry)
        {
            int val1 = 0;
            if (l1) val1 = l1 -> val;
            
            int val2 = 0;
            if (l2) val2 = l2 -> val;
            
            sum = carry + val1 + val2;
            digit = sum % 10;
            carry = sum / 10;
            
            if (l1) 
            {
                l1 -> val = digit;
                temp -> next = l1;
                temp = l1;
                l1 = l1 -> next;
                
                if (l2)
                    l2 = l2 -> next;
            }
            else if(l2)
            {
                l2 -> val = digit;
                temp -> next = l2;
                temp = l2;
                l2 = l2 -> next;
            }
            else  // if (carry == 1)
            {
                ListNode* finalAns = ans -> next;
                temp -> next = future;
                future -> val = 1;
                future -> next = NULL;
                return finalAns;
            }
        }
        return ans -> next;
    }
//2nd type: like conventional sum
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        Node* rev1 = reverse(first);
        Node* rev2 = reverse(second);

        Node* revSum = addTwoNumbers(rev1, rev2);
        Node* ans = reverse(revSum);
        return ans;
    }
};

*****Approach 2: (type 2) without modifying LL thus SC: O(max(N,M))*****
//gfg
class Solution
{
    public:
    //reverse
    Node* reverse (Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (curr)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void insertAtTail(Node* &head, Node* &tail, int digit)
    {
        Node* temp = new Node(digit);
        //empty list
        if (head == NULL)
        {
            head = temp;
            tail = head;
            return;
        }
        else 
        {
            tail -> next = temp;
            tail = temp; // tail = tail -> next;
        }
    }
    //Function to add two numbers represented by linked list.
    Node* addTwoNumbers(Node* l1, Node* l2) {
        //ans list's head and tail.
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        int sum = 0, carry = 0, digit = 0;
        
        while (l1 || l2 || carry)
        {
            int val1 = 0;
            if (l1) val1 = l1 -> data;
            
            int val2 = 0;
            if (l2) val2 = l2 -> data;
            
            sum = carry + val1 + val2;
            
            digit = sum % 10;
            carry = sum / 10;
            //create ans node and insert it in ans tail
            insertAtTail(ansHead, ansTail, digit);
            
            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }
        return ansHead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        first = reverse(first);
        second = reverse(second);

        Node* ans = addTwoNumbers(first, second);
        ans = reverse(ans);
        return ans;
    }

*/