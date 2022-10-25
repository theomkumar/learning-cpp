#include<iostream>

using namespace std;

//gcd using '-' operator
/*(int gcd(int a,int b) {
    if (a==0) return b;
    if (b==0) return a;

    while(a!=b) {
        if (a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

// gcd using '%' operator with recursion
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
*/
// gcd using '%' operator without recursion
int gcd(int a, int b)
{
    //we are changing remainder into divisor & divisor into dividend and 
    //R = remainder ; a = dividend i.e > b = divisor
    int R;
    if (b > a)
        swap(a, b);
    while (a % b) {
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}

int main() {
    int a, b;
    cout << "enter the values of a and b" << "\n";
    cin >> a >> b;
    int ans = gcd(a, b);
    cout << "gcd of " << a << " " << b << " is : " << ans << "\n";

    //Lcm*hcf/gcd = a*b
    cout << "lcm of " << a << " " << b << " is : " << ((a * b) / ans) << "\n";
    return 0;
}