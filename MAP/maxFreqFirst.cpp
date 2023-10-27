int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    int ans = 0, maxFreq = 0;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++){
        m[arr[i]]++;
        if (m[arr[i]] > maxFreq){
            maxFreq = m[arr[i]];
        }
    }
    for(int i = 0; i < n; i++){
        if (m[arr[i]] == maxFreq)
            return arr[i];
    }
    return -1;
}