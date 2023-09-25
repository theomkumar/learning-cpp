//https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049


/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

//We can also use the property:
//successor = Ancestor or Right Subtree Min
//predecessor = Ancestor or Left Subtree Max
//Ancestor(pred or succ) we can find when we are finding the key if root->val < key it can be potential predecessor and vice versa.

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    
    int successor = -1, predecessor = -1;

    TreeNode *temp = root;
    //successor
    while (temp)
    {
        if (temp->data <= key)
        {
            temp = temp->right;
        }  
        else
        {
            successor = temp->data;
            temp = temp->left;
        }
    }
    //predecessor
    while(root)
    {
        if (root->data >= key)
        {
            root = root->left;
        }
        else
        {
            predecessor = root->data;
            root = root->right;
        }
    }
    return make_pair(predecessor, successor);
}