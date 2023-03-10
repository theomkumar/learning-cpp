#include <bits/stdc++.h> 

class NQueue {
public:
    //free is free index where we can insert elements, next[] contains next free element and after updating free, next[] stores prev element index;
    int *arr, *next, *rear, *front, free;
    // Initialize your data structure.
    NQueue(int n, int s): arr(new int[s]), next(new int[s]), rear(new int[n]), front(new int[n]), free(0){
        for (int i = 0; i < s; i++)
            next[i] = i+1;
        next[s-1] = -1;
        for (int i = 0; i < n; i++)
        {
            rear[i] = -1;
            front[i] = -1;
        }
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.
        if (free == -1)
            return false;
        int i = free;
        free = next[i];
        next[i] = -1;
        //update front as well if first element is inserted
        if (front[m-1] == -1)
            front[m-1] = i;

        else //link prev element-> new;
            next[rear[m-1]] = i;

        rear[m-1] = i;
        arr[i] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
        if (front[m-1] == -1)
            return -1;
        int index = front[m-1];
        front[m-1] = next[index];
        next[index] = free;
        free = index;
        return arr[index];
    }
};
