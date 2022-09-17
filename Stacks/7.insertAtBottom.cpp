#include <bits/stdc++.h> 
using namespace std;

void solve (stack<int> &s, int x)
{
    //if stack becomes empty we'll insert bottom element x and return
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int curr = s.top();
    s.pop();
   //recursive call 
    solve(s, x);

    s.push(curr);
}
stack<int> pushAtBottom(stack<int>& s, int x) 
{
    solve(s, x );
    return s;
}
//same code as above but in one function.
stack<int> pushAtBottom(stack<int>& s, int x) 
{
    //base case
    if (s.empty())
    {
        s.push(x);
        return s;
    }
    int curr = s.top();
    s.pop();
    //recursive call
    pushAtBottom(s, x);
    
    s.push(curr);
    return s;
} 