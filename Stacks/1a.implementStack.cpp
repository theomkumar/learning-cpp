//LIFO -> Last in First order
#include<iostream>

using namespace std;

//approach 1: stack implementation using array
class Stack
{
    //properties
    int *arr;   
    int size;
    int top; 

    public:
    //constructor
    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (top < size-1)
            arr[++top] = element;
        else
            cout <<"Stack Overflow! \n";
    }
    void pop ()
    {
        if (top >= 0)
            top--;
        else
        {
            cout << "Stack Underflow! \n";
        }
        
    }
    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }

        else 
        {
            cout <<"Stack is Empty: ";
            return -1;
        }
    }
    bool isEmpty()
    {
        return top == -1 ? 1 : 0; 
    }
    
};
int main() 
{
    Stack st(4);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(50);

    cout <<st.peek()<<endl;
    st.pop();
    st.pop();
    cout <<st.peek()<<endl;
    st.pop();
    st.pop();
    cout <<st.peek()<<endl;
    st.push(99);

    if (st.isEmpty())
    {
        cout << "Stack is emptyy!!";
    }
    else 
        cout << "Stack is not empty!!";
    /*
    //create stack using stl
    stack<int> s; 

    //push element
    s.push(5);
    s.push(6);
    //pop 
    s.pop();

    cout <<"Top element: " << s.top();

    // is empty?  
    cout <<"\nempty: " << s.empty();

    //size of stack
    cout <<"\nsize of stack: " << s.size();
    */
    return 0;
}