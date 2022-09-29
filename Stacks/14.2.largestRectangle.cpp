#include<iostream>
#include<vector>
#include<stack>

using namespace std;
//when we find element smaller to our previous stack we calculate it's area, and we keep calculating area and popping larger element from stack until heights[i] is smaller than our stack elements.

//one pass debug and dry run it to understand the logic


    //i = 0,1,2,3,
    // eg 1,2,2,1,6
    //for calculating area from i = 0 to i = 1
    //LOGIC: area =  L * b; L = 2, b = (nextSmallerIndex - prevSmallerIndex - 1) 
                            //       = 3 - 0 - 1 = 2 
    
   int largestRectangleArea(vector<int> &height) {
    
    int maxArea = 0;
    height.push_back(0); //why? coz 0 will always be lesser than than previous non zero stack element so we can calculate area of all previous element w.r.t it.
    stack<int> index; //store index of previous smaller index
    
    for(int i = 0; i < height.size(); i++)
    {
        while(!index.empty() && height[index.top()] >= height[i])// only > is also correct, eg. 2,2,2,2,0 if >= then area will be calculated everytime we encounter 2 and popped as well, if > then area will be calculated at then,stack will be more full incase of only >   
        {
            int h = height[index.top()]; //we want to calculate area of this element
            index.pop(); //why? coz after popping we'll get our prev smaller index, and also coz we would've computed area for this index by the end of this loop!
            
            int prev = index.empty() ? -1 : index.top() ;//prev will store the index of previous smaller index
            int currArea = h * (i - prev - 1);
            maxArea = max(maxArea, currArea);
        }
        index.push(i);
    }
    return maxArea;
}


int main() 
{
    // vector<int> height = {2,1,5,6,2,3};
    vector<int> height = {2,1,5,6,2,2,2,3};
    cout << largestRectangleArea(height);
    return 0;
}