//it is max heap by default. i.e greatest element will come out; 

#include<iostream>
#include<queue>
using namespace std;

int main() {
    //max heap
    priority_queue<int> maxi;

    //min heap
    priority_queue<int,vector<int>, greater<int> > mini;

    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(4);

    mini.push(1);
    mini.push(2);
    mini.push(3);
    mini.push(4);

    for(int n=maxi.size(),i=0; i<n; i++) {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    

    cout<<"empty or not before pop "<<mini.empty()<<"\n";

    cout<<"Mini \n";
    for(int n=mini.size(),i=0; i<n; i++) {
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<'\n';

    cout<<"empty or not after pop "<<mini.empty()<<'\n';

    for(int i:mini) {
        cout<<i<<"\n";
    }
}