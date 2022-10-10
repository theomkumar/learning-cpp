class Solution {
//Logic: all local inversions are global inversions but reverse is not true, note nums is a permutation of all the numbers in the range [0, n - 1]
//if distance between a number and index is more than 1 then it'll be +1 local inversion but more than +1 global inversion.
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            if (abs(i - nums[i]) > 1) return false;
        
        return true;
    }
};
/*
using merge sort
bruteforce method:
step 1 : count local inversion.
step 2 : global inversion == count inversion

class Solution {
public:
    typedef long long ll;
    ll global = 0;
        void merge(vector<int>& v, int l, int r)
    {
        int mid = l + (r-l)/2;
        int n1 = mid - l + 1;
        int n2 = r - mid;
        
        int a[n1]; int b[n2];
        
        //copying values in new array
        int j = l;
        for (int i = 0; i < n1; i++)
            a[i] = v[j++];
        
        j = mid + 1;
        for (int i = 0; i < n2; i++)
            b[i] = v[j++];
        
        //merge both sorted array 
        j = l;
        int i1 = 0, i2 = 0;
        
        while (i1 < n1 && i2 < n2)
        {
            if (a[i1] < b[i2])
                v[j++] = a[i1++];
            else
            {
                global += n1 - i1;
                v[j++] = b[i2++];
            }
        }
        
        while (i1 < n1)
            v[j++] = a[i1++];
        while (i2 < n2)
            v[j++] = b[i2++];
    }
    void mergeSort(vector<int>& v, int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r-l)/2;
            
            //sort left part
            mergeSort(v, l, mid);
            
            //sort right part
            mergeSort(v, mid+1, r);
            
            //merge right and left
            merge(v, l, r);
        }
    }
    bool isIdealPermutation(vector<int>& nums) {
        global = 0;
        ll local = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] > nums[i])
                local++;
        }
        mergeSort(nums, 0, nums.size() - 1);
        cout <<"global: "<<global<<" local: "<<local;
        return (local == global);
    }
};

*/