#include <iostream>
using namespace std;
bool isEven() {
    int a;
    cin>>a;
    if (a&1 ) return 0;
    return 1;
}
int main() {
    bool ans =isEven();
    if(ans) cout<<"The number is Even \n";
    else cout<<"The number is odd";

    ans =isEven();
    if(ans) cout<<"The number is Even \n";
    else cout<<"The number is odd";

    ans =isEven();
    if(ans) cout<<"The number is Even \n";
    else cout<<"The number is odd";

    
    
}