#APPROACH 1: using simple array

class CustomStack {
public:
    int *arr;
    int size;
    int top;
    CustomStack(int maxSize) {
        size = maxSize;
        arr = new int[size];
        top = -1;
    }
    
    void push(int x) {
        if (top < size - 1)//size - top > 1;
            arr[++top] = x;
    }
    
    int pop() {
        if (top >= 0)
        {
            int temp = arr[top];
            top--;
            return temp;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if (top == -1)
            return;
        if (top < k)
            arr[top] += val;
        
        top--;
        increment(k, val);
        top++;
    }
};

#APPROACH 2 using vector