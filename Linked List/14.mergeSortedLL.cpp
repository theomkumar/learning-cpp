/*
APPROACH 1: using one dummy node

        ListNode* mergeTwoLists(ListNode* left, ListNode* right) 
        {
                if (!left)
                    return right;

                if(!right)
                    return left;

//dummy node , we'll put sorted list after this node, at end will simply return ans->next, we are doing this so we don't have to worry about head;
            
                ListNode* ans = new ListNode(-1);
                ListNode* temp = ans; //pointer for traversing
            
                while (left && right)
                {
                    if (left -> val < right -> val)
                    {
                        temp -> next = left;
                        temp = left; //temp = temp -> next;
                        left = left -> next;
                    }
                    else
                    {
                        temp -> next = right;
                        temp = right; 
                        right = right -> next;
                    }
                }
                while (left)
                {
                    temp -> next = left;
                    temp = left; //temp = temp -> next;
                    left = left -> next;
                }
                while (right)
                {
                    temp -> next = right;
                    temp = right; 
                    right = right -> next;
                }
        //we can just return ans -> next now, but i want to free heap memory! 
                ListNode* finalAns = ans -> next;
                delete (ans);
         
                return finalAns;   
        }

APPROACH 2: this is how i did myself without dummy node.

        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)
            return NULL;

        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }
        ListNode* head = NULL;
        //let's put head in it's right place first, i.e smaller first element bet. list 1 & 2.

        if (list1 && list2)
        {
            if (list1 -> val < list2 -> val)
            {
                head = list1;
                list1 = list1 -> next;
            }
            else 
            {
                head = list2;
                list2 = list2 -> next;
            }
        }
        
        ListNode* temp = head; //we'll use temp to traverse
        while (list1 && list2)
        {
            if (list1 -> val < list2 -> val)
            {
                temp -> next = list1;
                temp = temp -> next;
                list1 = list1 -> next;
            }
            else
            {
                temp -> next = list2;
                temp = temp -> next;
                list2 = list2 -> next;
            }
        }
        while (list1)
        {
            temp -> next = list1;
            temp = temp -> next;
            list1 = list1 -> next;
        }
        while (list2)
        {
            temp -> next = list2;
            temp = temp -> next;
            list2 = list2 -> next;
        }
        return head;
    }
*/