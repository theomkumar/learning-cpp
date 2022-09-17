#include<iostream>
#include<array>
using namespace std;

int main() {
    int arr[5]={1,2,3,4,5};
    array<int,5> a = {1,2,3,4,5};
    
    
    for(int i = 0; i<a.size(); i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    //using at to find elements at the corresponding index

    cout<<"element at Index 2: "<<a.at(2)<<endl;

    //empty or not - this returns boolean value 

    cout<<"if empty return 1 : "<<a.empty()<<"\n";

    //front & back 
    cout<<"first element: "<<a.front()<<"\n"<<"last element: "<<a.back()<<"\n";

    
}