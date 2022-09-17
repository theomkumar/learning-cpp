/*
class Solution {
public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                temp -> next = list1;
                temp = list1;
                list1 = list1 -> next;
            }
            else 
            {
                temp -> next = list2;
                temp = list2;
                list2 = list2 -> next;
            }
        } 
            while (list1)
            {
                temp -> next = list1;
                temp = list1;
                list1 = list1 -> next;
            }
            while (list2) 
            {
                temp -> next = list2;
                temp = list2;
                list2 = list2 -> next;
            }
        
            return ans -> next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        if (k == 1)
            return lists[0];
        
        ListNode* ans = NULL;
        int i = 0;
        while (--k)
        {
            lists[i+1] = mergeTwoLists(lists[i], lists[i+1]);
            ans = lists[i+1];
            i++;
        }
        return ans;
    }
};

*/