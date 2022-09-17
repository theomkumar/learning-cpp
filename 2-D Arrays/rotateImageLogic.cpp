 void rotate(vector<vector<int>>& matrix) {
        
        //swapping top to bottom =  
        /*for (int col = 0; col < matrix.size(); ++col) {
            for (int row = 0; row < matrix.size()/2; ++row)
                swap( matrix[row][col], matrix[ matrix.size()-1-row ][col] );
        }
        */
        reverse(matrix.begin(), matrix.end()); 
        
        //swapping row to column and vice versa;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = row + 1; col < matrix[row].size(); ++col)
                swap(matrix[row][col], matrix[col][row]);
        }
        
    }

};