
/*
Circular:
 -increment =>  tail = ++tail % size;
 -decrement =>  head = (--head + size) % size;

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
    
    //optional fix memory leak in the code
    ~MyCircularDeque ()
    {
        delete []arr;
    }
};
*/
class MyCircularDeque {
public:
    int *arr, size, head, tail;
    MyCircularDeque(int k) : arr(new int[k]),size(k),head(-1),tail(-1) {}

    bool insertFront(int value) {
        if (isFull())   return false;
        if (isEmpty())
            head = tail = 0;
        else //decrement head-- in cyclic array
            head = (--head+size) % size;
        arr[head] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())   return false;
        if (isEmpty())
            head = tail = 0;
        /*else if (tail == size-1)
            tail = 0;
        else
            tail++;*/
        else
            tail = ++tail % size;
        arr[tail] = value;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        if (head == tail)
            head = tail = -1;
        else 
            head = ++head % size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        else if (head == tail)
            head = tail = -1;
        else
            tail = (--tail + size) % size;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : arr[head];
    }
    
    int getRear() {
        return isEmpty() ? -1 : arr[tail];
    }
    
    bool isEmpty() {
        return (head == -1);
    }
    
    bool isFull() {
        return ((tail + 1) % size == head);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */