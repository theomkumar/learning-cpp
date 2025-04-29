//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int find (int vertex, vector<int> &parent) {
        if (vertex == parent[vertex])
            return vertex;
        return parent[vertex] = find(parent[vertex], parent);
    }
    void Union (int x, int y, vector<int> &parent, vector<int> &rank) {
        int x_parent = find(x, parent), y_parent = find(y,parent);
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    vector<int> rank(V);
	    vector<int> parent(V);
	    
	    for (int i = 0; i < V; i++) {
		        parent[i] = i;
		        rank[i] = 0;
	    }

	        
	   for (int i = 0; i < V; i++) {
	       
	       for (auto &j : adj[i]) {
	           if (i < j) continue;
	           int i_parent = find(i, parent);
	           int j_parent = find(j, parent);
	           if (i_parent == j_parent)
	            return 1;
	           Union(i, j, parent,rank);
	       }
	   }
	   return 0;
	}
};

//{ Driver Code Starts.
int main(){
        int V = 10;
		vector<int>adj[V];
	return 0;
}
// } Driver Code Ends