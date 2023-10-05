#include<iostream>
#include<queue>

using namespace std;


int main() 
{
    //max heap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout << "top element : "<<pq.top()<<'\n';
    pq.pop();
    cout << "top element : "<<pq.top()<<'\n';
    
    if (pq.empty())
        cout << "pq is empty()\n";
    else
        cout <<"pq is not empty\n";
    
    //min heap
    cout <<"MIN HEAP \n";
    priority_queue<int,vector<int>,greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(11);
    minHeap.push(8);
    minHeap.push(3);
    minHeap.push(5);

     cout << "top element : "<<minHeap.top()<<'\n';
    minHeap.pop();
    cout << "top element : "<<minHeap.top()<<'\n';
    
    if (minHeap.empty())
        cout << "minHeap is empty()\n";
    else
        cout <<"minHeap is not empty\n";
    return 0;
}