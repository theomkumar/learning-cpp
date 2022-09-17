#include<iostream>
#include<math.h>
using namespace std;
/*
int count (long long &b)
{
    return (log10(b) + 1);
}
*/
long long minValue(int &a, long long &b)
{
    if (a == 1)
        return b;

    long long min = pow(10, a-1);
    
    if (min % b == 0)
        return min;
    else 
        return min - (min % b) + b;
}
int main() 
{
    int a = 2;
    long long b = 2;
    long long ans = minValue(a, b);
    cout << " ans: " << ans;
    return 0;
}