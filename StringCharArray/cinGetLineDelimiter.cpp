#include<iostream>
#include<string.h>
using namespace std;


int main() {

    string name;
    cout<<"enter name(press $ at end): ";
    
    //$ is delimiter, if we leave it like (cin,s) only then "\n" will be the delimiter.
    getline(n,name,'$'); 
    
    
    char address[30];
    cout<<"enter address(press x to end): "; 
    cin.getline(address,30,'x');

    cout<<"\nhi "<<name;
    cout<<", your address is: "<<address<<"\n";

    return 0;

}