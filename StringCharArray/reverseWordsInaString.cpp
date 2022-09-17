#include<iostream>
using namespace std;

void reverse1 (string &s,int start,int end) {
    while(start<end)
        swap(s[start++],s[end--]);
    
}

int main() {
    
    //string s = {'t','h','e',' ','m','a','n',' ','i','s',' ','n','i','c','e'};
    string s = "cat a";
    int n = s.size();

    cout<<"input: "<<s<<"\n";

    reverse1(s,0, n-1);

    cout<<"after revering: "<<s<<"\n";

    int j = 0;
    
    for(int i = 0; i < n; i++){
        if(s[i] == ' '){
            reverse1(s,j,i-1);

            cout<<s<<'\n';

            j = i + 1;
        }
        else if (i==n-1) 
            reverse1(s,j,n-1);
    }
    cout<<s;
}