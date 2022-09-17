#include <bits/stdc++.h> 
using namespace std;

//logic is to pop all elements, while inserting them insert at sorted position.
//hi
void insert(stack<int> &s,int target)
{
    if ( s.empty() || s.top() < target )
    {
        s.push(target);
        return;
    }
    int curr = s.top();
    s.pop();
    insert(s, target);
    s.push(curr);
}
void sortStack(stack<int> &s)
{
	if (s.empty() )
        return;
    int curr = s.top();
    s.pop();
    sortStack(s);
    insert(s, curr);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);
    return 0;
}