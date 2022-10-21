#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//using queue
void interLeaveQ1(queue<int> &q)
{
    int n = q.size();
    queue<int> temp;
    //push first half into q
    for (int i = 0; i < n/2; i++)
    {
        temp.push(q.front());
        q.pop();
    }
    //push first half front element then second half front element in q and pop front from both 
    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}
//using stack //same approach as q method but we have to reverse stack elements!
void interLeaveQ2(queue<int> &q)
{
    int n = q.size();
    stack<int> st;

    //cut first half paste in stack
    for (int i = 0; i < n/2; i++)
    {
        st.emplace(q.front());
        q.pop();
    }
    //cut stack to q --> reversed!
    while (!st.empty())
    {
        q.emplace(st.top());
        st.pop();
    }
    //cut half of q put it in back, so the back comes in front
    for (int i = 0; i < n/2; i++)
    {
        q.emplace(q.front());
        q.pop();
    }
    //cut first half of q into stack!
    for (int i = 0; i < n/2; i++)
    {
        st.emplace(q.front());
        q.pop();
    }
    //interleave elements 
    while (!st.empty())
    {
        q.emplace(st.top());
        st.pop();
        q.emplace(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11); q.push(12); q.push(13); q.push(14); q.push(15); q.push(16); q.push(17); q.push(18); q.push(19); q.push(20);

//    interLeaveQ1(q);
    interLeaveQ2(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}