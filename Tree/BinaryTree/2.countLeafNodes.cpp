//https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void inOrder(BinaryTreeNode<int> *root, int &cnt)
{
    if (root == NULL)
        return;
    inOrder(root->left, cnt);

    if(root->left == NULL && root -> right == NULL)
        cnt++;

    inOrder(root->right, cnt);

}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int cnt = 0;
    inOrder(root, cnt);
    return cnt;
}