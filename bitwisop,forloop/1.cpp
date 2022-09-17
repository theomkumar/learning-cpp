#include<iostream>
using namespace std;
int main() {
    int a=4;
    int b=6;
    cout<<" a&b "<<(a&b)<<endl;
    cout<<" a|b "<<(a|b)<<endl;
    cout<<" ~a ~b "<<~a<<~b<<endl;
    cout<<" a^b "<<(a^b)<<endl;

    //right shift- half
    cout<<(17>>1)<<endl;
    cout<<(17>>2)<<endl;
    //left shift- doubles ,exception very large no. it becomes negative
    cout<<(19<<1)<<endl;
    cout<<(21<<2)<<endl;

    //pre-post increment
    int i=7;
    cout<<i++<<endl;
    //7 i=8
    cout<<++i<<endl;
    //9 i=9
    cout<<--i<<endl;
    //8 i=8
    cout<<i--<<endl;
    //8 i=7
    cout<<i<<endl;
    //7
}