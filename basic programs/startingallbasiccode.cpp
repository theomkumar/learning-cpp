#include<iostream>
using namespace std;

int main() {

//Code of if a number is -ve,+ve excluding 0
/*
int a;
cin>>a;
    if (a>0) {
        cout<<"A is positive \n";
        }

    else{
        cout<<"A is negative \n";
    }
*/


  //Code of which number is greater
/*
    int a,b;

    cout<<"Enter the value of a \n";
    cin>> a;

    cout<< "Enter the value of b \n";
    cin>> b;

 if (a>b) {
    cout<<" A is greater than B \n";
 }
 if (b>a) {
     cout<<"B is greater than A \n";
}
 if (b==a) {
    cout<<"Both A and B are equal \n";
 }

    int a=2;
    int b=a+1;
    if (a=3==b)
    cout<<"yes \n";
    else cout<<"no \n";
}
*/

   //Code of if a number a is +ve, -ve or 0
/*
   int a ;
   cout<<"Enter the value of A \n";
   cin>> a;

   if (a>0) {
    cout<<"A is Positve \n";
   }
   else if (a<0) {
        cout<<"A is negative \n";
        }
   else {
            cout<<"A is Zero \n";
        }
*/

  //Code of if a character is uppercase( 65-90) , lower case ( 97-122), numeric 48-57

    //first using ASCII values
/*
   char ch;
   cout<<"Enter desired character \n";
   cin>>ch;

   if ((ch>=97) && (ch<=122)) {
    cout<<"This is lowercase \n";
   }
   else if (ch>=65 && (ch<=90)){
    cout<<"This is uppercase \n";
    }
   else if ((ch<=57) && (ch>=48)) {
        cout<<"This is numeric \n";
    }
    else {
        cout<<"wrong input \n";
    }
*/
    //Second try without using ASCII values
 /*
    if ((ch>='a') && (ch<='z')) {
    cout<<"This is lowercase \n";
   }
   else if (ch>='A' && (ch<='Z')){
    cout<<"This is uppercase \n";
    }
   else if ((ch<='9') && (ch>='0')) {
        cout<<"This is numeric \n";
    }
    else {
        cout<<"wrong input \n";
    }
*/
 //Code of print 1 to N
 /*
 int n;
 cout<< "Print number from 1 to N \n"<<"Enter the value of N \n";
 cin>>n;
 int i=1;
 while (i<=n) {
   cout<<i<<" ";
   i=i+1;
}
*/
//sum 1 to n
/*
int n;
 cout<< "Sum 1 to N \n"<<"Enter the value of N : ";
 cin>>n;
int s=0;
int i=1;
while (i<=n) {
        s=i+s;
        i=i+1;
}
cout<<"value of sum is "<<s<<endl;
 }
*/

//sum of all even no. upto n
/*
int n;
 cout<< "Calculate sum of all even number upto N \n"<<"Enter the value of N : ";
 cin>>n;
int s=0;
int i=2;
while (i<=n) {
        s=i+s;
        i=i+2;
}
cout<<"sum is "<<s<<endl;
*/
//second way using modulus function
/*
int n;
 cout<< "Calculate sum of all even number upto N \n"<<"Enter the value of N : ";
 cin>>n;
int s=0;
int i=2;
while (i<=n) {
        if(i%2==0){
            s=i+s;
        }

          i=i+1;
    }
    cout<<s<<endl;
}
*/







//number N prime or not
/*
int n;
cin>>n;
int i=2;
while (i<n) {
    if (n%i==0) {
    cout<<"Not Prime for \n"<<i<<endl;
    }
    else {
        cout<<"Prime for \n"<<i<<endl;
    }
  i=i+1;
            }
*/
//pattern 1 X by X
/*
int n;
cin>>n;

int i=1;
while(i<=n) {
    int j=1;
    while (j<=n){
        cout<<"*";
        j=j+1;
    }
    cout<<endl;
    i=i+1;
 }
 */
 //pattern 2
 /*
 int n;
 cin>>n;
 int i=1;
 while (i<=n) {
    int j=1;
    while (j<=n) {
        cout<<i;
        j=j+1;
    }
    cout<<endl;
    i=i+1;
 }
*/

//Fahrenheit to Celsius c=(5.0/9)*(f-32)
/*
float f;
cout<<"Enter Temperature in Fahrenheit to convert into Celsius :";
cin>>f;
float c=(5.0/9)*(f-32);
cout<<f<<" F = "<<c<<" C \n";
*/