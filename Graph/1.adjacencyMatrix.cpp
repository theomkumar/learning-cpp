//SC: MATRIX: O(N^2)

#include<iostream>
using namespace std;

int main(){
    //let's take 1-based indexing:
    int n, m;
    cout<<"Enter no. of node & edges : \n";
    cin>>n>>m;

    int adjMatrix[n+1][n+1];

    cout<<"enter connecting edges: \n";

    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    //print graph;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (adjMatrix[i][j] == 1)
                cout <<i<<"->"<<j<<endl;
        }
    }
    return 0;
}