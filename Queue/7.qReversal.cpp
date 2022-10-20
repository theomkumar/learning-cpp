#include<bits/stdc++.h>
using namespace std;
//Function to reverse the queue.

/* Approach 1:
Using stack:

queue<int> rev(queue<int> q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.emplace(st.top());
        st.pop();
    }
    return q;
}
*/
//using recursion:
void reverse(queue<int> &q)
{
    if (q.empty())
        return;
    int front = q.front();
    q.pop();
    reverse(q);
    q.push(front);
}
queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}

int main() 
{

    
    return 0;
}