#include<iostream>

using namespace std;

int main() {
    //points to remember 


    // when int *p = 0, then we have to initialise it  like this:
    // p = &i . correct
    // *p = i. wrong , segmentation error coz such memory address doesn't exist.
/*
    int arr[6] = { 11, 12 , 31};
    int *p = arr;
    cout<< p[2]<<endl; 
    //p[2] == *(p+2);  


    int arr[] = { 11,21, 31, 41};
    int *ptr = arr++; 
    //(&anything)++ isnt possible
    //arr == (&arr[0])
    //arr++ => arr = arr+1; which is not possible as memory address of an array can't be changed
    // coz address of symbol table is fixed for a hardware 
    cout<<*ptr<<endl;


    char arr[] = " abcde";
    char *p = &arr[0];
    cout<< p << endl;
 // this prints the whole array not the address of arr[0] coz
 // the implementation of cout in char array is different.

    char arr[] = "abcde";
    char *p = &arr[0];
    p++; // increment address by 1 byte(in case of int 4 byte) i.e from arr[0]-> arr[1].
    cout<<p<<endl; // print from arr[1] to null character.
  
    char str[]= "abcde";
    char *p = str;
    cout<< str[0] << " "<< p[0] << " "<< p[1] << endl;
    //this doesn't print the whole array.

 
//***double pointer
     int first = 110;
     int *p = &first;
     int **q = &p;
     int second = (**q)++ + 9; // note post increment;
     cout << first << " " << second <<  endl;

    int first = 100;
    int *p =  &first;
    int **q = &p;
    int second = ++(**q);
    int *r = *q;
    ++(*r);
    cout<<first<<" "<<second<< "\n";
*/


    return 0;
}