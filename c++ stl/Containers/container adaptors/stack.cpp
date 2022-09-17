// stack- last in - first out concept
//push-pop-top-size-empty
#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<string> s;
    s.push("the");
    s.push("om");
    s.push("kumar");

    cout<<"top element: "<<s.top()<<'\n';

    s.pop();
    cout<<"after pop, top element: "<<s.top()<<'\n';

    cout<<"size of stack: "<<s.size()<<'\n';
    cout<<"if empty output 1: "<<s.empty()<<'\n';

}