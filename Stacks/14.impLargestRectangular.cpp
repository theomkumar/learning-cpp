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

//Approach 2: using map