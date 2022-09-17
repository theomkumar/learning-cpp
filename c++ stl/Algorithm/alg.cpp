#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);

    //binary search 
    cout<<"finding 3: "<<binary_search(v.begin(),v.end(),3)<<"\n";
    int a=3,b=6;

    //upper bound lower bound
    //std::lower_bound - returns iterator to first element in the given range which is EQUAL_TO or Greater than val.

    // std::upper_bound - returns iterator to     first element in the given range which is Greater than val.

    cout<<"lower bound of 3: "<<lower_bound(v.begin(),v.end(),3)-v.begin()<<"\n";
    
    cout<<"upper bound of 3: "<<upper_bound(v.begin(),v.end(),3)-v.begin()<<"\n";
    //min max
    cout<<"min "<<min(a,b)<<" max "<<max(a,b)<<"\n";
    //swap
    swap(a,b);
    cout<<"a "<<a<<" b "<<b<<"\n";
    //reverse
    string alphabet = "abcde";
    reverse(alphabet.begin(),alphabet.end());
    cout<<"string "<<alphabet<<endl;
    //rotate
    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"after rotate\n";
    for(int i:v) {
        cout<<i<<" ";
    }cout<<'\n';
    //sort
    sort(v.begin(),v.end());

    for(int i:v) {
        cout<<i<<" ";
    }
    

}