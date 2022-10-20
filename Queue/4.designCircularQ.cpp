/*
Logic : maintain two indices 
1. qfront -> front of Q, to pop
2. qrear -> rear of Q, to insert

```
EnQueue = insert element at rear position and insert => eg.qrear++;  arr[qrear] = element ;  

step 1: put qrear at right place. 
what is right place?
-> next vacant space where we can insert our element. eg. if next index is vacant ,qrear++

step 2: insert value at qrear.
->e.g if next index is free to insert
```

`DeQueue: pop element from qfront position, in array we can simply increment ,front++; `

**what about cyclic??** -> when qfront or qrear is at last index and we have to increment then we'll put them at 0th index again BUT with some conditions! explained below in code.`

**Primary Logic for this Code :**
1. empty condition : qfront = qrear = -1; 
2. single element in Q when : qrear = qfront. //when we pop last element we'll assign qfront = qrear = -1, coz that's our empty condition.
3. Full condition : when next index of qrear is occupied by qfront, no vacant space! 

*/
class MyCircularQueue {
    int *arr, qfront, qrear, size;
public:
    MyCircularQueue(int k) : arr(new int[k]), size(k), qfront(-1), qrear(-1)  {}
    
    //our goal is to put rear index at right place then insert(arr[rear] = value).  for that we need to first check if we even have space to insert!
    bool enQueue(int value) {
        //case 1: Q is full 
        if (isFull()) return false;

        //case 2: empty Q ( qrear = qfront = -1) then we'll insert at 0th index 
        if (qfront == -1) qfront = qrear = 0;
        
        //to maintain cycle
        //case 3: if rear element is at last, then next right place for rear is at index 0, if it is vacant! i.e qfront != 0.
        else if (qrear == size-1 && qfront != 0)  qrear = 0;
        
       //case 4: Normal case, right place for rear is next vacant index 
        else  qrear++;
        
        //inserting at right place
        arr[qrear] = value;
        return true;
    }
    //our goal to put qfront at right place : for normal case we can simply increment it by one. that's how u pop! in array just increment or decrement pointer.
    bool deQueue() {
		if (isEmpty())  return false;
		
        //if only one element is +nt, after popping -> Q will become empty, and empty condition is (qfront = qrear = -1)
		if (qfront == qrear)  qfront = qrear = -1;          
		
        //maintain cycle next element when qfront = (size-1) is 0th index coz it's cyclic!
        else if (qfront == size-1)  qfront = 0;
		
        //normal case
		else  qfront++;
        return true;
    }
    
    int Front() {return (isEmpty()) ? -1 : arr[qfront];}
    
    int Rear() { return (isEmpty()) ?  -1 : arr[qrear];}
    
    bool isEmpty() {return (qfront == -1);}
    
    bool isFull() { return  ((qfront == 0 && qrear == size-1) || (qrear == qfront-1 ));}
	//Destructor - this will free up heap memory allocated -> arr = new int[size];
	~MyCircularQueue() {delete []arr;}	
};