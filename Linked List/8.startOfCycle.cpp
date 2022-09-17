/*
    **#Approach 1:(it modifies LL) by modifying LL's value**
    ListNode *detectCycle(ListNode *head) 
    {
        while (head != NULL)
        {
            head -> val = 100001;
            head = head -> next;
            if (head && head -> val == 100001)
                return head;
        }
        return NULL;
    }

    **#Approach 1: by modifying LL's value**
    ```
ListNode *detectCycle(ListNode *head) 
    {
        while (head != NULL)
        {
            head -> val = 100001;
            head = head -> next;
            if (head && head -> val == 100001)
                return head;
        }
        return NULL;
    }

**#Approach 2: Optimised(without modifying LL)  TC: O(n) &  SC:O(1)**
//Find collision point of fast & slow , now increment head and collision until they collide, return that collision point, as that'll be start of cycle. how?? it can be mathematically proven easily.
  
```
 ListNode *detectCycle(ListNode *head) 
    {
        if (head == NULL || head -> next == NULL)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast -> next && fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            //when fast & slow collide 
            if (fast == slow)
            {
                while (slow != head)
                {
                    slow = slow -> next;
                    head = head -> next;
                }
                return head;
            }
        }
        return NULL;
    }
```
*/