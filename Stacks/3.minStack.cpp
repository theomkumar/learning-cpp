/*
APPROACH 1: TIME O(1) SPACE O(N)
using vector pair <val, minimum val til current element>

class MinStack {
public:
    vector<pair<int, int>> v;
    void push(int val) 
    {
        if (v.empty())  v.push_back({val, val}); 
        else  
            v.push_back({val, min(val, v.back().second)}); //v.back() == v[v.size()-1]
    }
    void pop() { v.pop_back(); }
    int top() { return v.back().first; }
    int getMin() { return v.back().second; }
};

#APPROACH 2: TIME O(1) SPACE O(N)
using 2 stack implementation.

Logic: maintain minimum in mini stack while pushing(push if val <= mini.top()) and popping (pop from mini if val == mini.top() )

class MinStack {
public:
    stack<int> s;
    stack<int> mini;
    
    void push(int val) {
        if (mini.empty() || val <= mini.top())
            mini.push(val);
        s.push(val);    
    }
    
    void pop() {
        if (s.top() == mini.top())
            mini.pop();
        s.pop();
    }
    
    int top() { return s.top(); }
    int getMin() { return mini.top(); }
};
#Approach 3: OPTIMAL: TIME O(1) SPACE O(1) //no extra space except the stack itself
*/

class MinStack {
public:
    stack<int> s;
    int mini = INT_MAX;
    
    void push(int val) {
        if (val <= mini) //we'll push previous min value into the stack before pushing new min val, coz when we'll pop eg. min element then we need to update mini with prev min value   
        {
            s.push(mini); //we'll use it to update mini when popping min element!
            mini = val; //update mini with min val
        }
        s.push(val);
    }
    
    void pop() {
        if (s.top() == mini) //this means mini got updated here, and we know that we have stored previous min value in stack before pushing new minimum!
        {
            s.pop(); //popping curr min value 
            mini = s.top(); //this is our previous min value, we'll update mini, and now we'll pop it as well!
        }
        s.pop();
    }
    
    int top() {return s.top(); }
    
    int getMin() { return mini; }
};

//Code Studio //this will get oveflow in leetcode coz we are multiplying by 2, 

class SpecialStack {
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
    stack<int> s;
    int mini = INT_MAX;
    void push(int data) {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data > mini)
                s.push(data);
            else// data < mini
            {
                s.push (2 * data - mini);
                mini = data;
            }
        }
    }

    int pop() {
        if (s.empty())
            return -1;
        int curr = s.top();
        s.pop();

        if (curr > mini)
            return curr;
        else
        {
            int prevMin = mini;//we are supposed to pop this element only!
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if (s.empty())
            return -1;
        int curr = s.top(); 
        if (curr > mini)
            return curr;
        else
            return mini;
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if (s.empty())
            return -1;
        return mini;
    }  
};