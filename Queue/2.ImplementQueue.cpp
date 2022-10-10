/*
Approach 1: Queue Implementation Using an array
class MyQueue {
public:
    int arr[100];
    int front = 0;  //front of queue
    int rear = 0;   //back of queue insertion will happen here;
                    //rear - front == size of queue  
    void push(int x) {
        arr[rear] = x;
        rear++;
    }
    int pop() {
        int ans = arr[front];
        front++;
        
        //this isn't necessary, but it'll prevent wastage of space. how? imagine if we push 5 times, then rear = 5, and if we pop 5 times then our front will be at 5, front == rear, this means our queue is empty, and now when we push new elements, it'll be inserted from the rear index i.e 5, thus we are not utilising previous 5 empty space!.
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        return ans;
    }
    
    int peek() {
        return arr[front];
    }
    
    bool empty() {
        return (front == rear);
    }
};
2. Queue Implementation Using Vector
class MyQueue {
public:
    vector<int> v;
    
    MyQueue() {
    }
    
    void push(int x) {
        v.push_back(x);
    }
    int pop() {
        int ans = v[0];
        v.erase(v.begin());
        return ans;
    }
    
    int peek() {
        return v[0];
    }
    
    bool empty() {
        return v.empty();
    }
};
3.Queue Implementation Using Stack!!
*/
class MyQueue {
public:
    stack<int> st;
    void push(int x) {
        push_bottom(x);
    }
    
    void push_bottom(int x)
    {
        if (st.empty())
            return st.push(x);
        int top = st.top();
        st.pop();
        push_bottom(x);
        st.push(top);
    }
    
    int pop() {
        int top = st.top();
        st.pop();
        return top;
    }
    
    int peek() { return st.top(); }
    
    bool empty() { return st.empty(); }
};
