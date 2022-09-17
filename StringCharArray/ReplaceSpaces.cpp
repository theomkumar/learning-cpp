#include<iostream>
#include<string.h>

using namespace std;
//https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5
string replaceSpaces(string &str){
    string temp;
    int n = str.size();
	for(int i = 0; i<n; i++) {
        if (str[i]==' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0'); 
        }
        else temp.push_back(str[i]);
    }
    return temp;
}


int main() {
    string str = "Hello From the other side";
    cout<<replaceSpaces(str);
}