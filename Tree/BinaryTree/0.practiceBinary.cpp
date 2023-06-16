#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node
{
    public:
    int data;
    node *left, *right;

    node(int d) : data(d),left(NULL),right(NULL) {}
};

node* buildTree()
{
    int data;
    cout <<"Enter data: ";
    cin >> data;
    cout <<'\n';

    if (data == -1) return NULL;
    node *root = new node(data);

    cout << "enter data to the left of "<< root -> data<<' ';
    root -> left = buildTree();
  
    cout <<"enter data to the right of "<< root -> data<<' ';
    root -> right = buildTree();

    return root;
}

void levelOrderStepWise(node* &root)
{
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        //null condition
        if (temp == NULL)
        {
            cout <<'\n';
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else 
        {
            //print data:
            cout << temp -> data <<' ';
            
            //insert left & right
            if (temp -> left)
                q.push(temp -> left);
            if (temp -> right)
                q.push(temp -> right);
        }
    }
}


void levelOrderTraversal(node* &root)
{
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop(); 
        cout << temp -> data <<' ';
        if (temp -> left) q.push(temp -> left);
        if (temp -> right) q.push(temp -> right);
    }
    cout <<'\n';
}

void reverseLevelOrderTraversal(node* &root)
{
    if (root == NULL)
        return;
    queue<node*> q;
    stack<int> s;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop(); 
        s.push(temp->data);
        if (temp -> left) q.push(temp -> left);
        if (temp -> right) q.push(temp -> right);
    }
    while (!s.empty())
    {
        cout << s.top()<<' ';
        s.pop();
    }
    cout <<'\n';
}

void reverseStepLevelTraversal(node *root)
{
    if (root == NULL)
        return;
    stack<int> st;
    queue<node*> q;

    q.push(root);

    //create a separater indicating the level is complete
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            st.push(0);
            q.pop();
            //if there are some child nodes
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            st.push(q.front()->data);
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }

            q.pop();
        }
    }
    while (!st.empty())
    {
        if (st.top() == 0)
            cout <<'\n';
        else
            cout <<st.top()<<' ';
        st.pop();
    }
    cout <<'\n';
}
//LNR
void inorder(node* &root)
{
    if (root == NULL)
        return;
    inorder(root -> left);
    cout << root -> data <<' ';
    inorder(root -> right);
}
//iterative: inorder 

//build from level order 
node* buildLevelOrder(node* root)
{
    int data;
    cout << "enter root data\n";
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
        cout <<"enter data to the left of "<<temp->data<<'\n';
        cin >> data;
        if (data != -1)
        {
            temp -> left = new node(data);
            q.push(temp -> left);
        }
        cout <<"enter data to the right of "<<temp->data<<'\n';
        cin >> data;
        if (data != -1)
        {
            temp -> right = new node(data);
            q.push(temp -> right);
        }
    }
    return root;
}
int main()
{
    
    node* root = NULL;
    /*  //i/p: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree();

    levelOrderTraversal(root);
    levelOrderStepWise(root);
    reverseLevelOrderTraversal(root);
    reverseStepLevelTraversal(root);
    cout <<"Inorder: \n";
    inorder(root);
    */
    root = buildLevelOrder(root);
    levelOrderStepWise(root);
}