#include<iostream>
using namespace std;
//https://leetcode.com/problems/merge-sorted-array/
//read question!
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = n-1;
    int s = nums1.size()-1;
    while(j>=0 && i>=0) {
        if(nums1[i]>=nums2[j]) 
            nums1[s--]=nums1[i--];
        else nums1[s--]=nums2[j--];
    }
    while (j>=0) {
        nums1[s--] = nums2[j--];
    }
}