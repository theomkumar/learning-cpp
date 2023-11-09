#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    TrieNode* child[26];
    bool isTerminal;
    int childCount;

    TrieNode(){
        for(int i = 0; i < 26; i++) child[i] = NULL;
        isTerminal = false;
        childCount = 0;
    }
};
class Trie {
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }
    ~Trie(){
        deleteTrieNode(root);
    }
    void deleteTrieNode(TrieNode* root){
        for(int i = 0; i < 26; i++){
            if (root->child[i])
                deleteTrieNode(root->child[i]);
        }
        delete root;
    }

    void insert(string &word){
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i]-'a';
            if (curr->child[idx] == NULL){
                curr->child[idx] = new TrieNode();
                curr->childCount++; ///only this modification!!!!!
            }
            curr = curr->child[idx]; 
        }
        curr->isTerminal = true;
    }
    void findLongestPrefix(string &s, string &ans){
        TrieNode* curr = root;
        for(int i = 0; i < s.size(); i++){
            if (curr->childCount > 1|| (curr->isTerminal)){
                return;
            }
            ans += s[i];
            curr = curr->child[s[i]-'a'];
        }
    }
};
string longestCommonPrefix(vector<string>& s,int n) {
    Trie *t = new Trie();
    //pass all words in trie
    for(int i = 0; i < s.size(); i++){
        t->insert(s[i]);
    }
    string ans = "";
    //if any node has more than one child or if any word terminates first we'll stop
    t->findLongestPrefix(s[0],ans);
    delete t;
    return ans;
} 
int main(){
    vector<string> s = {"long,longer,longest, longi,lonely"};
    string ans = longestCommonPrefix(s,s.size());
    cout << ans;
    return 0;
}