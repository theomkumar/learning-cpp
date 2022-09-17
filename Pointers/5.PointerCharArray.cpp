#include<iostream>

using namespace std;

int main() {
    //implemetation of cout in char array is different 
    //from that of int array.

    int arr[5] = {1,2,3,4,5};
    char ch[7] = "omiboy";

    cout<<*ch<<endl; //prints first character.

    char ch2[7]= {'o','m','i','b','o','y','\0'};
    cout << "ch2: "<< ch2 <<endl;
    cout <<"ch2: " << ch2[2]<<endl;

    //prints address of 1st element ( &arr[0]).
    cout<<arr<<"\n";
    //prints entire content of ch till null character.
    cout<<ch<<"\n \n";

    char *c = &ch[0];
    
    //prints entire string until null character is found.
    cout << "print pointer c: " << c << '\n';

    cout << "value:" << *c <<'\n';

    cout << "test ch:" << &ch <<" "<< &ch[0] <<" "<< &ch[1] <<" "<< &ch[2] <<" " << &ch[3] << " "<< endl;

    cout << "test ch2: " << &ch2 <<" " << &ch2[0] <<" "<< &ch2[1] <<" "<< &ch2[2] <<" "<< &ch2[3] << " " << endl;
    
    cout << "test arr: " << &arr <<" "<< &arr[0] <<" "<< &arr[1] <<" "<< &arr[2] <<" "<< &arr[3] <<" "<< endl;

    //keeps printing until null character is found
    char temp = 'z'; //no null character,cout will keep printing  
                     //next memory block until it finds null character.

    char *p = &temp;
    cout << p << endl;
    
    cout << *(ch+4) <<'\n';
    
/*
    //here the content is copied from temp memory to memory block of test[];
    char test[6] = "abcde";
    
*/ 
    //very risky bad practice coz the address of temporary memory is stored in pointer
    char *t = "abcde";
    cout << t << endl;
    cout << &t << endl;
    
    return 0;
}