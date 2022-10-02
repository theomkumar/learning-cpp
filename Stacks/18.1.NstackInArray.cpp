using namespace std;
/*watch youtube! and dry run ...

Logic : 
top[] size = no. of stacks, and it contains  index of top element of respective stack. e.g top element of 2nd stack will be kept in [2-1]th stack.
if ith stack is empty then top[i] = -1;
we initialise top[] with -1 as all stacks are empty during initialisation.

freespot : denotes index of arr which is free, so we can push element there, and we need to update freespot to next available free spot!
we initialise freespot to 0 and if we are pushing an element then we'll update freespot to next free spot and that'll be 1 that's why we initialise next[] with 1!  //next[0] = 1 

Next: stores next free spot, eg. for i = 0, next free spot is 1 , next[0] = 1;
//it's primary goal is to update freespot variable with next free index, after that we can store previous element in it why ? coz when we pop then we will have to update top of stack with previous element, and we can easily access it this way!.

next : 2 functions
1. it'll contain next free spot
2. after assigning freespot ,it contains prev element index (it is actually current top element , after we push 'x' it'll become prev!)
*/


#include <bits/stdc++.h> 
class NStack
{
    int *arr, *top, *next, freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        //top initialise
        for (int i = 0; i < N; i++)
            top[i] = -1;

        //next 
        for (int i = 0; i < S; i++)
            next[i] = i + 1;

        next[S-1] = -1;
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if (freespot == -1) return false;
        //freespot space index
        int i = freespot;
        //update freespot to next freespot space
        freespot = next[i];//freespot = next[freespot]
     
        //update next[i] to the current top element
        next[i] = top[m-1];
        //update top
        top[m-1] = i;
        
         //push element 
        arr[i] = x;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for underflow
        if (top[m-1] == -1)
            return -1;

        int i = top[m-1];
        top[m-1] = next[i]; //coz next[i] contains prev element as well if it's not empty
        /*
        we have two free spots 1.the variable free spot 2nd is i, coz it's popped. i need to become free spot.

        if we make freespot = i directly then how 
        */
        next[i] = freespot; 
        freespot = i;

        return arr[i];
    }
};