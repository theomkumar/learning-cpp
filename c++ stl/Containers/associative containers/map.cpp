//key value, 
#include<iostream>
#include<map>  
using namespace std;

int main() {
    map<int,string> m;
    m[1]="the";
    m[23]="om";
    m[2]="kumar";

    m.insert({5,"bheem"});
    m.insert({44,"chota bheem"});

    cout<<"before erase \n";
    for(auto i:m) {
        cout<<i.first<<i.second<<endl;
    }

    cout<<"finding 23 "<<m.count(23)<<"\n";

    //erase
    cout<<"after erase \n";
    m.erase(23);

    for(auto i:m) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    //find
    auto it = m.find(5);

    for(auto i=it; i!=m.end(); i++) {
        cout<<(*i).first<<endl;
    }


}