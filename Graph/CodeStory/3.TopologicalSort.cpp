//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//APPROACH 1: DFS

with stack STANDARD METHOD::: send child first 
//
class Solution
{
	public:

	//Function to return list containing vertices in Topological order. 
	void dfs (vector<int> adj[], int u, vector<bool>&visited, stack<int> &st){
	    visited[u] = true;
	    for (auto &v : adj[u]){
	        if (!visited[v]) {
	            dfs (adj, v, visited, st);
	        }
	    }
	    st.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(V, false);
	    stack<int> st;
	    for (int i = 0; i < V; i++){
	        if (!visited[i]){
	            dfs(adj, i, visited, st);
	        }
	    }
	    vector<int> res;
	    while (!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};
//we can also do the same without stack, just result vector we just need to reverse it!
/*
	void dfs (vector<int> adj[], int u, vector<bool>&visited){
	    visited[u] = true;
	    for (auto &v : adj[u]){
	        if (!visited[v]) {
	            dfs (adj, v, visited);
	        }
	    }
	    res.push_back(u);
	}
    */
//# APPROACH 2:
	//KAHN's ALGO (TOPOLOGICAL SORT USING BFS)
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> inDegree(V,0);
	    for (int i = 0; i < V; i++){
	        for (auto &v : adj[i]){
	            inDegree[v]++;
	        }
	    }
	    queue<int>q;
	    for (int i = 0; i < V; i++){
	        if (inDegree[i] == 0){
	            q.push(i);
	        }
	    }

	    while (!q.empty()) {
	        int u = q.front();
	        res.push_back(u);
	        q.pop();
	        
	        for (auto &v : adj[u]){
	            if (--inDegree[v] == 0)
	                q.push(v);
	        }
	    }
	   
	    return res;
	}
//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends