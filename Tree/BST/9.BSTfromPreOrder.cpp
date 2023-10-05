
//METHOD 2: RANGE:  we can just iterate over preorder, and keep inserting the node using the range property of BST. (WE ONLY NEED MAXI RANGE , MINI NOT NEEDED)

//In the process of constructing a Binary Search Tree (BST) from a preorder traversal, we don’t need to check if an element is less than a minimum value (mini). This is because in preorder traversal, once we’ve moved past a node, all subsequent values will be either in its right subtree (and hence greater than the node), or in some ancestor’s right subtree (and hence also greater). Therefore, we only need to check if an element is greater than a maximum value (maxi) to ensure that it belongs to the correct subtree. This is why maxi is used but mini is not necessary in this context.

BinaryTreeNode<int>* solve (vector<int> &preorder,int mini, int maxi, int &i)
{
    if (i == preorder.size() || preorder[i] > maxi || preorder[i] < mini)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder,mini, root->data, i);
    root->right = solve(preorder,root->data, maxi, i);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i = 0, mini = INT_MIN, maxi = INT_MAX;
    return solve(preorder,mini,maxi,i);
}


class Solution {
    TreeNode* buildTree(vector<int>& preorder,int &i, int maxi)
    {
        if (i == preorder.size() || preorder[i] > maxi)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = buildTree(preorder,i,root->val);
        root->right = buildTree(preorder,i,maxi);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildTree(preorder,i,INT_MAX);
    }
};
/*
METHOD 1;
sort the vector, to get inorder. Now we have both inorder and preorder , we can use the logic of make a binary tree using preorder and inorder to make BST;
#include <bits/stdc++.h> 

   BinaryTreeNode<int>* build (vector<int>& preOrder,unordered_map<int,int>&m,int &idx, int l, int r)
    {
        //base case
        if (l > r)
            return NULL;
        //process current node
        int rootElement = preOrder[idx++];
        int rootIdx = m[rootElement];
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(rootElement);
        //recursive call
        newNode->left = build(preOrder,m,idx,l,rootIdx-1);
        newNode->right = build(preOrder,m,idx,rootIdx+1,r);
        return newNode;
    }

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    vector<int> inorder = preorder;
    sort(inorder.begin(),inorder.end());

    unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

    int idx = 0, l = 0, r = inorder.size()-1;

    BinaryTreeNode<int>* ans = build(preorder, m, idx, l, r);
    return ans;
}
*/