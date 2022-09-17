/*
##APPROACH 1: using map TC: O(n) SC: O(m+n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> mark;
        while (headA)
        {
            mark[headA] = 1;
            headA = headA -> next;
        }
        while (headB)
        {
            if (mark[headB])
                return headB;
            headB = headB -> next;
        }
        return NULL;
    }
};
##APPROACH 2: TC O(n) SC O(1)
Logic is pretty neat!
dry run it, basically both the pointers are destined to meet,either at intersection point or null

EASY TO UNDERSTAND INTUITION:
Imagine two tracks A1 and A2, one is 5 units and the other is  2 units, if athletes P1 and P2 start running simultaneously and are told to run as much as their buddy's track after they finish their own track.
Now, at the end : P1 covered -> A1 distance + A2 distance = 5 + 2 = 7
while P2 covered -> A2 distance + A1 distance = 2 + 5 = 7
They are destined to meet! if there is no intersection they'll still meet but at NULL!
Do dry run!

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        
        while (p1 != p2)
        {
            p1 = p1 ? p1 -> next : headB;
            p2 = p2 ? p2 -> next : headA;
        }
        return p1;
    }


*/