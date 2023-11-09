/*
## 1:: Tried without using bool function :: just to understand how recursive call were made, skipp this maybe!

class Solution {
public:
    bool sudokuSolved = false;

    bool isValid(vector<vector<char>> &board, int ch, int row, int col)
    {
        //row & col check
        for(int i = 0; i < board.size(); i++){
            //row
            if (board[row][i] == ch) return false;
            //col
            if (board[i][col] == ch) return false;
        }
        //grid check (3*3 grids)
        int gRow = row/3 * 3, gCol = col/3 * 3;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if (board[gRow+i][gCol+j] == ch)
                    return false;

        return true;
    }
    void solve(vector<vector<char>>&board)
    {
        if (sudokuSolved == true) return;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size();j++){
                if (board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if (isValid(board,c,i,j)){
                            board[i][j] = c;
                            solve(board);
                            if (sudokuSolved == true)
                                return;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return;
                }

            }
        }
        sudokuSolved = true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

### 2 : //STANDARD METHOD:::

class Solution {
public:

    bool isValid(vector<vector<char>> &board, int ch, int row, int col)
    {
        //row & col check
        for(int i = 0; i < board.size(); i++){
            //row
            if (board[row][i] == ch) return false;
            //col
            if (board[i][col] == ch) return false;
        }
        //grid check (3*3 grids)
        int gRow = row/3 * 3, gCol = col/3 * 3;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if (board[gRow+i][gCol+j] == ch)
                    return false;

        return true;
    }
    bool solve(vector<vector<char>>&board)
    {
        //iterate and try out all the possible values
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size();j++){
                if (board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if (isValid(board,c,i,j)){
                            board[i][j] = c;
                            if (solve(board)) return true;//no process is needed
                            board[i][j] = '.';//else backtrack
                        }
                    }
                    //even after trying all occurence,not solved
                    return false;
                }
            }
        }
        //if we reach here it means the sudoku has been solved!!! just exit from recursive call
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

### 3: modifying isValid little bit

*/
class Solution {
public:

    bool isValid(vector<vector<char>> &board, int ch, int row, int col)
    {
        //grid starting row & col 
        int gRow = row/3 * 3, gCol = col/3 * 3;

        //row & col check & grid check
        for(int i = 0; i < board.size(); i++){
            //row
            if (board[row][i] == ch) return false;
            //col
            if (board[i][col] == ch) return false;
            //grid
            if (board[gRow+i/3][gCol+i%3] == ch) return false;
        }
        /*
        //grid check (3*3 grids)
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if (board[gRow+i][gCol+j] == ch)
                    return false;

        */
        return true;
    }
    bool solve(vector<vector<char>>&board)
    {
        //iterate and try out all the possible values
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size();j++){
                if (board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if (isValid(board,c,i,j)){
                            board[i][j] = c;
                            if (solve(board)) return true;//no process is needed
                            board[i][j] = '.';//else backtrack
                        }
                    }
                    //even after trying all occurence,not solved
                    return false;
                }
            }
        }
        //if we reach here it means the sudoku has been solved!!! just exit from recursive call
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};