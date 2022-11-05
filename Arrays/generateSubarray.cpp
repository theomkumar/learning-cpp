#include<iostream>
using namespace std;

//time complexity: O(N^3)
int main() 
{
    int arr[5] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    //start position i
    for (int i = 0; i < n; i++)
    {
        //end position j
        for (int j = i; j < n; j++)
        {
            //print from i to j! 
            cout<<'(';
            for (int k = i; k <= j; k++)
                cout << arr[k] <<' ';
            cout <<')';
        }
        cout<<'\n';
    }
    return 0;
}