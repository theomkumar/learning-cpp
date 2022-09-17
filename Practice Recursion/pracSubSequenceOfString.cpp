#include<iostream>
#include<vector>
#include<string>

using namespace std;

void print(vector<string>& arr)
{
    for (int i = 0; i < arr.size(); i++) 
    {
        cout << "("<< arr[i] <<") ";
    }
    cout <<'\n';
}

void solve (string subseq, vector<string>& ans, string& output, int idx)
{
    if (idx >= subseq.size())
    {
        ans.push_back(output);
        return;
    }
    //exclude
    solve (subseq, ans, output, idx+1);
    //include
    output.push_back(subseq[idx]);
    solve (subseq, ans, output, idx+1);
    output.pop_back();

}
int main() 
{
    string subseq = {"abc"};
    vector<string>ans;
    string output = {""};
    solve(subseq, ans, output, 0);
    print (ans);
}