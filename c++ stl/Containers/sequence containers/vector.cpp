#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v;
    //initialise vector of size 5 with all elements as 1, 
    
    //vector<int> v1(5,1);

    //capacity - how much memory assigned, eg empty array 0
    cout<<"capacity: "<<v.capacity()<<"\n";
    
    v.push_back(1);
    cout<<"capacity: "<<v.capacity()<<" ";
    
    v.push_back(2);
    cout<<"capacity: "<<v.capacity()<<" ";

    v.push_back(3);
    cout<<"capacity: "<<v.capacity()<<" ";
    
    v.push_back(4);
    cout<<"capacity: "<<v.capacity()<<"\n";
    //size 
    cout<<"size: "<<v.size()<<"\n";

    //front & back
    cout<<"first element: "<<v.front()<<" ";
    cout<<"last element: "<<v.back()<<"\n";
    //using at 
    cout<<"element at index 3: "<<v.at(3)<<"\n";
    //using pop_back

    cout<<"before pop: ";
    for(int i:v) {
        cout<<i<<" ";
    }cout<<"\n";

    v.pop_back();

    cout<<"after pop: ";
    for(int i:v) {
        cout<<i<<" ";
    }cout<<" \n";

  //clear- it doesn't clear vector's capacity i.e its memory allocation

    cout<<"before clear size: "<<v.size()<<"\n";
    v.clear();
    cout<<"after clear size: "<<v.size()<<"\n";

    vector<int> v1(5,9);
    vector<int> v2(v1);

    v1.push_back(5);
    //print vector
    for(int i:v1) {
        cout<<i<<" ";
    }cout<<"\n";

    for(int i:v2) {
        cout<<i<<" ";
    }cout<<"\n";

}