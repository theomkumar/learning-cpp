#include<iostream>
#include<queue>

using namespace std;

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front()<<' ';
        q.pop();
    }
    cout << '\n';
}
void reverseQ(queue<int> &q)
{
    if (q.empty())
        return;
    int top = q.front();
    q.pop();
    reverseQ(q);
    q.push(top);
}

int main()
{
    int a23456789jjfjkafjkdasljfdsaklfjksad = 12;
    cout << a23456789jjfjkafjkdasljfdsaklfjksad<<endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    print(q);
    reverseQ(q);
    cout<<"after reverse: ";
    print(q);
}