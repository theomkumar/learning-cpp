#include<iostream>

using namespace std;

//good read with 2 initialising methods
//https://www.geeksforgeeks.org/how-to-declare-a-2d-array-dynamically-in-c-using-new-operator/
// https://www.geeksforgeeks.org/creating-array-of-pointers-in-cpp/

int main() {
    
 //  Method 2: using an array of pointer: Here an array of pointers
    //is created and then to each memory block

// Dynamic 2D Array of Pointers in C++: A dynamic array of pointers is basically an array of 
//pointers where every array index points to a memory block. This represents a 2D view in our mind. But logically it is a continuous memory block.


    //runtime input -> 2D Array create.
    
    int row,col;
    cin >> row >> col;

    //creating 2D array

    //declaring memory block of size row i.e an array of pointer   
    int** arr = new int*[row];

    //declaring memory block of size col
    for (int  i = 0; i<row; i++) {
        arr[i] = new int[col];
    }

    //taking input
    for(int i=0; i<row ; i++) {
        for (int j = 0; j<col; j++) {
            cin>>arr[i][j]; //*(*(arr+i)+j)
        }
    }
    //taking output
    cout<<"\n";

    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            cout<<*(*(arr+i)+j) /*arr[i][j] */<<" "; // *(*(arr+i)+j) == arr[i][j];
        }cout<<endl;
    }cout<<"\n";

    //playing
    cout<<arr[2][2]<<" "<<*(arr+2)+2<< " " <<&arr[2][2] <<" "<<&(*(*(arr+2)+2))<<"\n";

    //releasing memory

    for (int i = 0; i<row; i++) {
        delete[] arr[i];
    }
    delete[] arr;


    return 0;
}