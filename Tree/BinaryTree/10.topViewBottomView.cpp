//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution
{
    public:
    // for bottom view we can just comment check before inserting into the map.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
        //queue<Node, <horizontal distance>
        queue<pair<Node*,int>> q;
        // <horizontal distance, val>
        map<int,int> m;

        int x = 0;
        q.push({root,x});

        while (!q.empty())
        {
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* curr = temp.first;
            x = temp.second;
            if(m.find(x) == m.end())
                m[x] = curr->data;
            
            if(curr -> left)
                q.push({curr->left, x-1});
            if(curr -> right)
                q.push({curr->right, x+1});
        }
        for (auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends