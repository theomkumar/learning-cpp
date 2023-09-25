//practice
class Solution {
    int findMax(TreeNode* root)
    {
        while (root->right)
            root = root->right;

        return root->val;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;

        if (root->val == key)
        {
            //0 child
            if (!(root->left) && !(root->right))
            {
                delete root;
                return NULL;
            }
            //1 child (2 cases)
            else if (root->left && !(root->right))
            {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else if (!(root->left) && (root->right))
            {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            //2 child (2 ways: replace with right subtree Min or left subtree max)
            //replacing with left subtree max;
            else if (root->left && root->right)
            {
                int maxLeft = findMax(root->left);
                root->val = maxLeft;
                root->left = deleteNode(root->left, maxLeft);
                return root;
            }
        }
        else if (root->val > key)
            root->left = deleteNode(root->left,key);
        else //if (root->val < key)
            root->right = deleteNode(root->right,key);

        return root;
    }
};

/*
class Solution {
    int minVal(TreeNode* root)
    {
        TreeNode* temp = root;
        while (temp->left)
            temp = temp->left;
        return temp->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if (root == NULL)
            return root; 
        if (root->val == key)
        {
            //0child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            //1 child
            if (root->left == NULL && root->right)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == NULL && root->left)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // 2 child 
            if (root->left && root->right)
            {
                //2 ways to solve replace root with(1. right subtree min, left subtree max)
                int rightMin = minVal(root->right);

                root->val = rightMin;
                root->right = deleteNode(root->right, rightMin);
                return root;
            }

        }
        else if (root->val > key)
            root->left = deleteNode(root->left,key);
        else //if (root->val < key)
            root->right = deleteNode(root->right,key);
        return root;
    }
};

*/