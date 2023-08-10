//LOGIC: keep pushing left element into q, as it's of diff diagonal, while continue moving to right until NULL.

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (!root) return ans;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
    
        while (curr)
        {
            ans.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            curr = curr->right;
        }
        
    }
    return ans;
}