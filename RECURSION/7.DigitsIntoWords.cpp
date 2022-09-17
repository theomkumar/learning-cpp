#include<iostream>
#include<vector>
//trying 
using namespace std;

int main() 
{
    string storeNO[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n; cin>>n; cout<<"\n";
    vector<string> ans;
    while (n)
    {
        int digit = n % 10;
        ans.push_back(storeNO[digit]);
    
        n = n/10;
    }
    
    //  for (int i = ans.size()-1; i; i--)
    for (int i = ans.size()-1; i>=0; i--)
    {
        cout<<ans[i]<<" ";
    }
}