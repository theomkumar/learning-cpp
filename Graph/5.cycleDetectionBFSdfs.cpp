#include<unordered_map>
#include<list>
#include<queue>
#include<string>

using namespace std;

//TC : O(N)
bool isCyclicDFS(unordered_map<int, list<int>> &adj,
                unordered_map<int,bool> &vis,
                int node, int parent)
{
    vis[node] = true;
    for(auto neighbour:adj[node]){
        if (vis[neighbour] && neighbour != parent)
            return true;
        else if (!vis[neighbour]){//
            bool cycleDetected = isCyclicDFS(adj,vis,neighbour,node);
            if (cycleDetected)
                return true; 
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;


    //create adj list
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    unordered_map<int,bool> vis;
    
    //disconnected graph-> thus check all sub-components
    for(int i = 0; i < n; i++){
        if (!vis[i]){
            //isCyclicBFS(adj,vis,i)
            if (isCyclicDFS(adj,vis, i, -1)){
                return "Yes";
            }
        }
    }
    return "No";
}