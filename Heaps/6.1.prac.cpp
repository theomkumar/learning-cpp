#include <bits/stdc++.h> 
using namespace std;
    
    //Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

void inorder(BinaryTreeNode* root, vector<int> &v)
{
	if (root == NULL)
		return;
	//LNR
	inorder(root->left,v);
	v.push_back(root->data);
	inorder(root->right,v);
}
void makeMinHeap(BinaryTreeNode *root, vector<int>&v, int &i)
{
    if (root == NULL)
        return;
    //N -> L -> R
    root->data = v[i++];
    makeMinHeap(root->left,v,i);
    makeMinHeap(root->right,v,i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int> v;
	inorder(root,v);
	int i = 0;
	makeMinHeap(root,v,i);
	return root;
}
int main()
{
    BinaryTreeNode* root = new BinaryTreeNode(7);
    root->left = new BinaryTreeNode(6);
    root->left = new BinaryTreeNode(6);
}
