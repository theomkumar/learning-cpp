//Recursive approach - better(easier to understand)
class Solution {
private:
    bool isPossible(ListNode* head, int k)
    {
        while (--k)//running loop k-1 times
        {
            head = head -> next;
            if (head == NULL)
                return false;
        }
        return true;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)////we don't necessarily need this coz isPossible will check for this too, but it's better coz we don't have to call function unnecessarily.
            return NULL; //coz head == NULL so doesn't matter if we return head or null
        
        //step 1 reverse first K nodes if it's possible
       //checking if we have k nodes to reverse; 
        if (isPossible(head, k) == 0)
            return head;
        
        int cnt = k;    
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        
            while (cnt--)
            {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }
        
        //step 2: recursive call: 
        //it'll reverse rest of nodes in k group and will return the head(start of rest of k            group) that we need to join with head -> next (i.e end of our first k-group)
        
        ////Note after reversing , prev becomes the start of current k group, and head becomes end,
        //our goal is to join end of curr to start of next k-group(i.e head -> next to prev)
        //if the list becomes empty after reversing curr k group simply reverse prev.

        head -> next = reverseKGroup(next, k); 
        
        //step 3: return
        return prev; //this previous is actually start of the reversed nodes
    }
};