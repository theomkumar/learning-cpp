#include<iostream>
using namespace std;

bool isPalindrome(string s, int index)
{
    s.erase(s.begin()+index);
    for (int i = 0; i<=s.size()/2; i++) {
        if (s[i]!=s[s.size()-i-1])
            return false;
    }
    return true; 
}

int main() 
{
    int t;
    cin>>t;
    for (int i = 0; i<t; i++) {
        int n;
        cin>>n;
        string s;
        char C = ' ';
        s.append(C,n);
        cin>>s;

    int count = 0;

    for (int i = 0; i<n; i++) {
        if (isPalindrome(s,i)) {
            count++;
        }
    }
    cout<<count<<"\n";
    }
    
    return 0;
}