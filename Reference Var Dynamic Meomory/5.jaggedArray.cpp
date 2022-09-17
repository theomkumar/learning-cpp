#include<iostream>
#include<vector>

//incomplete

using namespace std;

int main() {
    int row; cout<<"row:"; cin>>row;
    //array of pointers.
    int **arr = new int* [row];
    
    vector<int> count;

    //allocating memory block for col.
    for (int i = 0; i<row; i++) {
        int col; cout<<"col len:"; cin>>col;

        count.push_back(col);
        
        for (int j = 0; j<col; j++) {
            arr[i] = new int[col];
        }
    }

    //input values

    for (int i = 0; i<row; i++) {
        
        cout<<"input value:";
        
        for (int j = 0; j<count[i]; j++) {
            
            cin>>arr[i][j];
        }
    }cout<<"\n";
    //output value
    for (int i = 0; i<row; i++) {
        
        for (int j = 0; j<count[i]; j++) {
            
            cout<<arr[i][j]<<" ";
        } cout<<"\n";
    
    } cout<<"\n";
    
    return 0;
}