/*
Node *removeLoop(Node *head)
{
    if (head == NULL || head -> next == NULL)
        return head;

    Node *ans = head;

    //detect isloop
    Node *fast = head;
    Node *slow = head;
    Node *prev = NULL; 
    
    while (fast -> next != NULL && fast -> next -> next != NULL)
    {
        fast = fast -> next -> next;
        prev = slow;
        slow = slow -> next;
        if (slow == fast)
        {
            while (head != slow)
            {
                head = head -> next;
                prev = slow;
                slow = slow -> next;
            }
            prev -> next = NULL; //this will break the cycle 
            return ans;
        }
    }
    return ans;
}
    
*/