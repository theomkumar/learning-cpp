#include <bits/stdc++.h> 
using namespace std;

//brute force: O(N*M + (N*M)log(N*M)) SC: O(N*M)
vector<int> mergeKSortedArrays(vector<vector<int>>&a, int k)
{
    // Write your code here. 
    vector<int> ans;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a[i].size();j++)
            ans.push_back(a[i][j]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
//using merge two sorted logic(BAD): TC: 

vector<int> merge(vector<int> &v1, vector<int> &v2){
    int i = 0,j = 0, n1 = v1.size(), n2 = v2.size(), IDX = 0;
    vector<int> ans(n1+n2);
    
    while(i < n1 && j < n2){
        if (v1[i] < v2[j])
            ans[IDX++] = v1[i++];
        else
            ans[IDX++] = v2[j++];
    }
    while(i < n1)
        ans[IDX++] = v1[i++];
    while(j < n2)
        ans[IDX++] = v2[j++];
    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> ans = arr[0];
    for(int i = 1; i < k; i++)
        ans = merge(ans, arr[i]);
    return ans;
}
//using merge sort logic: DIVIDE AND CONQUER

//APPROACH 1: MODIFYING WITHOUT ALTERING INPUT ARRAY::
#include <vector>

void merge(std::vector<int>& merged, const std::vector<int>& left, const std::vector<int>& right) {
    int i = 0, j = 0;
    const int n1 = left.size();
    const int n2 = right.size();

    int k = merged.size();  // Start merging from the end of the merged vector
    merged.resize(k + n1 + n2);

    while (i < n1 && j < n2) {
        if (left[i] < right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }

    while (i < n1)
        merged[k++] = left[i++];

    while (j < n2)
        merged[k++] = right[j++];
}

void mergeSort(const std::vector<std::vector<int>>& arrays, int start, int end, std::vector<int>& merged) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        std::vector<int> left;
        mergeSort(arrays, start, mid, left);

        std::vector<int> right;
        mergeSort(arrays, mid + 1, end, right);

        merge(merged, left, right);
    } else {
        merged = arrays[start];  // Copy the single array to the merged vector
    }
}

std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& arrays, int k) {
    if (k == 0) {
        return std::vector<int>();
    }

    std::vector<int> merged;
    mergeSort(arrays, 0, k - 1, merged);

    return merged;
}


//APPROACH 2::: DOING INPLACE:
void merge(vector<int>& left, vector<int>& right) {
    // Merge two sorted arrays (left and right) into a single sorted array.
    int i = 0, j = 0, n1 = left.size(), n2 = right.size();
    vector<int> merged(n1+n2);
    
    while (i < n1 && j < n2) {
        if (left[i] < right[j])
            merged.push_back(left[i++]);
        else
            merged.push_back(right[j++]);
    }

    while (i < n1)
        merged.push_back(left[i++]);

    while (j < n2)
        merged.push_back(right[j++]);

    left = merged; // Copy merged array back to the left vector
}

void mergeSort(vector<vector<int>>& arrays, int start, int end) {
    if (start == end) {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(arrays, start, mid);
    mergeSort(arrays, mid + 1, end);
    merge(arrays[start], arrays[mid + 1]); // Merge the two halves
}

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays, int k) {
    mergeSort(arrays, 0, k - 1);
    return arrays[0];
}
//why m+1??? 
    /*
    we’re dividing this larger array(2d) into two halves.(we are storing merged array in first part of the half), for 1st half:
    merged array will be stored in 'l' 
    for 2nd half : again we are storing in first part of this half, i.e m+1, here ‘r’ == end of the half, and ‘m+1’ would be the start of the second half of this larger array. That’s why we’re using arr[m+1], because we are storing the sorted array in (left-most part of the half).
    */


//USING HEAP:::

//OPTIMAL APPROACH 1(babbar):

#include <bits/stdc++.h> 
class node{
    public:
    int i, j , data;
    node(int row, int col, int d){
        i = row;
        j = col;
        data = d;
    }
};
class compare {
public:
    bool operator()(node* a, node* b) {
        return (a->data > b->data);
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> ans;
    ans.reserve(arr.size()*k);
    
    priority_queue<node*,vector<node*>,compare> minHeap;
    //step 1: push 1st element in minHeap
    for(int i = 0;i < arr.size(); i++)
    {
        node* temp = new node(i,0,arr[i][0]);
        minHeap.push(temp);
    }
    while(minHeap.size())
    {
        node* temp = minHeap.top();
        minHeap.pop();
        int i = temp->i, j = temp->j;
        ans.push_back(temp->data);
        //push next element
        if(j+1 < arr[i].size())
        {
            node* next = new node(i, j+1,arr[i][j+1]);
            minHeap.push(next);
        }
    }
    return ans;
}

