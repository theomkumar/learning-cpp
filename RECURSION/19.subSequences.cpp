#include<iostream>
#include<vector>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087

//return all subsequences except empty.

void print (vector<string> &ans) 
{
    for (int i = 0; i<ans.size(); i++) {
        cout << "(" <<ans[i] <<") ";
    }
    cout<<'\n';
}

void solve (string str, string output, int index, vector<string> & ans)
{
	//base case
	if (index >=str.size())
	{
	//	if (output != "\0")
		if (output.size())   //if string is empty then it won't be pushed to ans.
			ans.push_back(output);
		return;
	}
	//exclude
	solve (str, output, index+1, ans);
	//include
	char element = str[index];
	output.push_back(element);
	solve (str, output, index+1, ans);
	//output.pop_back(); (this as well)
}

vector<string> subsequences(string str){
	
	vector<string> ans;
	string output = "";
	int index = 0;
	
	solve (str,output,index,ans);
    print (ans);
	return ans;
}


int main() 
{
    string str = "abc";
    subsequences(str);
        
    return 0;
}