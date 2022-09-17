#include<iostream>
#include<vector>

using namespace std;
 
int main() {
    //input
    vector<vector<int>> matrix{{ 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
    
    cout<<"Input :- \n";
    for (int i = 0; i<matrix.size(); i++) {
        for (int j = 0; j<matrix[i].size(); j++) 
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }

    

    //processing 
    //cout<<"Processing:- \n";

    int n = matrix.size();
        vector<vector<int> >ans(matrix);
        int count = 0;
        //index of matrix;
        int startingRow = 0,startingCol = 0, endingRow = n-1, endingCol = n-1;
        //index of ans;
        int startRow = 0,startCol = 0, endRow = n-1, endCol = n-1;

        while (count<n) {
        //starting row = reversed starting column
            for (int i = startCol;i<=endCol; i++) {
                ans[startRow][i]= matrix[n-i-1][startingCol];

                //cout<<matrix[n-i-1][startingCol]<<" ";
            }

            startRow++; startingCol++;
            count++;
        }

    //output rotated image
    cout<<"Output:- \n";

    for(int i = 0; i<ans.size(); i++) {
        for (int j = 0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }cout<<"\n";
    }


    return 0;
}