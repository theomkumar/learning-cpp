/*
Approach 1: 

class MyHashSet {
public:
    vector<bool> m;
    
    MyHashSet() {
        m.resize(1e6+1);
    }
    
    void add(int key) {
        m[key] = 1;
    }
    
    void remove(int key) {
        m[key] = 0;
    }
    
    bool contains(int key) {
        return m[key];
    }
};

Approach 2:

class MyHashSet {
public:
    vector<list<int>> m;
    int size;
    
    MyHashSet() {
        size = 100;
        m.resize(size);
    }
    //very simple hash function
    int hash (int key)
    {
        return key % size;
    }
    
    void add(int key) {
        if (contains(key)) return;
        int i = hash(key);
        m[i].push_back(key);
            
    }
    //search if key is present or not, and return the iterator, so can do both delete as well as find from it.
    list<int> :: iterator search(int key)
    {
        int i = hash(key);
        //stl function to find key, if not found it'll return end()
        return find (m[i].begin(), m[i].end(), key);
    }
    void remove(int key) {
        if (contains(key) == 0) return;
        int i = hash(key);
        m[i].erase( search(key));
    }
    
    bool contains(int key) {
        int i = hash(key);
        if (search(key) != m[i].end()) return true;
        return false;
    }
};
*/