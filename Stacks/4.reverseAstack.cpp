#include<iostream>
#include<stack>
using namespace std;


int main() 
{
    string str = "babbar";
    stack<char> s;

    cout << "Before: " << str;

    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }

    for (int i = 0; i < str.size(); i++)
    {
        str[i] = s.top();
        s.pop();
    }
    cout << "\nAfter: " << str <<'\n'; 
    
    return 0;
}