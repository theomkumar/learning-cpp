#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> nums) {
    for (int i = 0; i<nums.size(); i++) {
        cout<<nums[i]<<" ";
    }cout<<"\n";
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n);
    
    for (int i = 0; i<n; i++) {
        temp[(i+k) % n] = nums[i];
    }
    for(int i = 0; i<n; i++) {
        nums[i] = temp[i];
    }
    
}

int main() {
    vector<int> nums= {1,2,3,4};
    int k = 2;
    rotate(nums,k);
    print(nums);
}

