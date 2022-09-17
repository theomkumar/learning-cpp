#include<iostream>
using namespace std;
int main() {
    int i=1;
    switch(i) {
        case 0:  cout<<"zero \n";
                break;
        case 1 : cout<<"case 1 ";
        case 2 : cout<<"case2 ";
                break;

                
        default : cout<<"default case"; 
    }
}