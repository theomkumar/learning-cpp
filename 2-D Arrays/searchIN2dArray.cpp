#include<iostream>
using namespace std;

bool isFound(int arr[][4],int row, int column, int target) {
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<column; j++)
            if (arr[i][j]==target) 
                return 1;
    }
    return 0;

}


int main() {
/*
    int row,column;
    cout<<" enter row: ";
    cin>>row;
    cout<<"\n enter column: ";
    cin>>column;

    int arr[row][column];
    
    cout<<"enter elements row wise: ";
    for (int r = 0; r<row; r++) {
        for (int c = 0; c<column; c++) {
            cin>>arr[r][c];
        }
    }
*/
    int arr[3][4]= {1,2,3,4,5,6,7,8,9,10,11,12};
    // print
    for(int i=0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"enter target: ";
    cin>>target;

    if ( isFound(arr,3,4,target) ) {
        cout<<"target found! \n";
    }
    else cout<<"not found! \n";
}