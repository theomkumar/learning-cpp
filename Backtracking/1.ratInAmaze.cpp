#include <bits/stdc++.h> 
using namespace std;

//1
// User function template for C++

class Solution{
    private:
    bool isPossible ( int x, int y, vector<vector<int>> &m, vector<vector<bool>> &visited, int n)
    {
        if (x >= 0 && x < n && y >= 0 && y < n && m[x][y] == 1 && visited[x][y] == 0)
            return true;
        return false;
    }
    void solve ( vector<vector<int>> &m, vector<string> &ans, vector<vector<bool>> &visited, string &path, int x, int y, int n)
    {
        //base case 
        if (x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
         
        //down 
        int newx = x+1;
        int newy = y;
        
        if (isPossible(newx, newy, m, visited, n))
        {
            path.push_back('D');
            solve(m, ans, visited, path, newx, newy, n);
            path.pop_back();
        }
        //right
        newx = x;
        newy = y+1;
        
        if (isPossible(newx, newy, m, visited, n))
        {
            path.push_back('R');
            solve(m, ans, visited, path, newx, newy, n);
            path.pop_back();
        }
        //up
        newx = x-1;
        newy = y;
     
        if (isPossible(newx, newy, m, visited, n))
        {
            path.push_back('U');
            solve(m, ans, visited, path, newx, newy, n);
            path.pop_back();
        }
        //left
        newx = x;
        newy = y-1;
        
        if (isPossible(newx, newy, m, visited, n))
        {
            path.push_back('L');
            solve(m, ans, visited, path, newx, newy, n);
            path.pop_back();
        }
        //unmarking visited after returning from path (pop back)
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        //visited will keep mark of visited path
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        string path = "";
        if (m[0][0] == 0)
            return ans;
        solve(m, ans, visited, path, 0, 0, n);
        sort(ans.begin(), ans.end() );
        return ans;
    }
};

    

class Solution{
    public:
    void solve (vector<vector<int>> &maze, int &n, string currPath,vector<string>&ans,vector<vector<bool>> &visited,
     int x, int y)
    {
        if (x == n-1 && y == n-1){
            ans.push_back(currPath);
            return;
        }
        //Down
        if(x+1 < n && maze[x+1][y] != 0 && !(visited[x+1][y])){
            visited[x][y] = true;
            solve(maze,n,currPath+'D',ans,visited,x+1,y);
            visited[x][y] = false;
        }
        //left
        if(y-1 >= 0 && maze[x][y-1] != 0 && !(visited[x][y-1])){
            visited[x][y] = true;
            solve(maze,n,currPath+'L',ans,visited,x,y-1);
            visited[x][y] = false;
        }
        //right
        if(y+1 < n && maze[x][y+1] != 0 && !(visited[x][y+1])){
            visited[x][y] = true;
            solve(maze,n,currPath+'R',ans,visited,x,y+1);
            visited[x][y] = false;
        }
        //UP
        if(x-1 >= 0 && maze[x-1][y] != 0 && !(visited[x-1][y])){
            visited[x][y] = true;
            solve(maze,n,currPath+'U',ans,visited,x-1,y);
            visited[x][y] = false;
        }        
    }
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // Your code goes here
        vector<string> ans;
        string currPath = "";
        
        if (maze[0][0] == 0)
            return ans;
        //create 2-D visited array
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        solve(maze,n,currPath,ans,visited,0,0);
        return ans;
    }
};

    
//2
    bool isPossible(vector<vector<int>>&maze,int n,vector<vector<bool>> &visited,
     int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == false);
     }

    void solve (vector<vector<int>> &maze, int &n, string currPath,vector<string>&ans,vector<vector<bool>> &visited,
     int x, int y)
    {
        if (x == n-1 && y == n-1){
            ans.push_back(currPath);
            return;
        }
        visited[x][y] = true;
        //Down
        if(isPossible(maze,n,visited,x+1,y)){  
            solve(maze,n,currPath+'D',ans,visited,x+1,y); 
        }
        //left
        if(isPossible(maze,n,visited,x,y-1)){
            solve(maze,n,currPath+'L',ans,visited,x,y-1);
        }
        //right
        if(isPossible(maze,n,visited,x,y+1)){
            solve(maze,n,currPath+'R',ans,visited,x,y+1);
        }
        //UP
        if(isPossible(maze,n,visited,x-1,y)){
            solve(maze,n,currPath+'U',ans,visited,x-1,y);
        }   
        visited[x][y] = false;     
    }
    vector<string> searchMaze(vector<vector<int>> &maze, int n) {
        // Your code goes here
        vector<string> ans;
        string currPath = "";
        
        if (maze[0][0] == 0)
            return ans;
        //create 2-D visited array
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        solve(maze,n,currPath,ans,visited,0,0);
        return ans;
    }
//3 striver