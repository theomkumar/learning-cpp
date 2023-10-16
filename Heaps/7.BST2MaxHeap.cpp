//same as min heap logic
class Solution{
  public:
      void inorder(Node* root, vector<int> &v)
    {
    	if (root == NULL)
    		return;
    	//LNR
    	inorder(root->left,v);
    	v.push_back(root->data);
    	inorder(root->right,v);
    }
    void makeMaxHeap(Node *root, vector<int>&v, int &i)
    {
        if (root == NULL)
            return;
        //N -> R -> L
        root->data = v[i++];
        makeMaxHeap(root->right,v,i);
        makeMaxHeap(root->left,v,i);
    }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> v;
    	inorder(root,v);
    	reverse(v.begin(),v.end());
    	int i = 0;
    	makeMaxHeap(root,v,i);
    }    
};