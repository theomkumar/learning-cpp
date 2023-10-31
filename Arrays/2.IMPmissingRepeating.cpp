/*
//brute force solution: TC: nlogn SC: O(1)
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();
    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if (a[j] == i) count++;
        }
        if (count == 0) missing = i;
        else if (count == 2) repeating = i;
        if (missing != -1 && repeating != -1)
            break;
    }
    return { repeating, missing };
}
//BETTER solution: TC: O(2N) SC: O(n)
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();
    int repeating = -1, missing = -1;
    int arr[n+1] = {0    vector<int> findArray(vector<int>& p) {
        int xorSum = p[0];
        for(int i = 1; i < p.size(); i++){
            p[i] = p[i]^xorSum;
            xorSum ^= p[i];
        }
        return p;
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] == 0)
            missing = i;
        else if (arr[i] == 2)
            repeating = i;
        if (repeating != -1 && missing != -1)
            break;
    }
    return { repeating, missing };
}

//optimal solution 1: TC: O(N) SC: O(1)
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long n = a.size(); //why? long n? coz we are multiplying it with other long value
    //sum of N natural no & sum of square of N natural no
    long sumN = (n*(n+1))/2, sumSqN = (n*(n+1)*(2*n+1))/6;
    //sum of array element & sum of square of array elements
    long sumA = 0, sumSqA = 0;

    for(auto i:a){
        sumA += i;
        sumSqA += i*i;
    }
    //missing - remaining - equation 1
    int mMinusR = sumN-sumA;
    //missing + remaining - equation 2
    int mPlusR = (sumSqN-sumSqA)/mMinusR;
    //using 2 equation to find 2 variables!!
    int m = (mMinusR+mPlusR)/2;
    int r = mPlusR-m;
    return {r, m};
}
*/
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size();
    //xor all a elements & 1-N
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr ^= a[i];
        xr ^= (i+1);
    }
    //xr == missing ^ repeating
    //find first differentiating bit
    int count = 0;
    while(true){
        if ((xr & (1<<count)) != 0)
            break;
        count++;
    }
    int diffBit = 1<<count;
//  int diffBit = (xr & ~(xr-1));
    int xorOne = 0, xorZero = 0;
    for (int i = 0; i < n; i++){
        //a[] elements
        if(((a[i]&diffBit))!= 0){
            xorOne ^= a[i];
        } else {
            xorZero ^= a[i];
        }
        // 1-N elements
        if (((i + 1) & diffBit) != 0)
            xorOne ^= (i + 1);
        else
            xorZero ^= (i + 1);
    }
    // xorOne and xorZero contains missing & repeating
    int count1 = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == xorOne)
            count1++;     
    }
    if (count1 == 2)
        return {xorOne,xorZero};
    else
        return {xorZero,xorOne};
}