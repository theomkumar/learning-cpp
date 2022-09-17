#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print (vector<string> &ans) {
    for (int i = 0; i<ans.size(); i++) {
        cout << ans[i] <<" ";
    }
}
void solve (string &str, vector<string> &ans, int idx)
{
    if (idx >= str.size()){
        ans.push_back(str);
        return;
    }
    for (int j = idx; j < str.size(); j++) {
        swap (str[idx], str[j]);
        solve (str, ans, idx+1);
        swap (str[idx], str[j]);
    }
}
vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    solve (str, ans, 0);
    //sort(ans.begin(), ans.end());
    print (ans);
    return ans;
}

int main() 
{
    string str = "abc";
    generatePermutations(str);
    return 0;
}