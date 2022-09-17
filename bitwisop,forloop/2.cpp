#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the value of n : ";
    cin>>n;
    cout<<"printing count from 1 to n \n";

    for (int i=1; i<=n; i++) {
        cout<<i<<endl;
    }

    //using break to stop loop
    /*
    int i=1;
    for ( ; ; ){
        if(i<=n) {
        cout<<i<<endl; 
        }
        else {
            break;
            }
             
            i++; 
    }
    */
   
}