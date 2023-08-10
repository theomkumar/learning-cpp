/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    vector<int> ans;

    void printLeftBoundary(Node* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        ans.push_back(root->data);

        if (root->left)
            printLeftBoundary(root->left);
        else
            printLeftBoundary(root->right);
    }

    void printLeafNodes(Node* root) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }

        printLeafNodes(root->left);
        printLeafNodes(root->right);
    }

    void printRightBoundary(Node* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
            printRightBoundary(root->right);
        else
            printRightBoundary(root->left);

        ans.push_back(root->data);
    }

public:
    vector<int> boundary(Node* root) {
        if (root == NULL)
            return ans;

        ans.push_back(root->data);
        //edge case when root is leaf, it will be printed twice so need this condition, alternatively we can call leafNode(right subtree) and leafNode(leftSubtree) to avoid this edge case.
        if (root -> left == NULL && root -> right == NULL)
            return ans;

        printLeftBoundary(root->left);
        printLeafNodes(root);
        printRightBoundary(root->right);

        return ans;
    }
};