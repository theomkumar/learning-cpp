#include<bits/stdc++.h>
using namespace std;
//code studio then leetcode

##Leetcode
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/submissions/

// Approach 1: Brute force O(n^2)

vector<int> finalPrices(vector<int>& prices) {
    
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i+1; j < prices.size(); j++)
        {
            if (prices[j] <= prices[i])
            {
                prices[i] = prices[i] - prices[j];
                break;
            }
        }
            
    }
    return prices;
}

vector<int> finalPrices(vector<int>& prices) {
    stack<int> s; 
    s.push(0); //if that element is last or smallest then discount will be 0;
    
    for (int i = prices.size()-1; i >= 0; i--)
    {
        while (s.top() > prices[i])
            s.pop();  
        int temp = prices[i];
        prices[i] -= s.top();
        s.push(temp);
    }
    return prices;
}

//similar question but here we need to return -1 if not found
//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n-1; i >= 0; i--)
    {
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

