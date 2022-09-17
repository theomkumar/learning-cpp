#include<iostream>
#include<vector>
using namespace std;

// same as 1 , look at logic
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int> >ans(matrix);
    int count = 0;
    
    //index of matrix;
    int startingCol = 0;
    
    //index of ans;
    int startRow = 0;

    //starting row = reversed starting column
    while (count<n) {
        for (int i = 0;i<=n-1; i++) {
            ans[startRow][i]= matrix[n-i-1][startingCol];
        }
        startRow++; startingCol++; count++;
    }
    //if we only do matrix=ans, it'll work as well.
    matrix.clear();
    matrix=ans;
    ans.clear();
}

int main() {
    //input
    vector<vector<int>> matrix{{ 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
    //printing input
    cout<<"Input :- \n";
    for (int i = 0; i<matrix.size(); i++) {
        for (int j = 0; j<matrix[i].size(); j++) 
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }

    //processing 
    rotate(matrix);
    
    //printing output i.e- rotated image.
    cout<<"Output:- \n";
    for(int i = 0; i<matrix.size(); i++) {
        for (int j = 0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}