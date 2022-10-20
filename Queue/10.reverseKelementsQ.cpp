#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> st;
    int n = q.size(), rem = n - k;

    //push k elements in stack
    while (k--)
    {
        st.push(q.front());
        q.pop();
    }
    //push k elements from stack to q
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    //fetch first (n-k) == remaining element and push back
    while (rem--)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}