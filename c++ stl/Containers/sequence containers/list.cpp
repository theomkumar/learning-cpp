#include<iostream>
#include<list>

using namespace std;

int main() {
    list<int> l;
    //push front back, pop front back erase begin end
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    l.push_front(0);


    for(int i:l) {
        cout<<i<<" ";
    }cout<<"\n";
    //erase 

    l.erase(l.begin());

    cout<<"after erase ";
    for(int i:l) {
        cout<<i<<" ";
    }cout<<"\n";

    list<int> a(5,100);
    for(int i:a) {
        cout<<i<<" ";
    }cout<<"\n";

    list<int> b(a);
    for(int i:b){
        cout<<i<<" ";
    }cout<<"\n";
}
