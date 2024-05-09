//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
/*
    bool dfs (vector<int> adj[], int curr, int parent, vector<int> &visited){
        visited[curr] = 1;
        for (auto &neighbour : adj[curr]){
            if (neighbour == parent) continue;
            if (visited[neighbour])
                return true;
            if (dfs(adj, neighbour, curr, visited))
                return true;
        }
        return false;
    }
*/
    bool bfs (vector<int> adj[], int curr, int parent, vector<int> &visited){
        visited[curr] = 1;
        queue<pair<int, int>> q;
        q.push({curr,parent});
        
        while (!q.empty()){
            auto top = q.front();
            int parent = top.second;
            int curr = top.first;
            q.pop();
            for (auto &neighbour : adj[curr]){
                if (neighbour == parent) continue;
                if (visited[neighbour])
                    return true;
                visited[neighbour] = 1;
                q.push({neighbour, curr});
            }
        }
       
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        for (int i = 0; i < V; i++){
            if (visited[i] == 0 && bfs(adj, i, -1, visited)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends