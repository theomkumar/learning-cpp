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

            //mark next as -1 as job of next is (1)to assign free to next freeSpot & (2)link prev element to next element of the q.
            //if we don't mark it -1 then if we continue dequeue element and reach this element, then next[idx] will give index to some other index(i.e arr[next[idx]]) to dequeue but arr[next[idx]] could be vacant...so it'll continue dequeuing until the end of array,therefore -1 acts as a full stop, marking end of q.

            //link ->
            // eg: q1 : 4,5,6,7 -> in this q next[0] will be linked to next element i.e 1, and we want to dequeue all elements, first 4 will be dqueued, but it's linked to 5, so front[] will point to element 5, similarly 5-> 6, 6-> 7, but imagine if we did't mark next[] of 7 element as -1 then, this dqueuing would keep carrying on to whatever nex[] was pointing to!.

            next[idx] = -1; //acts as end of current Q

            //check if Q is empty
            if (front[qn-1] == -1)//0-indexed array
            {
                next[idx] = -1; 
                front[qn-1] = idx;
            }
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
    KQueue q(7, 3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    q.dequeue(1);
    q.dequeue(2);
    q.dequeue(1);
    q.dequeue(1);

    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(1);

}

