//https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0
#include<iostream>
#include<stack>
using namespace std;


//Approach one TC O(n) SC 

void deleteMiddle(stack<int>&s, int count, int n){
    //base case
    if (count == n/2)
    {
        s.pop();
        return;
    }
    int curr = s.top();
    s.pop();
    //recursive call
    deleteMiddle(s, ++count, n);
    s.push(curr);

}
//Approach two TC O(n) SC O(n) my intuition 

void deleteMiddle1(stack<int>&s, int N){
    stack<int> temp;
    int cnt = 0;
    N =  (N+1)/2;//N+1 == size of stack
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty())
    {
        if (cnt != N)
        {
            s.push(temp.top());
        }
        cnt++;
        temp.pop();
    }
}  

int main() 
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5); 
    // s.push(7); 
    // s.push(7); 
    int size = s.size() - 1; //why? in question it's given!
    deleteMiddle(s, size);



    
    return 0;
}