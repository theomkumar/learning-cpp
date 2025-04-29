/*
Rank is helping to reduce tree height.

Compression is helping by shortening the path to reach the parent.

*/
#include<bits/stdc++.h>
using namespace std;


int find (int i , vector<int> &parent){
    if (i == parent[i])
        return i;
    return parent[i] = find(parent[i], parent);
}
void Union (int x, int y, vector<int>&parent, vector<int> &rank) {
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);
    if (x_parent == y_parent) 
        return;
    if (rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent;
    }
    else if (rank[y_parent] > rank[x_parent]){
        parent[x_parent] = y_parent;
    }
    else {//doesn't matter
        parent[x_parent] = y_parent;
        rank[y_parent]++; 
    }
}


int main() 
{
    

    return 0;
}