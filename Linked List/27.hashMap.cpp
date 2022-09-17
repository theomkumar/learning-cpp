/*
Approach 1:

class MyHashMap {
public:
    vector<int> data;
    int size = 1e6 + 1; //constraint was 10^6
    
    MyHashMap() {
        data.resize(size);
        fill(data.begin(), data.end(), -1); 
    }
    
    void put(int key, int value) {
        data[key] = value; 
    }
    
    int get(int key) {
        return data[key]; 
    }
    
    void remove(int key) {
        data[key] = -1; 
    }
};

Approach 2:

class MyHashMap {
public:
    vector<list<pair<int, int>>> data;
    int size = 100; 
    
    MyHashMap() {
        data.resize(size);
    }
    
    int hash(int key)
    {
        return key % size;
    }
    //return iterator to the element if +nt else return last iterator.
    list<pair<int, int>> :: iterator search (int key) 
    {
        int i = hash(key); 
        //iterator to traverse list 
        list<pair<int,int>> :: iterator it = data[i].begin();
        while (it != data[i].end())
        {
            if (it -> first == key)
                return it;
            it++;
        }
        return it;
    }
    void put(int key, int value) {
        int i = hash(key);
        //if key is +nt 
        if (search(key) != data[i].end()) //or we can just remove(key) then push key,val pair
            search(key) -> second = value;
        
        else//not present
            data[i].push_back({key, value}); 
    }
    
    int get(int key) {
        int i = hash(key);
        if (search(key) == data[i].end()) return -1;
        return search(key) -> second; 
    }
    
    void remove(int key) {
        int i = hash(key);
        if (search(key) != data[i].end())
            data[i].erase(search(key));
    }
};
*/