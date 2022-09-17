// https://leetcode.com/contest/weekly-contest-306/problems/largest-local-values-in-a-matrix/

// 1/n check for more optimized ones
class Solution {
public:
    int maxi (vector<vector<int>> &grid, int i, int j)
    {
        int maxi = 0;
        int row = i+3;
        int col = j+3;
        for (int a = i; a < row; a++ )
        {
            for (int b = j; b < col; b++)
            {
                maxi = max(maxi, grid[a][b]);
            }
        }
        return maxi;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        vector<vector<int>> maxLocal;
        vector<int> temp;
        
        int n1 = grid.size();
        int n2 = n1 - 2;
        
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                temp.push_back( maxi(grid, i, j));
            }
            maxLocal.push_back(temp);
            temp.clear();
        }
        return maxLocal;
    }
};