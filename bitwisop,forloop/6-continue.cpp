#include<iostream>
using namespace std;
int main () {
    for(int i=0; i<4; i++) {
        cout<<"Hi! \n";
        continue;
        cout<<"Bye!";
        //bye won't print, continue will skip & redirect it to updation i.e i++
    }
}