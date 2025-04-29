/*
* AKA UNION FIND
Disjoint Set means, those sets whose union is null is called disjoint set

DSU has 2 main operations::
1. join: combine 2 given sets
2. find parent: tell if two members (b, g) belong to the same set or not.

*/
int find (int i , vector<int> &parent){
    if (i == parent[i])
        return i;
    return find(parent[i], parent);
}

void union (int x, int y, vector<int> &parent){
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);
    if (x_parent != y_parent){
        parent[x_parent] = y_parent;
    }
}
