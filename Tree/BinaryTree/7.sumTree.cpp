/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false

//**************O(N^2)
class Solution
{
    int sum(Node* root)
    {
        if (root == NULL)
            return 0;
        if (!(root -> left) && !(root -> right))
            return root -> data;
        int right = sum(root -> right);
        int left = sum(root -> left);
        int ans = root -> data + right + left;
        return ans;
    }
    
    public:
    bool isSumTree(Node* root)
    {
        if (root == NULL || (!(root -> left) && !(root -> right)))
            return true;
        bool left = isSumTree(root -> left);
        bool right = isSumTree(root -> right);
        return (root -> data == sum(root -> left) + sum(root -> right)) && left && right;
       
    }
};

//************* O(N)

class Solution
{
    public:
    pair<bool,int> sumTree(Node* root)
    {
        if (root == NULL)
            return make_pair(true,0);
        if (root -> left == NULL && root -> right == NULL)
            return make_pair(true,root -> data);
        pair<bool,int> leftAns = sumTree(root->left);
        pair<bool,int> rightAns = sumTree(root -> right);
        
        pair<bool,int> ans;
        //isSum conditions(3)
        ans.first = ( leftAns.first && rightAns.first && (root -> data == leftAns.second + rightAns.second) );
        ans.second = root->data + leftAns.second + rightAns.second;
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
        return sumTree(root).first;
    }
};