#include<iostream>
#include<climits>
using namespace std;
// return index of row with largest row sum;

void sumRow(int arr[][4],int row,int column) {
    cout<<"sum of all elements in a row: ";
    int ansIndex = 0;
    int maxi = INT_MIN;

    for (int i = 0; i<row; i++) {
        int sum = 0;
        for(int j = 0; j<column; j++) {
            sum+=arr[i][j];
        }
        cout<<sum<<" ";
        if (sum>maxi) {
            maxi = sum;
            ansIndex = i;
        }
    }

    cout<<"\n";
    cout<<"largest row sum index is: "<<ansIndex;
    
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
    
    return 0;
}