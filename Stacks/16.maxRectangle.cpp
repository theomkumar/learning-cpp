#include<bits/stdc++.h>
using namespace std;

#APPROACH 1: Using largest area in rectangle/histogram approach
class Solution {
    int histogramArea (vector<int> &h, int n)
    {
        vector<int> prev(n);
        stack<int> st;
        st.push(-1);
        
        //find prev smaller index
        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && h[st.top()] >= h[i])
                st.pop();
            prev[i] = st.top();
            st.push(i);
        }
        //find next smaller index
        vector<int> next(n); 
        stack<int> s;
        s.push(-1);
        
        for (int i = n-1; i >= 0; i--)
        {
            while (s.top() != -1 && h[s.top()] >= h[i])
                s.pop();
            if (s.top() == -1)
                next[i] = n;
            else
                next[i] = s.top();
            s.push(i);
        }
        //calculate
        int maxArea = 0;
        for (int i = 0; i < n; i++)
            maxArea = max(maxArea, h[i] * (next[i] - prev[i] - 1));
        
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();//col len
        int n = matrix[0].size();//row len
        
        vector<int> histogram(n,0);
        int maxArea = 0; 
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)     
            {
                if (matrix[i][j] == '0')
                    histogram[j] = 0;
                else
                    histogram[j]++;
            }
            maxArea = max(maxArea, histogramArea(histogram, n));
        }
        return maxArea;
    }
};