/* 
# Approach 1: SC-> O(n) TC-> O(n)

//pushing LL val in string/vector checking palindrome in that data structure

    bool isPalindrome(ListNode* head) {
        string val;
        while (head != NULL)
        {
            val.push_back(head -> val);
            head = head -> next;
        }
    
        for (int i = 0; i < val.size()/2; i++)
        {
            if (val[i] != val[val.size() - i - 1])
                return 0;

        }
    
        return 1;
        
    }
# Approach 2: SC: O(1) TC: O(n)

    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while (curr)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        //logic : reverse list after mid and compare both halves
        if (head -> next == NULL) return head;
        
        ListNode* fast = head -> next;
        ListNode* slow = head;
        
        while (fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        //step 2: reversing 2nd half
        slow -> next = reverse(slow -> next);
        
        ListNode* head2 = slow -> next;//head pointer of 2nd half.
        
        //step 3: compare both halves 
        while (head && head2)
        {
            if (head -> val != head2 -> val)
                return false;
            head = head -> next;
            head2 = head2 -> next;
        }
        //OPTIONAL: repeat step 2 : to undo modification in List. 
        //slow -> next = reverse(slow -> next);
        
        return true;
    }


*/