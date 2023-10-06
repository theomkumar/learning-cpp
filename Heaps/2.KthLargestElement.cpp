//same logic will apply to kth smallest element, we'll use max heap for that.
//https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1068418629/
class Solution {
public:
    //time complexity is O(n log k) and the space complexity is O(k)
    int findKthLargest(vector<int>& nums, int k) {
        int i = 0;
        priority_queue<int,vector<int>,greater<int>> pq;

    //step 1: push first k element into min heap
        while(i < k)
            pq.push(nums[i++]);
    //step 2: iterate rest, if element is greater than heap top, then pop heap top, and insert it.

        while(i < nums.size()){
            if (nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
    //step 3: heap top is kth largest element
        return pq.top();
    }
};