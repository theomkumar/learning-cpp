//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function


//// <EASY METHOD:

void findPath(Node* root, vector<int> &path, int k, int target, int &ans)
{
    if (!root)
        return;
    if (root->data == target)
    {
        int n = path.size();
        if (n-k >= 0)
            ans = path[n-k];
    }
    path.push_back(root->data);
    
    findPath(root->left, path, k, target, ans);
    findPath(root->right, path, k, target, ans);
    path.pop_back();
}
int kthAncestor(Node *root, int k, int target)
{
    // Code here
    int ans = -1;
    vector<int> path;
    findPath(root, path, k, target, ans);
    return ans;
}

//OPTIMISED 
/* LOGIC:
if we find target node, we'll keep returning target node, until we make k = 0, if k = 0, 
then it's the Kth ancestor, so we'll return this curr node, from now onwards.

NOTE : if we ultimately returned target node -> it means we couldn't find Kth ancestor so return -1

*/
Node* solve (Node* root, int &k, int node)
{
    if (!root)
        return NULL;

    if (root->data == node)
        return root;
    
    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);
    
    if (left)
    {
        k--;
        if (k == 0)
            return root;
        else    
            return left;
    }
    else if (right)
    {
        k--;
        if (k == 0)
            return root;
        else
            return right;
    }
    else
        return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    return ans->data;
}
