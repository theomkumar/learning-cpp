using namespace std;
//APPROACH 1: USING ARRAY  // LEETCODE + CODESTUDIO SAME QN

/*
Logic : 

Full condition : when front is at first and rear at last or when front is one ahead of rear(how? coz it's cyclic if eg.  (f)3 3 3(r) pop one time  _ f(3) 3(r) now we push 3 again at rear _3(r) (f)3 3)

EMPTY CONDITION : front = rear = -1;
if empty() then we need to initialise front = rear = 0, then we can push.

ONE ELEMENT CONDITION : when front == rear, if one element is present and we have to pop ,then our Q will be empty,so we need to make front = rear = -1
same with popping 

MAINTAIN CYCLE CONDITION:
if our front is at last index and we need to pop, so we need to increment front but it's at last index, so we'll make it 0, coz it's cyclic 

if our front is at first index and we need to push, then we normally decrement front and insert, we'll make our front = n-1, coz cyclic 

same with rear element.
*/
class MyCircularDeque {
    int size, front, rear, *arr;
public:
    MyCircularDeque(int k) : size(k), front(-1), rear(-1), arr(new int[k]) {  } 
   
    //put front at right place then insert
    bool insertFront(int value) {
        if (isFull())  return false;
        if (isEmpty()) front = rear = 0;
        else if (front == 0) front = size -1;
        else front--;
        arr[front] = value;
        return true;
    }
    //put rear at right place then insert
    bool insertLast(int value) {
        if (isFull())  return false;
        if (isEmpty()) front = rear = 0;
        else if (rear == size-1)  rear = 0;
        else rear++;
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())  return false;
        if (front == rear) front = rear = -1;
        else if (front == size-1) front = 0;
        else front++;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())  return false;
        if (rear == front) front = rear = -1;
        else if (rear == 0) rear = size-1; 
        else rear--;
        return true;
    }
    
    int getFront() { return isEmpty() ? -1 : arr[front]; }
    
    int getRear() { return isEmpty() ? -1 : arr[rear]; }
    
    bool isEmpty() { return (front == -1); }
    
    bool isFull() { return ((front == 0 && rear == size-1) || (rear == front-1)); }
};

//CODE STUDIO

#include <bits/stdc++.h> 
class Deque
{
public:
    int *arr, size,front, rear;
    Deque(int n) : arr(new int[n]),size(n),front(-1),rear(-1) {}

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check full condition
        if (isFull()) return false;
        if (isEmpty()) front = rear = 0;
        else if (front == 0) front = size - 1;
        else  front--;
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull())  return false;
        if (isEmpty())  front = rear = 0;
        else if (rear == size-1)  rear = 0;
        else rear++;
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty()) return -1;
        int ans = arr[front];
        if (front == rear) front = rear = -1;
        else if (front == size-1) front = 0;
        else front++;
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty())  return -1;
        int ans = arr[rear];
        if (front == rear) rear = front = -1;
        else if (rear == 0) rear = size-1;
        else rear--;
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront() {  return (isEmpty()) ? -1 : arr[front]; }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear() { return (isEmpty()) ? -1 : arr[rear]; }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() { return (front == -1); }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull() { 
        return ((front == 0 && rear == size-1) || (rear == front-1));
     }
     //optional frees up heap memory
     ~Deque()
     {
        delete []arr;
     }
};
int main()
{
    Deque deque(12);
}