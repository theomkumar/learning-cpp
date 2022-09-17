#include<iostream>
#include<vector>
using namespace std;

/*You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 
at least once. There is a single integer value that is present in the array twice.
 Your task is to find the duplicate integer value present in the array.*/
 int findDuplicate(vector<int> &arr) 
{
    int s=0;
    for (int i=0; i<arr.size(); i++) {
        s=s^arr[i];
        //we are xor ing whole array thus the dublicate ones will be removed (only unique elements left)
        // therefore s = 1^3^4^5
    }
    for (int i=1; i<arr.size(); i++) {
        s=s^i;
        //now we'll xor 1,2,3,4,5 with s= 1^3^4^5
        // thus s = 2 ;
    }
    return s;
    
	
}

int main() {
    vector<int> arr= { 1,2,3,2,4,5};
    cout<<findDuplicate(arr);
}