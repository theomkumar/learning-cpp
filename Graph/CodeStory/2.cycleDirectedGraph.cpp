class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs (vector<int> adj[], int curr, vector<int> &visited,vector<int> &pathVisited){
        visited[curr] = 1;
        pathVisited[curr] = 1;
        
        for (auto &neighbour : adj[curr]){
            if (pathVisited[neighbour])
                return true;
            if (visited[neighbour] == 0 && dfs(adj, neighbour, visited, pathVisited))
                return true;
        }
        pathVisited[curr] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        for (int i = 0; i < V; i++){
            if (visited[i] == 0 && dfs(adj, i,visited, pathVisited)){
                return true;
            }
        }
        return false;
    }
};