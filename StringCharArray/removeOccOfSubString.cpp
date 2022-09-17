#include<iostream>
#include<string.h>

using namespace std;
//https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5
string removeOccurrences(string s, string part) {
    
    int n = s.size();
	for(int i = 0; i+2<n && i<n; i++) {
        if (s[i]=='a' & s[i+1]=='b' & s[i+2]== 'c') {
            s.erase(i-1,i+2);
            i = i-2;
            cout<<"inside";
        }
        n = s.size();
    }
    return s;
}


int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    cout<<removeOccurrences(s,part);
}