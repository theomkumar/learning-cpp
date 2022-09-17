https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    
    //element count
    int count = 0, total = row*col;
    
    // indices
    int startingRow = 0, startingCol = 0, endingRow = row-1, endingCol = col-1;
    
    while ( count<total )
    {
        //starting row
        for (int i = startingCol; count<total && i<=endingCol; i++,count++)
            ans.push_back( matrix[startingRow][i] );
        
        startingRow++;
        
        //ending column
        for (int i = startingRow; count<total && i<=endingRow; i++,count++ ) 
            ans.push_back( matrix[i][endingCol] );
        
        endingCol--;
        
        //ending row
        for (int i = endingCol; count<total && i>=startingCol; i--,count++ )
            ans.push_back( matrix[endingRow][i] );
        
        endingRow--;
        
        //starting column
        for (int i = endingRow; count<total && i>=startingRow; i--,count++ )
            ans.push_back( matrix[i][startingCol]);
        
        startingCol++;
        
    }
    return ans;
}
};