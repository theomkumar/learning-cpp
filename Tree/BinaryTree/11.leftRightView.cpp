//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
//recursion logic: for every level , one element is considered, therefore we can use relation between level and size of vector
//****************** USING RECURSION left view***************  
void solve(Node* root, vector<int> &ans, int level)
{
    if(root == NULL)
        return;
    if(ans.size() == level)
        ans.push_back(root -> data);
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}
vector<int> leftView(Node* root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
//****************** USING RECURSION right view view***************  
void solve(Node* root, vector<int> &ans, int level)
{
    if(root == NULL)
        return;
    if(ans.size() == level)
        ans.push_back(root -> data);
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}

// *********** USING LEVEL ORDER TRAVERSAL********

//for right view just comment the condition check before adding data to map
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans; 
    //node,level
    queue<pair<Node*, int>> q;
    //level, val
    map<int,int> m;

    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* curr = temp.first;
        int level = temp.second;
        if(m.find(level) == m.end())
            m[level] = curr -> data;

        if(curr -> left) 
            q.push({curr->left, level+1});
        if(curr -> right) 
            q.push({curr->right, level+1});
    }
    for (auto i:m)
        ans.push_back(i.second);
    return ans;
}