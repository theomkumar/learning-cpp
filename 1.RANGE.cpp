// C++ code to demonstrate the macros for data types
#include<iostream>
#include<limits.h> // for int,char macros
#include<float.h> // for float,double macros
#include<math.h>
using namespace std;

string toExponent(unsigned long long a)
{
    string exponent = " ";

    unsigned long long A = a;
    int power = 0;
    //count power
    while (A)
    {
        if (A/10) power++;
        A /= 10;
    }
    //precision upto 2 places
    float d = a/pow(10, power);
    d = (int)(d*100); //if we want to round off upto 2 place = (int)(d*100 + 0.5);
    d /= 100;
    string temp = to_string(d);

    //remove 0s after decimal
    while (temp.back() == '0') temp.pop_back();

    exponent += temp;
    exponent += " * ";
    exponent += "10^";
    exponent += (to_string(power));
    return exponent;
}


int main()
{
  
// Displaying ranges with the help of macros
cout << "char ranges : " << CHAR_MIN << " to " << CHAR_MAX;
cout << "\n\nshort char  : " << SCHAR_MIN << " to " << SCHAR_MAX;
cout << "\n\nunsigned char  : " << 0 << " to " << UCHAR_MAX;
  
cout << "\n\n\nshort int  : " << SHRT_MIN << " to " << SHRT_MAX;
cout << "\n\nunsigned short int  : " << 0 << " to " << USHRT_MAX;
cout << "\n\nint  : " << INT_MIN << " to " << INT_MAX <<" -> " <<" to " <<toExponent(INT_MAX);
cout << "\n\nunsigned int  : " << 0 << " to " << UINT_MAX <<" -> " <<toExponent(UINT_MAX);
cout << "\n\nlong int  : " << LONG_MIN << " to " << LONG_MAX<<" -> " <<toExponent(LONG_MAX);
cout << "\n\nunsigned long int  : " << 0 << " to " << ULONG_MAX<<" -> " <<toExponent(ULONG_MAX);
cout << "\n\nlong long int  : " << LLONG_MIN << " to " << LLONG_MAX<<" -> " <<toExponent(LLONG_MAX);
cout << "\n\nunsigned long long int  : " << 0 << " to " << ULLONG_MAX<<" -> " <<toExponent(ULLONG_MAX);
  
cout << "\n\n\n\nfloat  : " << FLT_MIN << " to " << FLT_MAX;
cout << "\n\nnegative float  : " << -FLT_MIN << " to " << -FLT_MAX;
cout << "\n\ndouble  : " << DBL_MIN << " to " << DBL_MAX;
cout << "\n\nnegative double  : " << -DBL_MIN << " to " << +DBL_MAX;
  
return 0;
  
}