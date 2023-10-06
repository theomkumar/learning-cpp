//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
//O(n logk) O(k)
int kthSmallest(int arr[], int l, int r, int k) {
    // Check if k is within the bounds of the array
    if (k > r - l + 1) {
        cout << "Invalid input: k is greater than number of elements in array";
        return -1;
    }
    // Create a max heap (priority queue)
    priority_queue<int> pq;

    // Push first k elements into the max heap
    while(l < k)
        pq.push(arr[l++]);

    // For remaining elements, if element is smaller than top, add it to max heap
    while(l <= r) {
        if (arr[l] < pq.top()) {
            pq.pop();
            pq.push(arr[l]);
        }
        l++;
    }
    // Top element of max heap is kth smallest element
    return pq.top();
}