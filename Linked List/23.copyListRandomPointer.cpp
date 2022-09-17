/*
#Approach 1 -> TC: O(n^2) SC: O(n)

void insertAtTail(Node* &ansHead, Node* &ansTail, int d)
{
    //copy 
    Node* temp = new Node(d);
    
    if (ansHead == NULL)
    {
        ansHead = temp;
        ansTail = temp;
        return;
    }
    else
    {
        ansTail -> next = temp;
        ansTail = ansTail -> next;     
    }
}
Node* findRandomNode(Node* head, int target)
{
    while (head -> val != target)
    {
        head = head -> next;
    }
    return head;
}
Node* copyRandomList(Node* head) {
    Node* ogHead = head;

    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    while (head != NULL)
    {
        insertAtTail(ansHead, ansTail, head -> val);
        head = head -> next;
    }
    head = ogHead;
    Node* temp = ansHead;
    while (head != NULL)
    {
        if (head -> random != NULL)
        {
            temp -> random = findRandomNode(ansHead, head -> random -> val);
        }
        temp = temp -> next;
        head = head -> next;
    }
    return ansHead;
}

#APPROACH 2: TC O(n) SC O(n) 
using map to store <original head , clone head> now, if we want random of clone we can just go to map[og -> random] which will point to the random pointer.

void insertAtTail(Node* &cloneHead, Node* &cloneTail, int d)
{
    //copy 
    Node* temp = new Node(d);
    
    if (cloneHead == NULL)
    {
        cloneHead = temp;
        cloneTail = temp;
        return;
    }
    else
    {
        cloneTail -> next = temp;
        cloneTail = cloneTail -> next;     
    }
}

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> oldToNewNode;
    Node* ogHead = head;

    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    
    //clone and update old to new node in unordered_map
    while (head != NULL)
    {
        insertAtTail(cloneHead, cloneTail, head -> val);
        oldToNewNode[head] = cloneTail;
        head = head -> next;
    }
    head = ogHead;
    Node* temp = cloneHead;
    while (head != NULL)
    {
        if (head -> random == NULL)
        {
            temp = temp -> next;
            head = head -> next;
        }
        else
        {
            temp -> random = oldToNewNode[head -> random];
            temp = temp -> next;
            head = head -> next;
        }
    }
    return cloneHead;
}

#APPROACH 3: TC O(n) SC O(1)

void insertAtTail(Node* &head, Node* &tail, int d)
{
    Node* newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail -> next = newNode;
        tail = tail -> next;
    }
}

Node* copyRandomList(Node* head) {
    //original & clone head
    Node* og = head; 
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    
    //step 1 make a clone
    while (og)
    {
        insertAtTail(cloneHead, cloneTail, og -> val);
        og = og -> next;
    }
    og = head; 
    Node* clone = cloneHead;//use this pointer to traverse clone
    
    //step 2 interweave og and clone, so that og is pointing to it's corresponding clone. 
    //and clone is pointing to curr og -> next, so we could traverse from og head and assign random pointer to clone later on.
    
    while (og)
    {
        Node* next = og -> next;
        og -> next = clone;
        og = next;
        
        next = clone -> next;
        if (clone) //for last node, clone -> next could be null so we have to check that
            clone -> next = og;
        clone = next;
    }
    og = head;
    clone = cloneHead;
    //step 3 assign random pointer to clone node
    while (og)
    {
        og -> next -> random = og -> random ? og -> random -> next : NULL;//NULL or og -> random , coz it's null anyways
        og  = og -> next -> next;
    }
    og = head;
    clone = cloneHead;
    
    //step 4: reverting step 2 (separating both og and clone)
    while (og)
    {
        og -> next = clone -> next;
        og  = og -> next;
        
        if(og)
            clone -> next = og -> next;
        clone = clone -> next;
    }
    return cloneHead;
}

*/