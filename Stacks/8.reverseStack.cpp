#include<bits/stdc++.h>
using namespace std;
//TC O(N^2) how?? SC O()
//logic we'll put top element on bottom , we'll solve one case recursion will solve rest!
void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int curr = s.top();
    s.pop();
    insertAtBottom(s, x);

    s.push(curr);
}
void reverseStack(stack<int> &s) {
    if (s.empty())    
        return;
    //
    int curr = s.top();
    s.pop();
    //recursion will reverse all the nodes after curr;
    reverseStack(s);

    //we'll solve one case i.e for curr
    insertAtBottom(s, curr);
}
