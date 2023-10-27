//my implementation , then improved versions!!
/*
//NOTE: WE DON'T NEED TO INSERT WORD TO TRIE!!! if it's not null it equals to word!!!

//DELETE : removal of word === make isTerminal or isEndOfWord as false! that's it!

//space optimised deletion??
//self naive implementation 
class Trie {
public:
    char data; //not needed
    Trie*children[26];
    bool isTerminal;
    
    Trie() {
        for(int i = 0; i < 26; i++) children[i] = NULL;
        isTerminal = false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(int i = 0; i < word.size(); i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) {
                Trie* temp = new Trie();
                temp->data = word[i];
                curr->children[idx] = temp;
                curr = temp;
            }
            else 
                curr = curr->children[idx];                
        }
        curr->isTerminal = true;//marking at end of the word, as insert!
    }
    
    //note search & startsWith are exact same code, except return part.
    bool search(string word) {
        Trie* curr = this;
        for(int i = 0; i < word.size() ;i++){
            int idx = word[i]-'a';
            if (curr->children[idx] == NULL)
                return false;
            else
                curr = curr->children[idx];
        }

        return curr->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(int i = 0; i < word.size() ;i++){
            int idx = word[i]-'a';
            if (curr->children[idx] == NULL)
                return false;
            else
                curr = curr->children[idx];
        }
        return true;
    }
};

#2: improved , concise but is not modular, using this to get root node.

class Trie {
public:
    Trie *children[26];
    bool isEndOfWord;
    
    Trie() {
        for(int i = 0; i < 26; i++) children[i] = NULL;
        isEndOfWord = false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(int i = 0; i < word.size(); i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) 
                curr->children[idx] = new Trie();
            curr = curr->children[idx];                
        }
        curr->isEndOfWord = true;//marking at end of the word, as insert!
    }
    
    bool search(string word, bool isPrefix = false) {
        Trie* curr = this;
        for(int i = 0; i < word.size() ;i++){
            int idx = word[i]-'a';
            if (curr->children[idx] == NULL)
                return false;
            curr = curr->children[idx];
        }
        return isPrefix ? true : (curr->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

//3: Best Approach with good practice, Modular version!! using separate TrieNode class
};
*/
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

    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) 
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];                
        }
        curr->isEndOfWord = true;//marking at end of the word, as insert!
    }
    
    bool search(string word, bool isPrefix = false) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size() ;i++){
            int idx = word[i]-'a';
            if (curr->children[idx] == NULL)
                return false;
            curr = curr->children[idx];
        }
        return isPrefix ? true : (curr->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};
//part 2 babbar implementation using recursion