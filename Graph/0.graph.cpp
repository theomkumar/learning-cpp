/*
Nodes  : entity to store data
& edges : connection nodes
Types:
1. directed -> one direction of edges 
2. undirected -> both direction

Degree = no of edges connected to the node
in case of directed we in-degree & out-degree    

->weighted graph: default weight if not mentioned is unit weight i.e 1
-> path: sequence of node from point p to q

Cyclic could be wighted
-> cyclic directed graph: forming cycle
-> acyclic directed graph:

GRAPH
1. Adjacency matrix : using 2-D matrix to represent graph of n nodes, SC: O(N^2)

2. Adjacency List
  
*/
//implementation of Adjacency list can be done by 
#include<iostream>
#include<unordered_map>
#include<list>

class graph{
    public:
    std::unordered_map<int,std::list<int> >adj;

    void addEdge(int u,int v,bool isDirected)
    {
        //true -> undirected

        //create an edge from u to v
        adj[u].push_back(v);
        if (isDirected == false)
            adj[v].push_back(u);
    }
    void print(){
        for (auto i:adj){
            std::cout << i.first << "-> ";
            for(auto j: i.second)
                std::cout << j <<", ";

            std::cout<<std::endl;
        }
    }

};
int main(){
    graph g;
    int n;
    std::cout << "Enter no. of nodes\n";
    std::cin>>n;
    int m;
    std::cout<<"Enter the number of edges\n";
    std::cin>>m;

    std::cout<<"Enter edges: ";
    for(int i = 0; i < m; i++){
        int u,v;
        std::cin >> u >> v;
        g.addEdge(u,v,false);
    }
    g.print();
}