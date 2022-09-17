//It is a syntax. In the function arguments int (&myArray)[100] parenthesis that enclose the &myArray are necessary. if you don't use them, you will be passing an array of references and that is because the subscript operator [] has higher precedence over the & operator.
//https://stackoverflow.com/questions/5724171/passing-an-array-by-reference
//E.g. int &myArray[100] // array of references i.e invalid
// int (&myArray)[100] parenthesis that enclose the &myArray are necessary.
#include<iostream>
using namespace std;

//Pass an array. Array decays to a pointer. Thus you lose size information.
void decayPointer(int *arr)
{
    cout << "size of arr(pointer size) " << sizeof(arr) << endl;
}

void reference (int (&arr)[12])
{
    cout << "size of arr(reference) " << sizeof(arr) << '\n';
    arr[12] = 100;
}

int main() 
{
    int arr[12];
    arr[12] = 22;

    decayPointer(arr);

    reference(arr);
    cout <<arr[12];
    
    return 0;
}

