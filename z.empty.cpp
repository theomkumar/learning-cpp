#include<iostream>
#include<string>
using namespace std;


string removeStars(string s) {
    int j = 0;
    for (int i = 0; i < s.size(); ++i) 
    {
        if (s[i] == '*')
        {
            j--;
        }
        else
        {
            s[j++] = s[i];
        }
    }
    return s.substr(0,j);
}
int main() 
{
    string s1 = "0123456789";
    cout <<s1 << endl;
    cout <<s1.substr()
    // cout << "BEFORE: "<< s1;

    // cout <<"\nAfter: "<< removeStars(s1);

    
    return 0;
}