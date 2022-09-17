void reverse(vector<int> &v) {
    
    int s = 0;
    int e = v.size()-1;
    
    while(s<e)
    {
        swap(v[s++], v[e--]);
    }
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
    int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;
    
    while(i>=0 && j>=0) {            
        int sum = a[i--] + b[j--] + carry;   
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    
    // first case
    while(i>=0) {
        int sum = a[i--] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);      
    }
    
     // second case
    while(j>=0) {
        int sum = b[j--] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    
     // 3rd case
    if (carry != 0) {
        ans.push_back(carry);
    }
    reverse(ans);
    return ans;
}