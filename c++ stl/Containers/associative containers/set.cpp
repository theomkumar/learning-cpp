//unique elements are stored in sets,

//incomplete Iterator
#include<iostream>
#include<set>
using namespace std;
int main() {
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(2);

    for(int i:s) {
        cout<<i<<"\n";
    }
    cout<<'\n';

    s.erase(s.begin());
    for(int i:s) {
        cout<<i<<"\n";
    }
    //count - checks if the corresponding elements are present or not.
    cout<<'\n';

    cout<<"is 5 present? "<<s.count(5)<<'\n';

    //s.find(5) using iterator
}