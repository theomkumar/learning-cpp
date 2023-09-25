/*
For every node :
Left->data < root->data;
right->data > root->data;

TIME COMPLEXITY :

FOR INSERTION : BEST CASE O(log n),
                 Worst O(N)i.e skewed tree
                Average O(Height)


INORDER OF BST IS ALWAYS SORTED

*/
#include<iostream>
#include<queue>

using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

void minValue(Node* root)
{
    Node* temp = root;
    while(temp->left) 
        temp = temp->left;
    cout << "\nminimum value is "<<temp->data<<endl;

}
void maxValue(Node* root)
{
    Node* temp = root;

    while(temp->right) 
        temp = temp->right;
    cout << "maximum value is "<<temp->data<<endl;

}
void inOrder (Node *root)
{
    if (root == NULL)
        return;
    inOrder(root -> left);
    cout << root -> data <<' ';
    inOrder(root -> right);
}
void preOrder (Node *root)
{
    if (root == NULL)
        return;
    cout << root -> data <<' ';
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder (Node *root)
{
    if (root == NULL)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data <<' ';
}
void levelOrderTraversal(Node*& root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    //used as separator
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp != NULL)
        {
            cout << temp->data << ' ';
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        else
        {
            cout << '\n';
            if (!q.empty())
                q.push(NULL);
        }

    }
    cout << '\n';
}

Node* insertIntoBST (Node* root, int d)
{
    //base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d < root->data)
        root->left = insertIntoBST(root->left,d);
    else
        root->right = insertIntoBST(root->right,d);
    return root;
}
void takeInput(Node* &root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main()
{
    Node* root = NULL;
    cout <<"Enter Data To Create BST \n";
    takeInput(root);

    cout <<"Print Level Order Traversal \n";
    levelOrderTraversal(root);

    cout <<"\nPrint Inorder Traversal \n";
    inOrder(root);

    cout <<"\nPrint preorder Traversal \n";
    preOrder(root);

    cout <<"\nPrint postorder Traversal \n";
    postOrder(root);

    minValue(root);
    maxValue(root);

    return 0;
}