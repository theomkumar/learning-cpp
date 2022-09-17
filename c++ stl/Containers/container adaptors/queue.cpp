//first in first out
// front-size-pop
#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<string> q;
    q.push("the");
    q.push("om");
    q.push("kumar");

    cout<<"size before pop: "<<q.size()<<'\n';
    cout<<"first element: "<<q.front()<<'\n';

    q.pop();

    cout<<"first element after pop: "<<q.front()<<'\n';
    cout<<"size after pop: "<<q.size()<<'\n';
}