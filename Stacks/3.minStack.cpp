// ##APPROACH 1 : using vector pair to store min element and value;

// 1.a : TC O(1) SC O(n) clean
/*
class MinStack {
public:
    vector<pair<int, int>> v;
    
    MinStack() {}
    
    void push(int val) {
        if (v.empty())
        {
            v.push_back({val, val});
        }
        else
            v.push_back({val, min(val, v[v.size()-1].second)});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size() - 1].first;
    }
    
    int getMin() {
        return v[v.size() - 1].second;
    }
};
//Approach 1.b not so clean! easy to understand

class MinStack {
public:
    vector<pair<int, int>> v;
    //min
    int mini = INT_MAX;
    
    MinStack() {}
    
    void push(int val) {
        mini = min(val, mini);
        v.push_back({val, mini});
    }
    
    void pop() {
        //if size is 0 then we'll return without pop

        if (v.size() == 0) return;
        //pop 
        v.pop_back();

        //after pop if size is 1 or more then we'll update mini with previous mini value;
        if (v.size() >= 1)
        {
            mini = v[v.size() -1].second;
        }
        else //if after popping size becomes 0, then we'll reset mini;
            mini = INT_MAX; 
        
    }
    
    int top() {
        return v[v.size() - 1].first;
    }
    
    int getMin() {
        return v[v.size() - 1].second;
    }
};
*/