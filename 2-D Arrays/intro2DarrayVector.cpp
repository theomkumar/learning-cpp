#include<iostream>
#include<vector>
using namespace std;

int main() {

    // creating 2D array

    //int arr[3][4]= {1,2,3,4,5,6,7,8,9,10,11,12};//row wise
    int arr[3][4] ={ {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

    //Vector 2D

        //direct input
    vector<vector<int>> matrix{{ 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };

    // pushing vectors to create 2D array
    vector<vector<int> > ans;

    vector<int> temp{1,2,3,4};
    vector<int> temp2{5,6,7,8};

    ans.push_back(temp);
    ans.push_back(temp2);

    //printing 2D vector
    for (int i = 0; i<ans.size(); i++) { 
        for (int j = 0; j<ans[i].size(); j++) //ans[i]=size in i'th row
            cout<<ans[i][j]<<" ";
        cout<<"\n";

    }cout<<"\n";

    //removes last element from row index 0;
    matrix[0].pop_back();
    //removes all elements from last row;
    matrix.pop_back(); 


    /* 
    int arr[3][4];

    //taking input row wise
    
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }
    
    //taking input column wise
    for(int i = 0; i<4; i++) {
        for (int j = 0; j<3; j++) {
            cin>>arr[j][i];
        }
    }
    */

   
    //print 2D array
    for(int i=0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}