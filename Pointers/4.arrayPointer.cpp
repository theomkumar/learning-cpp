#include<iostream>

using namespace std;

int main() {
  //address of an array can't be re-assigned.
    //pointer address is 8 byte for 64bit(8byte * 8bit = 64) system.
    int temp[10];
    cout << sizeof(temp) << endl;
    int *ptr = temp;
    cout << "pointer:" << sizeof(ptr) << "element: " << sizeof(*ptr) <<'\n';
    cout << &temp << " " << (&ptr) << "\n"; 
    //these are different coz pointer is also
    //a variable with its own unique address. 
    
    int arr[10];
    
    //error
      //arr = arr+1/++arr; here we are trying to assign an adress(arr) to new address(arr+1);

    cout << "Before: "<< ptr <<" after: "<< ++ptr <<"\n";
   //here we are assigning new address to a variable;
    return 0;
}