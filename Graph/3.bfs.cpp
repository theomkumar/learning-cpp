//https://www.codingninjas.com/studio/problems/bfs-in-graph_973002
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> visited(n,0),bfs;
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto i: adj[node]){
            if (visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return bfs;
}