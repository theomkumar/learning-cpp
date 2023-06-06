//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void left (Node* root, vector<int> &ans)
    {
        //base case
        if(root == NULL || !(root->right) && !(root->left))
            return;
        ans.push_back(root -> data);
        if(root -> left)
            left(root -> left, ans);
        else
            left(root -> right, ans);
    }
    void child(Node* root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        if(!(root->left) && !(root->right))
        {
            ans.push_back(root -> data);
            return;
        }
        child(root -> left, ans);
        child(root -> right, ans);
    }
    void right(Node* root, vector<int> &ans)
    {
        if(!root || !(root->left) && !(root->right))
            return;
        
        if (root -> right)
            right(root -> right, ans);
        else
            right(root -> left, ans);
        //after return push as we need reverse order
        ans.push_back(root -> data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
        ans.push_back(root -> data);
        //Your code here

        //left
        left(root -> left, ans);
        //child
        child(root -> left, ans);
        child(root -> right, ans);
        //right
        right(root -> right, ans);
        return ans;
    }
};
