#include<iostream>
//if the value isn't provided by function call then using default arg,
// default value is used inside function.

//can't make any var default statement-> only from right to left in order 
using namespace std;

void print(int arr[], int n = 2, int start = 1) //here default arg for start is 1'st index 
// if n or start isn't 
{
    for (int i = start; i<n; i++) 
    {
        cout << arr[i] << " ";
    }

}
int main() {
    
    int arr[5] = {0,2,4,6,8};
    int size = 5;

    print (arr,size); //default value of start will be used
    cout<<endl;

    print (arr, size, 3);
    cout<<endl;

    print (arr); // default arg of size and start will be used
    cout<<endl;

    
    return 0;
}