#include<iostream>
using namespace std;

void merge(int nums1[],int n,int nums2[], int m, int nums3[]) {
    int i =0, j=0;
    int t =0;
    while(i<n && j<m) {
        if (nums1[i]>nums2[j]) {
            nums3[t++]=nums2[j++];
        }
        else nums3[t++]=nums1[i++];
    }
    while (i<n) {
        nums3[t++]=nums1[i++];
    }
    while (j<m) {
        nums3[t++] = nums2[j++];
    }
}

void print (int nums[],int n) {
    for (int i = 0; i<n; i++) {
        cout<<nums[i]<<" ";
    }
}

int main() {
    int nums1[5] = {1,4,5,7,9};
    int nums2[6] = {2,3,6,8,10,11};
    int nums3[11];
    merge(nums1,5,nums2,6,nums3);
    print(nums3,11);
}
