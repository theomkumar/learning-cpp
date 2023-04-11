// <= 2 child
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node
{
public:
    int data;
    node* left, * right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    ~node()
    {
        delete left;
        delete right;
    }
};

node* buildTree(node* root)
{
    int data;
    cout << "enter data: ";
    cin >> data;

    //to stop basically(no child)
    if (data == -1)
        return NULL;

    root = new node(data);

    cout << "enter data to insert in left of " << data << endl;
    root->left = (buildTree(root->left));
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = (buildTree(root->right));
    return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);

    //create a separater indicating the level is complete
    q.push(NULL);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            cout << '\n';
            q.pop();
            //if there are some child nodes
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << (q.front())->data << ' ';
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);

            q.pop();
        }
    }

}

void reverseOrderLevelTraversal(node *root)
{
    if (root == NULL)
        return;
    stack<node*> st;
    queue<node*> q;
    q.push(root);
    st.push(root);

    //create a separater indicating the level is complete
    q.push(NULL);
    st.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            //if there are some child nodes
            if (!q.empty())
            {
                q.push(NULL);
                st.push(NULL);
            }
        }
        else
        {
            if (q.front()->right)
            {
                q.push(q.front()->right);
                st.push(q.front()->right);
            }
            if (q.front()->left)
            {
                q.push(q.front()->left);
                st.push(q.front()->left);
            }

            q.pop();
        }
    }
    while (!st.empty())
    {
        if (st.top() == NULL)
            cout <<'\n';
        else
            cout <<st.top()->data<<' ';
        st.pop();
    }
}

//LNR -> go left,Print, go right 
void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root -> left);
    cout << root -> data <<' ';
    inorder(root -> right);
}
//NLR -> node print, left, right
void preorder(node* root)
{
    if (root == NULL)
        return;
    cout << root -> data <<' ';
    preorder(root -> left);
    preorder(root -> right);
}
//LRN -> left, right, print
void postorder(node* root)
{
    if (root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data <<' ';
}

void buildFromLevelOrder(node* &root)
{
    cout<<"\n enter root data: ";
    int rootData;
    cin >> rootData;
    root = new node(rootData);
    queue<node*>q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout <<"enter data for left of "<<temp->data<<endl;
        int leftData; 
        cin >> leftData;
        if (leftData != -1)
        {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout <<"enter data for right of "<<temp->data<<endl;
        int rightData; 
        cin >> rightData;
        if (rightData != -1)
        {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    node* root = NULL;
    //creating a Tree
    root = buildTree(root);

    // i/p: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //levelOrderTraversalT
    cout << "\n Printing the level order Traversal Output:  \n";
    levelOrderTraversal(root);

    cout << "\n Printing the reverse level order Traversal output: \n";
    reverseOrderLevelTraversal(root);

    cout << "\nprinting inorder traversal \n";
    inorder(root);  
    cout << "\nprinting preorder traversal \n";
    preorder(root);  
    cout << "\nprinting postorder traversal \n";
    postorder(root);  


    node* root1 = NULL;
    //ip:  1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root1);  
    levelOrderTraversal(root1);  
    delete root;
    return 0;
}