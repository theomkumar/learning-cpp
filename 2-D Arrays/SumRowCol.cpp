#include<iostream>
using namespace std;

//
void sumRow(int arr[][4],int row,int column) {
    cout<<"sum of all elements in a row: ";
    for (int i = 0; i<row; i++) {
        int sum = 0;
        for(int j = 0; j<column; j++) {
            sum+=arr[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<"\n";
    
}

void sumColumn(int arr[][4],int row,int column) {
    cout<<"sum of all elements in a column: ";
    for (int i = 0; i<column; i++) {
        int sum = 0;
        for(int j = 0; j<row; j++) {
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
    }
    
}


int main() {
    // input & print
    int arr[3][4]= {1,2,3,4,5,6,7,8,9,10,11,12};
    
    for(int i=0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    sumRow(arr,3,4);
    sumColumn(arr,3,4);
    return 0;
}