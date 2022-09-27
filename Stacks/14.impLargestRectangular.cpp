#include<vector>
using namespace std;

//Approach 1: BRUTEFORCE O(N^2);

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int prev, next;
    int max_area = -1;
    for (int i = 0; i < n; i++)
    {
        prev = next = i;
        while (prev >= 0 && heights[prev] >= heights[i])            
            prev--;
        while (next < n && heights[next] >= heights[i])            
            next++;
        int area = heights[i] * (next - prev - 1); //(l*b)
        max_area = max(max_area, area);
    }
    return max_area;
}

//Approach 2: using stack O(n
)
class Solution {
    void nextSmaller(vector<int>& h, int n, vector<int> &next)
    {
        stack<int> st;
        st.push(-1);
        
        for (int i = n-1; i >= 0; i--)
        {
            while (st.top() != -1 && h[st.top()] >= h[i])
                st.pop();
            
            if (st.top() == -1)
                next[i] = n;
            
            else
                next[i] = st.top();
            
            st.push(i);
        }
        clear(stack)
    }
    void prevSmaller(vector<int>& h, int n, vector<int> &prev)
    {
        stack<int> st;
        st.push(-1);
        
        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && h[st.top()] >= h[i])
                st.pop();
            
            prev[i] = st.top();
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        
        vector<int> next(n);
        nextSmaller(h, n, next);
        
        vector<int> prev(n);
        prevSmaller(h, n, prev);
        
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, h[i] * (next[i] - prev[i] - 1));
        }
        return maxArea;
    }
};