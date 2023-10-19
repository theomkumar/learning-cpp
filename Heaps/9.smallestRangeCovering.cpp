/*
using heap: (min )
Logic: we will process first element of each array, and find the min,max that will be our initial range, the idea is to find smaller range than this one, it can only happen:
1. if we increase the min or decrease the maximum, but we can't decrease the max if the array is sorted, so we'll go to the next element of the min range array;

*/


//approach 1: using class ,node, compare

class Solution {
public:
    class node {
        public:
        int data, row, col;
        node(int d, int r, int c):data(d),row(r),col(c){}
    };

    struct compare {
        bool operator()(node* &a, node* &b){
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*,vector<node*>, compare> minHeap;
        int mini = INT_MAX, maxi = INT_MIN;
        //maintain max while processing first element of each array
        for (int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i][0]);
            minHeap.push(new node(nums[i][0],i,0));
        }
        mini = minHeap.top()->data;
        int start = mini, end = maxi;
        //process all the remaining element by increasing mini

        while(!minHeap.empty()){
            node* temp = minHeap.top();
            minHeap.pop();
            //assign mini
            mini = temp->data;
            //update range
            if (maxi-mini < end-start){
                start = mini, end = maxi;
            }
            int row = temp->row, col = temp->col;
            //add next element infront of mini if within array
            if (col+1 < nums[row].size()){
                minHeap.push(new node(nums[row][col+1],row, coGl+1));
                maxi = max(maxi, nums[row][col+1]);
            }
            else //one of the array is fully traveresed!!
                break;
        }
        return {start,end};
    }
};

//approach 2: without class...

//without class
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //create a min heap (data, (row,col))
        priority_queue< pair<int,pair<int,int>> , 
                vector<pair<int,pair<int,int>>>,
               greater<pair<int,pair<int,int>>> >minHeap;

        int mini = INT_MAX, maxi = INT_MIN;

        //insert first element into minHeap 
        for(int i = 0; i < nums.size(); i++){
            minHeap.push({nums[i][0], {i,0}});
            maxi = max(maxi, nums[i][0]);
        }
        mini = minHeap.top().first;
        int start = mini, end = maxi;

        //process all elements, by inserting min->next into heap
        while(!minHeap.empty()){
            pair<int,pair<int,int>> top = minHeap.top();
            minHeap.pop();
            //update mini
            mini = top.first;
            //if smaller range found update range
            if (maxi-mini < end-start)
                start = mini, end = maxi;
            
            //if next element of mini present push it
            int row = top.second.first, col = top.second.second;
            if (col+1 < nums[row].size()){
                minHeap.push({nums[row][col+1],{row,col+1}});
                //update maxi after pushing new element
                maxi = max(maxi, nums[row][col+1]);
            }
            else
                break;
        }
        return {start,end};
    }
};