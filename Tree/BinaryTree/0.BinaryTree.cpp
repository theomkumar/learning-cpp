//non linear data structure -> linked list is linear node1->node2->node3
//tree is connected to multiple nodes
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node* left, * right;

    node(int d): data(d), left(nullptr),right(nullptr) {}
};

node* buildTree(node* root)
{
    int data;

    cout << "enter data: \n";
    cin >> data;

    if (data == -1)
        return NULL;
    root = new node(data);

    cout << "To add element to the left of " << root->data << '\n';
    root->left = buildTree(root->left);
    cout << "To add element to the right of " << root->data << '\n';
    root->right = buildTree(root->right);

    return root;
}
/*
Node *buildTree()
{
    int data;
    cin >> data;
    Node* tree = new Node(data);
}
*/
void levelOrderTraversal(node*& root)
{
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout << temp->data << ' ';

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << "\n\n";
}

void levelOrderStepWise(node* root)
{
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);
    //used as separator
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
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

void reverseLevelOrder(node*& root)
{
    if (root == NULL)
        return;

    //we can also use stack here for simplicity
    vector<int> ans;
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << ' ';
    }
    cout <<'\n';
}
void reverseOrderStepWise(node*& root)
{
    if (root == NULL)
        return;

    stack<int> s;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            s.push(temp->data);
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
        else
        {
            s.push('\n');
            if (!q.empty())
                q.push(NULL);//this will create separator for next level
        }
    }

    while (!s.empty())
    {
        if (s.top() == '\n')
            cout << '\n';
        else
            cout << s.top() << ' ';
        s.pop();
    }
    cout << "\n\n";
}

node* buildFromLevelOrder(node* root)
{
    cout << "enter root data: \n";
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    root = new node(data);

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout <<"add data to the left of "<<temp -> data<<'\n';
        cin >> data;
        if (data != -1)
        {
            temp -> left = new node(data);
            q.push(temp -> left);
        }

        cout << "add data to the right of "<< temp -> data << '\n';
        cin >> data;
        if (data != -1)
        {
            temp -> right = new node(data);
            q.push(temp -> right);
        }
    }
    return root;
}

/*
inOrder > Left Node Right
pre > Node Left Right
post > Left Right Node
*/

void inOrder (node *root)
{
    if (root == NULL)
        return;
    inOrder(root -> left);
    cout << root -> data <<' ';
    inOrder(root -> right);
}

void preOrder (node *root)
{
    if (root == NULL)
        return;
    cout << root -> data <<' ';
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder (node *root)
{
    if (root == NULL)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data <<' ';
}

void itPreOrder(node *root)
{
    if (root == NULL)
        return;
    stack<node*> s;
    s.push(root);

    while (!s.empty())
    {
        root = s.top();
        s.pop();
        cout << root -> data<<' ';

        if(root -> right)
            s.push(root -> right);

        if(root -> left)
            s.push(root -> left);
    }
    cout << '\n';
}
//LNR
void itInOrder(node *root)
{
    if (root == NULL)
        return;
    node* curr = root;

    stack<node*> s;
    cout << '\n';

    while(!s.empty() || curr)
    {
        if(curr)
        {
            s.push(curr);
            curr = curr -> left;
        }
        else
        {
            curr = s.top();
            s.pop();
            cout << curr -> data <<' ';
            curr = curr -> right;
        }
    }
}
//post -> LRN
void itPostOrder(node *root)
{
    if (root == NULL)
        return;

    stack<node*> s1, s2;
    s1.push(root);

    while(!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);

        if(root -> left)
            s1.push(root -> left);
        if(root -> right)
            s1.push(root -> right);
    }
    while(!s2.empty())
    {
        cout << s2.top()->data <<' ';
        s2.pop();
    }
    cout << '\n';
}
int main()
{
    node* root = NULL;
/*
    root = buildTree(root);
    // 3 1 -1 -1 7 4 6 -1 -1 -1 -1
    cout << "\nlevel Order Traversal \n";
    levelOrderTraversal(root);

    levelOrderStepWise(root);

    cout << "\nReverse Level Order Traversal \n";
    reverseLevelOrder(root);
    reverseOrderStepWise(root);
*/
// 3 1 7 -1 -1 4 -1 6 -1 -1 -1
    root = buildFromLevelOrder(root);
    levelOrderTraversal(root);

    cout <<"\nRecursive InOrder Traversal\n";
    inOrder(root);

    cout <<"\npreOrder Traversal\n";
    preOrder(root);
    
    cout <<"\npostOrder Traversal\n";
    postOrder(root);

    cout <<"\nIterative preOrder Traversal\n";
    itPreOrder(root);

    cout <<"\nIterative inOrder Traversal\n";
    itInOrder(root);

    cout <<"\nIterative postOrder Traversal\n";
    itPostOrder(root);

}