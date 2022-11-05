#include<iostream>
using namespace std;

class KQueue
{
    int *arr, *front, *rear, *next, free;

    public:
    KQueue(int n, int k)
    {
        arr = new int[n];
        next = new int[n];
        for (int i = 0; i < n; i++) next[i] = 1+i;
        next[n-1] = -1;

        front = new int[k];
        rear = new int[k]; 

        for (int i = 0; i < k; i++) 
        {
            rear[i] = -1;
            front[i] = -1;
        }
        free = 0;
    }

        void enqueue(int data, int qn)
        {
            //overflow
            if (free == -1)
            {
                cout <<"queue is full! \n";
                return;
            }
            //find free spot index
            int idx = free; 
            //update freespot to next free index
            free = next[idx];


            //ig this step is optional, dry run to verify!
            //mark next as -1 //job of next is to update free to next freespot and after this is done, we can mark next[idx] as -1, as it's not free anymore!
            next[idx] = -1; 
            //check if Q is empty
            if (front[qn-1] == -1)//0-indexed array
                front[qn-1] = idx;

            else//linking next of curr rear to new element(data)
                next[rear[qn-1]] = idx;

            //update rear
            rear[qn-1] = idx;
            //push element
            arr[idx] = data;
        }

        void dequeue(int qn )
        {
            //check underflow
            if (front[qn-1] == -1)
            {
                cout <<"queue is empty! \n";
                return;
            }
            //index to pop
            int idx = front[qn-1];

            //update front to next element of Q
            front[qn-1] = next[idx];

            //update free spot
            next[idx] = free;
            free = idx;

            cout <<"arr[idx] "<<arr[idx]<<'\n';
        }

};
int main()
{
    KQueue q(10, 3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    q.dequeue(1);
    q.dequeue(2);
    q.dequeue(1);
    q.dequeue(1);

}



#include <bits/stdc++.h> 
class NQueue{
    int *arr, *rear, *front, *next,  
public:
    // Initialize your data structure.
    NQueue(int n, int s){
        
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
    }
};