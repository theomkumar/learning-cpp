#include<iostream>
#include<deque>
//double ended queue - insertion deletion from both ends
using namespace std;
int main() {
    deque<int> d;
    d.push_back(2);
    d.push_front(1);
    d.push_back(3);
    d.push_back(4);
    
    for(int i : d) {
        cout<<i<<" ";
    }cout<<"\n";
    
    //pop back and front
    d.pop_front();

    cout<<"after pop front ";
    for(int i : d) {
        cout<<i<<" ";
    }cout<<"\n";

    cout<<"element at index 1: "<<d.at(1)<<"\n";

    //front back
    cout<<"first element: "<<d.front()<<"  last element: "<<d.back()<<"\n";
    // empty function - return 0 if not empty
    cout<<"return 1 if empty: "<<d.empty()<<"\n";

    //ERASE

    cout<<"before ERASE ";
    for(int i : d) {
        cout<<i<<" ";
    }cout<<"\n";

    d.erase(d.begin(),d.begin()+1);

    cout<<"after erase ";
    for(int i : d) {
        cout<<i<<" ";
    }cout<<"\n";
}