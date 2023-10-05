//used the code for merging two sorted arrays, That's it!!
//TC = O(N+M) SC: O(M+N)

void inorder(TreeNode* root, vector<int> &in)
{
    if (root == NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> a, b;

    inorder(root1,a);
    inorder(root2,b);

    //merge a and b into answer vector.
    vector<int> ans;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])   
            ans.push_back(a[i++]);
            
        else if (b[j] < a[i]) 
            ans.push_back(b[j++]);
       
        else
        {
            ans.push_back(a[i]);
            i++;
        }
    }
    while (i < a.size())
        ans.push_back(a[i++]);

    while (j < b.size())
        ans.push_back(b[j++]);

    return ans;
}
