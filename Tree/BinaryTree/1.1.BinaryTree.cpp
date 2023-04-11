#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter the value: \n";
    cin >> data;
    Node* tree = new Node(data);

    if (data == -1)
        return NULL;

    cout << "inserting to the left of "<<data<<'\n';
    tree -> left = buildTree();
    cout << "inserting to the right of "<<data<<'\n';
    tree -> right = buildTree();

    return tree;
}

int main() 
{
    Node* tree = NULL;
    tree = buildTree();
    delete tree;
    return 0;
}