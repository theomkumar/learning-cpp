Intuition
Same approach as PostOrder/PreOrder
We want root node to begin with, Post-Order = LRN(left, right, node), if we reverse it -> NRL we get the root node.

Steps:
1.iterate over postorder in reverse direction (rootIdx)
2.Follow the reverse Order (N->R->L) i.e Build Root Node -> right subtree -> left subtree
3.find pivotElement
4.find pivotIndex in preorder, i.e stored in map
5.split into 2 subtree right & left & call it recursively

Complexity
Time complexity: O(N)
Space complexity: O(N)
Code
private:

    // N -> R -> L
    
    TreeNode* build(vector<int>& inorder, vector<int> &postorder, unordered_map<int,int> &  
                        inorderIdx, int left, int right, int &rootIdx)
    {
        if (left > right)
            return NULL;
        //N
        int pivotElement = postorder[rootIdx--];
        int pivotIdx = inorderIdx[pivotElement];
        TreeNode* root = new TreeNode(pivotElement);

        //R
        root->right = build(inorder, postorder, inorderIdx, pivotIdx+1, right,rootIdx);
        //L
        root->left = build(inorder, postorder, inorderIdx, left, pivotIdx-1,rootIdx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderIdx;
        for(int i = 0; i < inorder.size(); i++)
            inorderIdx[inorder[i]] = i;
        //iterate backwards of postorder i.e NRL
        int rootIdx = inorder.size()-1;
        TreeNode* rootNode = build(inorder,postorder,inorderIdx,0, inorder.size()-1, rootIdx);
        return rootNode;
    }
};