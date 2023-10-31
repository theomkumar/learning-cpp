#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public: 
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode () {
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode *root;
    
    Trie(){
        root = new TrieNode();
    }

    ~Trie(){
        deleteTrie(root);
    }

    void deleteTrie(TrieNode* node) {
        for(int i = 0; i < 26; i++)
            if(node->children[i])
                deleteTrie(node->children[i]);
        delete node;
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) 
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];                
        }
        curr->isEndOfWord = true;
    }

    void printSuggestions(TrieNode*curr,vector<string>&temp,string prefix){
        if (curr->isEndOfWord){
            temp.push_back(prefix);
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            TrieNode* next = curr->children[ch-'a'];
            if (next != NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str){
        TrieNode* prev = root;
        vector<vector<string> >output;

        string prefix = "";
        for(int i = 0; i < str.size(); i++){
            char lastChar = str[i];
            prefix.push_back(lastChar);
            TrieNode* curr = prev->children[lastChar-'a'];
            if (curr == NULL) break;
            vector<string> temp;
            printSuggestions(curr,temp,prefix);
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t = new Trie();
    for(int i = 0; i < contactList.size(); i++){
        t->insert(contactList[i]);
    }
    vector<vector<string>> result = t->getSuggestion(queryStr);
    delete t;
    return result;
}

int main() {
    vector<string> contactList = {"alice", "ab", "carol", "dave"};
    string queryStr = "a";
    vector<vector<string>> suggestions = phoneDirectory(contactList, queryStr);

    for(int i = 0; i < suggestions.size(); i++) {
        cout << "Suggestions after character " << i+1 << " are: ";
        for(int j = 0; j < suggestions[i].size(); j++) {
            cout << suggestions[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}