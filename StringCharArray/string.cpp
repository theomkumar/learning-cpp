#include<iostream>
using namespace std;

char toUpperCase(char c) {
    if (c>='a' && c<='z')
        c = c - 'a' + 'A';
    return c;
}
char toLowerCase(char c) {
    if (c>='A' && c<='Z') {
        c = c-'A'+ 'a';
    }
    return c;
}
int main() {
    string str = "om";
    str.push_back('i');
    str.push_back(' ');
    str.pop_back();
    cout<<str;

    cout<<"\nans "<<toLowerCase('Z');
}
