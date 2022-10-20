#include<iostream>
#include<queue>
using namespace std;


int main() 
{
    deque<int>d;
    d.push_front(12);
    d.emplace_back(14);//same function as push_back but it does inplace by passing value directly to constructor, read about it

    cout << "front: "<< d.front()<<'\n';
    cout << "back: "<< d.back()<<'\n';

    d.pop_front();
    cout << "front: "<< d.front()<<'\n';
    cout << "back: "<< d.back()<<'\n';
    d.pop_back();

    if (d.empty())
        cout <<"Deque is empty! \n";
    else
        cout << "Not Empty! \n";

    
    return 0;
}