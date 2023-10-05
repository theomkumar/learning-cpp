//https://practice.geeksforgeeks.org/problems/largest-bst/1

//TC: O(N) SC: O(N)
class info {
    public:
    int maxi, mini, size;
    bool isBST;
};
class Solution{
    
    public:
    info solve(Node* root, int &maxSize)
    {
        //base case
        if (root == NULL)
            return {INT_MIN,INT_MAX,0,true};
        //recursion will solve left & right 
        info left = solve(root->left,maxSize);
        info right = solve(root->right,maxSize);
        //we solve for Current Node
        info currNode;
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);
        //isBST
        currNode.isBST = (left.isBST && right.isBST &&
        (root->data > left.maxi && root->data < right.mini)) ? true : false;
    
        //answer update
        if (currNode.isBST)
            maxSize = max(maxSize,currNode.size);
        return currNode;
    }

    int largestBst(Node * root){
        // Write your code here.
        int maxSize = 0;
        info largestBstInfo = solve(root,maxSize);
        return maxSize;
    }