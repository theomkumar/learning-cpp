// <= 2 child
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node
{
    public:
    int data;
    node *left, *right;

    node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "enter data: ";
    cin >> data;
    root = new node(data);

    //to stop basically(no child)
    if (data == -1)
        return NULL;
    cout <<"enter data to insert in left of "<<data<<endl;
    root -> left = (buildTree(root->left));
    cout <<"Enter data for inserting in right of "<<data<<endl;
    root -> right = (buildTree(root->right));
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
        node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << '\n';
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp -> data << ' ';
            if (temp -> left)
                q.push(temp->left);

            if (temp -> right)
                q.push(temp-> right);
        }
    }
}
//incomplete
void reverseOrderLevelTraversal(node *root)
{
    stack<node*> q;

    //create a separater indicating the level is complete
    q.push(NULL);
    q.push(root);


    while (!q.empty())
    {
        node* temp = q.top();
        q.pop();

        if (temp == NULL)
        {
            cout << '\n';
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp -> data << ' ';
            if (temp -> left)
                q.push(temp->left);

            if (temp -> right)
                q.push(temp-> right);
        }
    }

}

int main() 
{
    node* root = NULL;
    //creating a Tree
    root = buildTree(root);

    // i/p: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //levelOrderTraversal
    cout <<"\n Printing the level order Traversal Output:  \n";
    levelOrderTraversal(root);

    cout <<"\n Printing the reverse level order Traversal output: \n";
    reverseOrderLevelTraversal(root); 
    return 0;
}