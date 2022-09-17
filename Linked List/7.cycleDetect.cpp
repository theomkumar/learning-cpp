/*
**Approach-1  mark using map then check if repeated...** TC: O(n) SC: O(n)

bool hasCycle(ListNode *head) {
    if (head == NULL)
        return false;
    map<Node*, bool> visited;
    Node* temp = head;
    
    while (temp != NULL)
    {
        //cycle is +nt
        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

**APPROACH - 2 (first intuition i got for this question)**
// assigning head -> val  to int i.e outside the constraint.
if we find that value again we know it's cyclic. 

** //APPROACH -3 (fast & slow pointer) Floyd cycle detection** this uses O(1) space && TC: O(n)

bool hasCycle(ListNode *head) {
        //in case of empty or single node list
        if (head == NULL || head -> next == NULL)
            return false;
        //
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast -> next && fast -> next -> next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow)
                return true;
        }
        return false;
    }
**Approach - 4 (Reverse the list)**
before : 1 -> 2 -> 3 loop to 1 - > 2 -> 3.......so on
after reverse: Null <- 1 <- 2 <- 3 loops to 1 -> NULL, forward and current pointer points to NULL, we can return the prev pointer i.e pointing to the head.
bool hasCycle(ListNode *head) {
        ListNode *reversedHead = reverse(head);
        if (head && head -> next && reversedHead == head)
            {
                return true;
            }
        
            return false;
        }


*/