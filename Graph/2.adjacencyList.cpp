//SC: O(2*Edges)
#include<iostream>
#include<vector>
using namespace std;
//undirected graph, in case of directed graph we can just commment out line no. 

int main() {
    //let's take 0-based indexing:
    int n, m;
    cout << "Enter no. of node & edges : \n";
    cin >> n >> m;

    //vector<vector<int>> adjList(n);
    vector<int> adjList[n];

    cout << "enter connecting edges: \n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);//comment this in case of directed graph
    }

    //print graph;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << i << "->" << adjList[i][j] << endl;
        }
    }
    return 0;
}