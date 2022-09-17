/*
TC: O(nlogn) SC: O(logn) 
  ListNode* merge(ListNode* l1, ListNode* l2)
  {
      //if one list is empty return the other one
      if (!l1) return l2;
      if (!l2) return l1;
      
      //dummy node, we'll add sorted elements in it
      ListNode* ans = new ListNode(-1);
      ListNode* temp = ans;//use this to traverse
      
      while (l1 && l2)
      {
          if (l1 -> val < l2 -> val)
          {
              temp -> next = l1;
              temp = l1;
              l1 = l1 -> next;
          }
          else
          {
              temp -> next = l2;
              temp = l2;
              l2 = l2 -> next;
          }
      }
      while (l1)
      {
          temp -> next = l1;
          temp = l1;
          l1 = l1 -> next;
      }
      while (l2)
      {
          temp -> next = l2;
          temp = l2;
          l2 = l2 -> next;
      }
      return ans -> next;
      //to free dummy node we can simply store ans -> next and then delete the node.
  }
  ListNode* findMid(ListNode* head)
  {
      ListNode* slow = head;
      ListNode* fast = head -> next;
      while (fast && fast -> next)
      {
          slow = slow -> next;
          fast = fast -> next -> next;
      }
      return slow;
  }
  ListNode* sortList(ListNode* head) {
    //if list is empty or single element 
      if (head == NULL || head -> next == NULL) 
          return head;
      
      //step 1 : find mid
      ListNode* mid = findMid(head);
      
      ListNode* l1 = head; //head of l1 list (0 to mid)
      ListNode* l2 = mid -> next; // head of l2 list (mid+1)
      
      //ending l1 list by adding null after mid 
      mid -> next = NULL;
      
      //sort l1 recursively
      l1 = sortList(l1);
      //sort l2 recursively
      l2 = sortList(l2);
      
      //merge sorted l1 and l2 and return it!
      return merge(l1, l2);
  }
*/