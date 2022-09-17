#include<iostream>
#include<vector>
#include<string>

using namespace std;

void print (vector<string> & ans)
{
    for (int i = 0; i <ans.size(); i++) 
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout <<ans[i][j] <<" ";
        }
        cout <<"| ";
    }
    
}

bool isPossible (vector<vector<int>>&m, vector<vector<bool>>& visited, int i, int j, int n)
{
    if ((i >= 0 && j >= 0 && i < n && j < n) && m[i][j] == 1 && visited[i][j] == 0)
    {
        return true;
    }
    return false;
}

void solve(vector<vector<int>>& m, vector<string>& ans, string &path, vector<vector<bool>> &visited, int i, int j, int n) 
{
    if (i == n-1 && j == n-1) {
        ans.push_back(path);
        return;
    }
    //marking current position as visited
    visited[i][j] = 1;
    //down
    int newi = i + 1;
    int newj = j;
    if ( isPossible(m, visited, newi, newj, n) ) 
    {
        path.push_back('D');
        solve (m, ans, path, visited, newi, newj, n);
        path.pop_back();
    }
    //right
    newi = i;
    newj = j+1;
    if (isPossible(m, visited, newi, newj, n) )
    {
        path.push_back('R');
        solve (m, ans,path, visited, newi, newj, n);
        path.pop_back();
    }
    //left
    newi = i;
    newj = j-1;
    if (isPossible(m, visited, newi, newj, n))
    {
        path.push_back('L');
        solve(m, ans, path, visited, newi, newj, n);
        path.pop_back();
    }
    //up
    newi = i-1;
    newj = j;
    if (isPossible(m, visited, newi, newj, n) )
    {
        path.push_back('U');
        solve (m, ans, path, visited, newi, newj, n);
        path.pop_back();
    }
    //marking visited zero while returning to previous.
    visited[i][j] = 0;
}

int main() 
{
    vector<vector<int>> m = { {1, 0, 0, 0},
                              {1, 1, 0, 1}, 
                              {1, 1, 0, 0},
                              {0, 1, 1, 1} };
    int n = m.size();
    vector<string> ans;
    string path = "";
    vector<vector<bool>> visited(n, vector<bool> (n, 0));
    //if source is at (0)
    if (m[0][0] != 0)
    {
        solve(m, ans, path, visited, 0, 0, n);
    }
    
    print (ans);
    
    return 0;
}