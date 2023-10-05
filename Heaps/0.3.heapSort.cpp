//HEAP SORT
//step 1: create a max heap
//step 2: heap sort logic (i.e swap first index element to last,decrease size, then heapify it, )
class Solution {
public:
    void heapify(vector<int>& nums, int n, int i)
    {
        int largest = i;
        int l = 2*i+1, r = 2*i+2;

        if(l < n && nums[largest] < nums[l])
            largest = l;
        if(r < n && nums[largest] < nums[r])
            largest = r;
        if (largest != i){
            swap(nums[i],nums[largest]);
            heapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>&nums, int n)
    {
        while(n > 1)
        {
            swap(nums[0], nums[n-1]);
            n--;
            heapify(nums, n, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        //creation of max heap
        for (int i = (n-1)/2; i >= 0; i--)
            heapify(nums, n, i);
        //heap sort 
        heapSort(nums,n);
        return nums;
    }
};