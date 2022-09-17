#include<iostream>
#include<vector>
#include<string>
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
using namespace std;

void print(vector<string> &ans)
{
    for (auto i:ans)
        cout << i <<" ";
    cout << "\n";
}

void solve (string digits, vector<string> &ans, string output, int index, string *mapping)
{
    //base case 
    if (index>=digits.size() ) {
        ans.push_back(output);
        return;
    }
    //index pointing to this number of input digit string and that number(say 2) is pointing to 
    //this value in mapping(i.e "abc");
    int number = digits[index] - '0';
    string value = mapping[number];
    
    //("abc"-> call for 'a','b','c')
    for (int i = 0; i<value.size(); i++)
    {
        output.push_back(value[i]);
        solve (digits,ans,output,index+1,mapping);
        output.pop_back();            
    }   
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;

    if (digits.size()==0)
        return ans;
    
    string output; //empty string

    int index = 0;//index of digits

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};//corresponding to the number
        
    solve (digits,ans,output,index,mapping);

    print (ans);


    return ans;                      
}

int main() 
{
    string digits = "23";
    letterCombinations(digits);
    return 0;
}