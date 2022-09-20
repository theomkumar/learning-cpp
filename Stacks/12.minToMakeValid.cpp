//https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=1
#include <bits/stdc++.h> 
using namespace std;


// APPROACH 1 : my brute force method by observation and dry run
int findMinimumCost(string str) {
    if (str.size() % 2)    return -1;
 
    stack<char> st;

    int invalid = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
            st.push(str[i]);
        
        else if (!st.empty())
            st.pop();
        
        else
            invalid++;
    }
    // eg -> }}}} if invalid is even we need invalid/2 operation ({{ -> we need one operation to make it valid, while 
// for odd eg-> {{{ we need 1 operation for {{ and one more for } 
//same logic with st.size();
    
    invalid = invalid % 2 ? (invalid - 1)/2 + 1 : invalid / 2; 
    invalid += st.size() % 2 ? (st.size()-1)/2 + 1 : st.size() / 2;

    return invalid;

    /*
    if (invalid % 2 == 0)
        invalid /= 2;
    else
        invalid = (invalid - 1)/2 + 1;

    int ans = st.size();
    if (ans % 2 == 0)
        ans /= 2;
    else 
        ans = (ans-1)/2 + 1;
    
    ans += invalid;
    
    return ans;

    */
}