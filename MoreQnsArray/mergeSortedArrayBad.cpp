#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//not efficient 

//popping back extra zeroes 
void popback(vector<int> &nums, int n) {
    int temp = nums.size()-n;
    for ( int i = 0; i<temp; i++) {
        nums.pop_back();
    }
}

void print(vector<int> nums,int n) {
    for (int i = 0; i < n; i++) {
        cout<<nums[i]<<" ";
    }cout<<'\n';
}
int main() {
    vector<int> nums1= {1,2,3,0,0,0};
    int m = 3;
    cout<<"size before pop"<<nums1.size()<<'\n';
    popback(nums1,m);
    print(nums1,m);

    vector<int> nums2 = {2,5,6};
    int n = 3;
    popback(nums2,n);
    print(nums2,n);

    nums1.insert(nums1.end(),nums2.begin(),nums2.end());
    print(nums1,m+n);

 
    sort(nums1.begin(),nums1.end());
    print (nums1,nums1.size());
}

/* void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
/*