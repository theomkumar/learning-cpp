class Solution {
    bool isSafe(int row,int col,vector<string>&board,int n){
        int x = row, y = col;
        //left
        while(y >= 0){
            if (board[x][y--] == 'Q')
                return false;
        }
        //diagonal top
        y = col;
        while(x >= 0 && y >= 0){
            if (board[x--][y--] == 'Q')
                return false;
        }
        x = row, y = col;
        //diagonal bottom
        while(x < n && y >= 0)
            if (board[x++][y--] == 'Q')
                return false;

        return true;
    }
public:
    void solve(int col,int n,vector<vector<string>>&ans,vector<string>&board){
        if (col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if (isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,n,ans,board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(0,n,ans,board);
        return ans;
    }
};