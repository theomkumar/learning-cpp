https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int c = 0; c<mCols; c++) {
        //if column index is even
        // if (!(c&1))-not odd (c%2==0)==even or 0;
        if (c%2==0)
            for(int r = 0; r<nRows; r++) 
                ans.push_back(arr[r][c]);
        else {
            for (int r = nRows-1; r>=0; r--) 
                ans.push_back(arr[r][c]);
        }
    }
    return ans;
}