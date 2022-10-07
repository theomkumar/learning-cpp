#include<iostream>
#include<queue>

using namespace std;


int main() 
{
    queue<int> q; 
    q.push(10);

    cout <<"Front of q: "<<q.front()<<'\n';
    q.push(11);
    cout <<"Front of q: "<<q.front()<<'\n';
    q.push(12);
    cout <<"Front of q: "<<q.front()<<'\n';

    cout <<"SIZE: " << q.size();
    q.pop();
    q.pop();
    q.pop();
    cout <<"\nSIZE: " << q.size();

    if (q.empty())
        cout<<"\nQueue is empty!! \n";
    else   
        cout<<"\nQueue is Not empty!! \n";
    return 0;
}