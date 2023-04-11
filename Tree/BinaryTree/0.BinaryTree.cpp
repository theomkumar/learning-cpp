#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node* left, * right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
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

    //we can also use stack here
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

    while(!s.empty())
    {
        node* temp = s.top();
        s.pop();
        if(temp == NULL)
            continue;
        else
        {
            cout<<temp->data<<' ';

            if(temp -> right)
                s.push(temp->right);

            if(temp -> left)
                s.push(temp->left);
        }
    }
    cout << '\n';
}
//LNR
void itInOrder(node *root)
{
    if (root == NULL)
        return;
    node* temp = root;

    stack<node*> s;


    while(!s.empty() || temp != NULL)
    {
        if(temp != NULL)
        {
            s.push(temp);
            temp = temp -> left;
        }
        else
        {
            temp = s.top();
            s.pop();
            cout << temp->data<<' ';
            temp = temp -> right;
        }
    }
    cout << '\n';
}
//post -> LRN
void itPostOrder(node *root)
{
    if (root == NULL)
        return;
    node* temp = root;

    stack<node*> s;


    while(!s.empty() || temp != NULL)
    {
        if(temp != NULL)
        {
            s.push(temp);
            temp = temp -> left;
        }
        else
        {
            temp = s.top();
            s.pop();
            cout << temp->data<<' ';
            temp = temp -> right;
        }
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