//main logic is that we traverse the tree, and maintain a count, if that count exceeds number of nodes, it means it's not a complete binary tree, as the CBT is filled from left to right.(watch babbar if stuck)
class Solution {
  public:
    int countNode(struct Node* root){
        if (!root)  return 0;
        return 1+countNode(root->left)+countNode(root->right);
    }
    //max heap property(it will be called if we know for sure that the tree is CBT)
    bool maxOrder(struct Node* root)
    {
        //if leaf 
        if (root->left == NULL && root->right == NULL)  return true;
        //if only left child exist
        if (root->right == NULL) return (root->data > root->left->data);
        //if both child exist, check them, along with rest of the nodes
        return ((root->data > root->left->data) && (root->data > root->right->data)
                && (maxOrder(root->right) && maxOrder(root->left)));
    }
    bool isCBT(struct Node* root, int i, int &count)
    {
        if (!root)  return true;
        //index is more than the no. of nodes
        if (i >= count) return false;
        return isCBT(root->left, 2*i+1, count) && isCBT(root->right,2*i+2,count);
    }
    bool isHeap(struct Node* root) {
        // code here
        int count = countNode(root);
        return isCBT(root, 0, count) && maxOrder(root);
    }
};