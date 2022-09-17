#include<iostream>

using namespace std;

void update (int **p2) {
    //p2 = p2 + 1; //change?- no

    *p2 = *p2 + 1; //change ? yes why? coz it change content of p1 i.e address of i. changing content 
        // of p2 causes change in **P2 as it'll print the value at changed content at p1.

    // **p2 = **p2 + 1; //change ? yes it'll increase i by 1.
}
int main() {

    int i = 5;
    int*p = &i;
    int**p2 = &p;

    cout<<" Before \n";

    //printing value of i.
    cout<<i<<" "<<*p<<" "<<**p2<<"\n";

    //address of i
    cout<<&i<<" "<<p<<" "<<*p2<<"\n";
     
    //address of p
    cout<<&p<<" "<<p2<<"\n";

    update (p2);

    cout<<" After \n";

    
    cout<<i<<" "<<*p<<" "<<**p2<<"\n";
    cout<<&i<<" "<<p<<" "<<*p2<<"\n";
    cout<<&p<<" "<<p2<<"\n";


    return 0;
}