#include<iostream>
#include<algorithm>
using namespace std;

void reverse(char name[],int n) {
    int s = 0;
    int e = n-1;
    for (int i = 0; s<e; i++) {
        swap(name[s++],name[e--]);
    }
}

int main() {
    char name[23];
    cout<<"input : ";
    cin>>name;
    int count = 0;

    for(int i = 0; name[i]!='\0'; i++) {
        count++;
    }
    cout<<"length: "<<count<<'\n';

    reverse(name,count);
    cout<<"reverse of input: "<<name<<'\n';
}