//Logic use top1(left to right order of insertion) to maintain top 
//top2 (right to left) to maintain top
//we are optimally utilisng space here, as for eg. if array size is 10, and stack one needs more space at a time say 7 and stack two is using 3 spaces, if we divide 10/2-> 5, 5 space for each , 
//then stack one will miss out on 2 space while stack two will have 2 wasted, thus it's better to let either stack occupy as much as space is +nt; 
//TC -> O(1)
class TwoStack {
    int *arr;
    int top1, top2, size;   
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if ((top2 - top1) > 1)//atleast one space available for push.
        {
            arr[++top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if ((top2 - top1) > 1)
        {
            arr[--top2] = num;
        }
    }        


    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0)
            return arr[top1--];
        else
            return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size)
            return arr[top2++];
        else
            return -1;
    }
};
