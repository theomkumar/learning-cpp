https://leetcode.com/problems/valid-palindrome

bool isPalindrome(string s) {
    int n = s.size();
    string ans;
    
    for(int i = 0; i<n; i++) {
        if (s[i]>='A' && s[i]<='Z') {
            int temp = s[i]-'A'+'a';
            ans.push_back(temp);
        }   
        else if (s[i]>='a' && s[i]<='z')
            ans.push_back(s[i]);
        else if (s[i]>='0' && s[i]<='9')
            ans.push_back(s[i]);
    }
    
    n = ans.size();
    
    for(int i = 0; i<n/2; i++) {
        if (ans[i]!=ans[n-i-1]) return false;
    }
    return true;
}